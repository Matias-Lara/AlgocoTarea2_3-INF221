#include <iostream>
#include <string>
#include <algorithm>
#include <climits>
using namespace std;
#include "../CostosVariables/costos.h"


int edit_distance_BF_aux(const string& s1, const string& s2, int i, int j) {
    if (i == 0) {
        int costo = 0;
        for (int k = 0; k < j; k++) {
            costo += cost_ins(s2[k]);
        }
        return costo;
    }
    if (j == 0) {
        int costo = 0;
        for (int k = 0; k < i; k++) { 
            costo += cost_del(s1[k]);
        }
        return costo;
    }
    
    // Costo de sustituir los caracteres paralelos actuales
    int costo_sustitucion = cost_sub(s1[i - 1], s2[j - 1]) + edit_distance_BF_aux(s1, s2, i - 1, j - 1);
    
    // Costo de insertar el caracter j-1
    int costo_insercion = cost_ins(s2[j - 1]) + edit_distance_BF_aux(s1, s2, i, j - 1);

    // Costo de eliminar el caracter i-1
    int costo_eliminacion = cost_del(s1[i - 1]) + edit_distance_BF_aux(s1, s2, i - 1, j);

    // Costo de sustituir el caracter i-1 por el i-2
    int costo_transposicion = INT_MAX;
    if (i > 1 && j > 1 && s1[i - 1] == s2[j - 2] && s1[i - 2] == s2[j - 1]) { // Solo si los caracteres son adyacentes
        costo_transposicion = cost_trans(s1[i - 1], s1[i - 2]) + edit_distance_BF_aux(s1, s2, i - 2, j - 2);
    }

    // Retornar el minimo (mejor opcion)
    return min(
        {costo_sustitucion, 
        costo_insercion, 
        costo_eliminacion, 
        costo_transposicion
        });
}

// Función principal que oculta el uso de índices i y j
int edit_distance_BF(const string& s1, const string& s2) {
    return edit_distance_BF_aux(s1, s2, s1.size(), s2.size());
}
