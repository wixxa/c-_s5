#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <string>
using namespace std;

int main() {
    string seq;
    ifstream rnaFile("../rosalind_prot.txt");
    if (!rnaFile.is_open()) {
        cerr << "Nie można otworzyć pliku rna_sequence.txt" << endl;
        return 1;
    }

    getline(rnaFile, seq);
    rnaFile.close();

    // Wczytanie tabeli kodonów
    ifstream codonFile("../codon_table.txt");
    if (!codonFile.is_open()) {
        cerr << "Nie można otworzyć pliku codon_table.txt" << endl;
        return 1;
    }

    vector<string> codons;        
    vector<string> aminoAcids;    
    string line;

    while (getline(codonFile, line)) {
        stringstream ss(line);
        string codon, aminoAcid;
        while (ss >> codon >> aminoAcid) {
            codons.push_back(codon);
            aminoAcids.push_back(aminoAcid);
        }
    }
    codonFile.close();

    // Translacja RNA na białko
    cout << "Tłumaczenie sekwencji RNA na białko:" << endl;
    string protein = "";
    bool stopCodonReached = false;

    for (size_t i = 0; i < seq.length() - 2; i += 3) {
        string codon = seq.substr(i, 3); 
        bool found = false;

        for (size_t j = 0; j < codons.size(); ++j) {
            if (codons[j] == codon) {
                found = true;
                if (aminoAcids[j] == "Stop") {
                    stopCodonReached = true;
                    break;
                }
                protein += aminoAcids[j];
                break;
            }
        }

        if (stopCodonReached) {
            break;
        }

        if (!found) {
            cout << "Nieznany kodon: " << codon << endl;
        }
    }

    if (!stopCodonReached) {
        cout << "Nie napotkano kodonu stop." << endl;
    }

    cout << "Zsekwencjonowane białko: " << protein << endl;

    return 0;
}