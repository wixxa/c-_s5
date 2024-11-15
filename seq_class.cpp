#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class Sequence {
    string sequence;  // DNA sequence

public:
    void readFromFasta(const string& path) {
        ifstream file(path);
        if (!file) {
            cout << "Cannot open file: " << path << endl;
            return;
        }
        string line;
        while (getline(file, line)) {
            if (line[0] != '>') sequence += line;  // Skip header
        }
    }

    void printSequence() {
        cout << "Sequence: " << sequence << endl;
    }
};

int main() {
    Sequence seq;
    seq.readFromFasta("/Users/wiktoria/Desktop/studia/c++/3. rok/example.fasta");
    seq.printSequence();
    return 0;
}
