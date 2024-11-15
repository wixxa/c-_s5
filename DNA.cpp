#include <iostream>
#include <string>
using namespace std;

int main(){
    string seq;
    cout << "Wprowadź sekwencje: " << endl;
    cin >> seq;
    int A = 0;
    int C = 0;
    int G = 0;
    int T = 0;
    int len_seq = seq.length();
    for (int i = 0; i <= len_seq; i++){
        if (seq[i] == 'A'){
            A++;
        }
        else if (seq[i] == 'C'){
            C++;
        }
        else if (seq[i] == 'G'){
            G++;
        }
        else if (seq[i] == 'T'){
            T++;
        }
    }
    cout << A << " " << C << " " << G << " " << T << endl;



}