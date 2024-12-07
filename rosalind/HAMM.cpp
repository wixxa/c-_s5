#include <iostream>
#include <string>
using namespace std;

int main(){
    string seq1;
    string seq2;
    cout << "Wprowadź sekwencje: " << endl;
    cin >> seq1;
    cin >> seq2;
    int len_seq = seq1.length();
    int h = 0;
    for (int i = 0; i <= len_seq; i++){
        if (seq1[i] != seq2[i]){
            h++;
        }
    }
    cout << "Mutations: " << h << endl;



}