#include <iostream>
#include <string>
using namespace std;

int main(){
    string seq;
    cout << "Wprowadź sekwencje: " << endl;
    cin >> seq;
    int len_seq = seq.length();
    for (int i = 0; i <= len_seq; i++){
        if (seq[i] == 'A'){
            seq.replace(i,1,"T");
        }
        else if (seq[i] == 'C'){
            seq.replace(i,1,"G");
        }
        else if (seq[i] == 'G'){
            seq.replace(i,1,"C");
        }
        else if (seq[i] == 'T'){
            seq.replace(i,1,"A");
        }
    }
    reverse(seq.begin(), seq.end());
    cout << seq << endl;



}