#include <iostream>
#include <string>
#include <algorithm>
#include <climits>
using namespace std;
#include "./CostosVariables/costos.h"


int levenshtein_aux(const string& s1, const string& s2, int i, int j) {
    if (i == 0) {
        int costo = 0;
        for (int k = 0; k < j; ++k) costo += cost_ins(s2[k]);
        return costo;
    }
    if (j == 0) {
        int costo = 0;
        for (int k = 0; k < i; ++k) costo += cost_del(s1[k]);
        return costo;
    }

    int costo_sustitucion = (s1[i - 1] == s2[j - 1]) ? levenshtein_aux(s1, s2, i - 1, j - 1)
                                                     : cost_sub(s1[i - 1], s2[j - 1]) + levenshtein_aux(s1, s2, i - 1, j - 1);

    int costo_insercion = cost_ins(s2[j - 1]) + levenshtein_aux(s1, s2, i, j - 1);

    int costo_eliminacion = cost_del(s1[i - 1]) + levenshtein_aux(s1, s2, i - 1, j);

    int costo_transposicion = INT_MAX;
    if (i > 1 && j > 1 && s1[i - 1] == s2[j - 2] && s1[i - 2] == s2[j - 1]) {
        costo_transposicion = cost_trans(s1[i - 1], s1[i - 2]) + levenshtein_aux(s1, s2, i - 2, j - 2);
    }

    return min({costo_sustitucion, costo_insercion, costo_eliminacion, costo_transposicion});
}

// Función principal que oculta el uso de índices i y j
int levenshtein_costos(const string& s1, const string& s2) {
    return levenshtein_aux(s1, s2, s1.size(), s2.size());
}

int main(){
    string s1, s2;
    cout << "String 1:";
    cin >> s1;
    cout << "String 2:";
    cin >> s2;
    int costo_MIN = levenshtein_costos(s1, s2);
    cout << costo_MIN << endl;
    return 0;
}