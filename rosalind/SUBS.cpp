#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
    string seq;
    string subseq;

    cout << "Wprowadź sekwencje: " << endl;
    cin >> seq;
    cout << "Wprowadź podsekwencje: " << endl;
    cin >> subseq;

    vector<int> positions;

    size_t pos = seq.find(subseq);
    while (pos != string::npos) {
        positions.push_back(pos + 1); 
        pos = seq.find(subseq, pos + 1); 
    }

    if (!positions.empty()) {
        cout << "Pozycje wystąpień podsekwencji: " << endl;
        for (int position : positions) {
            cout << position << " ";
        }
        cout << endl;
    } else {
        cout << "Podsekwencja nie została znaleziona.";
    }

    return 0;
}

//GATATATGCATATACTT
//ATAT