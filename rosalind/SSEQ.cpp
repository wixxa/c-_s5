#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <string>
using namespace std;

int main() {
    string dnaSeq;
    ifstream dnaFile("../rosalind_sseq.txt");
    string line;
    bool first_seq = true;
    int seq_num = 0;
    vector<size_t> positions;
    string sub_seq;

    if (!dnaFile.is_open()) {
        cerr << "Nie można otworzyć pliku." << endl;
        return 1;
    }

    while (getline(dnaFile, line)) {
        if(first_seq) {
            if (line[0] == '>'){
                seq_num += 1;
                if (seq_num > 1){
                    first_seq = false;
                }
                continue;
            }
        dnaSeq += line;
        }

        if (!first_seq) {
            if (line[0] == '>'){
                continue;
            }
            sub_seq += line;
            
        }
    }

    size_t current_pos =0;        
    int len_subseq = sub_seq.length();
    for (int i = 0; i < len_subseq; i++)
    {
        size_t pos = (dnaSeq.find(sub_seq[i], current_pos));
        if (pos != string::npos) {
            positions.push_back(pos + 1);
            current_pos = pos + 1;
        } else {
            cerr << "Błąd: symbol subsekwencji nie został znaleziony!" << endl;
            return 1;
        }
    }

    cout << "DNA: " << dnaSeq << endl;
    cout << "Subseq: " << sub_seq << endl;
    cout << "Indeksy: ";
    for (int index : positions) {
        cout << index << " ";
    }
    cout << endl;       
   

    return 0;
}
