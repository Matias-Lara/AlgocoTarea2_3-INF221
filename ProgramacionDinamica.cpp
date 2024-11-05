#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <climits>
using namespace std;
#include "./CostosVariables/costos.h"

using Matriz = vector<vector<int>>;

// Función para calcular la distancia de Levenshtein con costos variables usando programación dinámica
int levenshtein_DP(const string& s1, const string& s2) {
    int n = s1.size();
    int m = s2.size();

    // Matriz para almacenar los costos
    Matriz dp(n + 1, vector<int>(m + 1, INT_MAX));

    // Inicialización de la matriz en el caso base
    dp[0][0] = 0;
    
    // Inicialización de los costos de inserción
    for (int j = 1; j <= m; ++j) {
        dp[0][j] = dp[0][j - 1] + cost_ins(s2[j - 1]);
    }

    // Inicialización de los costos de eliminación
    for (int i = 1; i <= n; ++i) {
        dp[i][0] = dp[i - 1][0] + cost_del(s1[i - 1]);
    }

    // Llenado de la matriz usando programación dinámica
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            // Caso de sustitución
            int costo_sustitucion = dp[i - 1][j - 1] + cost_sub(s1[i - 1], s2[j - 1]);

            // Caso de inserción
            int costo_insercion = dp[i][j - 1] + cost_ins(s2[j - 1]);

            // Caso de eliminación
            int costo_eliminacion = dp[i - 1][j] + cost_del(s1[i - 1]);

            // Caso de transposición
            int costo_transposicion = INT_MAX;
            if (i > 1 && j > 1 && s1[i - 1] == s2[j - 2] && s1[i - 2] == s2[j - 1]) {
                costo_transposicion = dp[i - 2][j - 2] + cost_trans(s1[i - 1], s1[i - 2]);
            }

            // Obtener el mínimo de los costos posibles para dp[i][j]
            dp[i][j] = min({costo_sustitucion, costo_insercion, costo_eliminacion, costo_transposicion});
        }
    }

    // El resultado final esta en el ultimo slot de la matriz
    return dp[n][m];
}

int main(){
    string s1, s2;
    cout << "String 1: ";
    cin >> s1;
    cout << "String 2: ";
    cin >> s2;
    int costo_MIN = levenshtein_DP(s1, s2);
    cout << costo_MIN << endl;
    return 0;
}