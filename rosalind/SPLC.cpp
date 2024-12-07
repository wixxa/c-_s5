#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <string>
using namespace std;

int main() {
    string dnaSeq;
    ifstream dnaFile("../rosalind_splc.txt");
    string line;
    bool firstSeq = true;
    int seq_num = 0;
    string seq_dna;

    while (getline(dnaFile, line)) {
        if(firstSeq) {
            if (line[0] == '>'){
                seq_num += 1;
                if (seq_num > 1){
                    firstSeq = false;
                    seq_dna = dnaSeq;
                }
                continue;
                
            }
        dnaSeq += line;
        }
        
        
        if (!firstSeq) {
            string intron;
            if (line[0] == '>'){
                intron.clear();
                continue;
            }
            intron += line;
            size_t pos = dnaSeq.find(intron);
            while (pos != string::npos) {
                dnaSeq.erase(pos, intron.length()); // Usuń intron
                pos = dnaSeq.find(intron);         // Szukaj kolejnego wystąpienia intronu
            }
        }
        
    }
    cout << "Sekwencja DNA " << "długości " << seq_dna.length() << "nt:" << endl << seq_dna << endl;

    // Transkrypcja DNA na RNA 
    int len_seq = dnaSeq.length();
    for (int i = 0; i <= len_seq; i++){
        if (dnaSeq[i] == 'T'){
            dnaSeq.replace(i,1,"U");
        }
    }
    string seq_rna = dnaSeq;
    cout << "Sekwencja RNA " << "długości " << seq_rna.length() << "nt:" << endl << seq_rna << endl;


    // Wczytanie tabeli kodonów
    ifstream codonFile("../codon_table.txt");
    if (!codonFile.is_open()) {
        cerr << "Nie można otworzyć pliku codon_table.txt" << endl;
        return 1;
    }

    vector<string> codons;        // Wektor na kodony
    vector<string> aminoAcids;    // Wektor na aminokwasy
    while (getline(codonFile, line)) {
        stringstream ss(line);
        string codon, aminoAcid;
        while (ss >> codon >> aminoAcid) {
            codons.push_back(codon);
            aminoAcids.push_back(aminoAcid);
        }
    }
    codonFile.close();

    // Tłumaczenie RNA na białko
    string protein = "";
    bool stopCodonReached = false;

    for (size_t i = 0; i < seq_rna.length() - 2; i += 3) {
        string codon = seq_rna.substr(i, 3); 
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

    cout << "Białko " << "długości " << protein.length() << "aa :" << endl << protein << endl;


    return 0;
}
