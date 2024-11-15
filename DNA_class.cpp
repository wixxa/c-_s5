#include <iostream>
#include <string>
using namespace std;

class dna_analyzer {
    string dna_sequence;

public:
    dna_analyzer(const string& sequence) : dna_sequence(sequence) {}

    void count_nucleotides() {
        int A = 0, C = 0, G = 0, T = 0;

        for (char nucleotide : dna_sequence) {
            if (nucleotide == 'A') A++;
            else if (nucleotide == 'C') C++;
            else if (nucleotide == 'G') G++;
            else if (nucleotide == 'T') T++;
        }

        cout << "A: " << A << " C: " << C << " G: " << G << " T: " << T << endl;
    }
};

int main() {
    string seq;
    cout << "Wprowadź sekwencje: " << endl;
    cin >> seq;

    dna_analyzer analyzer(seq);
    analyzer.count_nucleotides();

    return 0;
}
