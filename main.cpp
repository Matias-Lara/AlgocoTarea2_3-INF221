#include <iostream>
#include <string>
#include "Algoritmos/bf.h"
#include "Algoritmos/dp.h"
using namespace std;


int main(){
    string s1, s2;

    cout << "String 1: ";
    cin >> s1;
    
    cout << "String 2: ";
    cin >> s2;

    int costo_bf = levenshtein_BF(s1, s2);

    int costo_dp = levenshtein_DP(s1, s2);

    cout << "Costo de edicion por BF: " << costo_bf << endl;
    cout << "Costo de edicion por DF: " << costo_dp << endl;
    
    return 0;
}