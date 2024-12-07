#include <iostream>
#include <string>
using namespace std;

int main(){
    string seq;
    cout << "Wprowadź sekwencje: " << endl;
    cin >> seq;
    int len_seq = seq.length();
    for (int i = 0; i <= len_seq; i++){
        if (seq[i] == 'T'){
            seq.replace(i,1,"U");
        }
    }
    cout << seq << endl;



}