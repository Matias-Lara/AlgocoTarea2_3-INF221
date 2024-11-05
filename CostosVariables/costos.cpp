#include "costos.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

// Definimos un alias para una matriz de 26x26
using MatrizCosto = vector<vector<int>>;

// Variables globales para almacenar los costos
vector<int> fila_inser(26);                  // Tabla de costo de inserción
vector<int> fila_elim(26);                   // Tabla de costo de eliminación
MatrizCosto matriz_sub(26, vector<int>(26));   // Matriz de costo de sustitución
MatrizCosto matriz_trans(26, vector<int>(26)); // Matriz de costo de transposición

// Flag para verificar si las tablas ya han sido cargadas
bool tablas_cargadas = false;

// Función para cargar las tablas desde los archivos
void cargarTablas() {
    if (tablas_cargadas) return; // Si ya están cargadas, no hacer nada

    // Cargar tabla de inserción
    ifstream ins_file("CostosVariables/costo_ins.txt");
    for (int i = 0; i < 26; ++i) ins_file >> fila_inser[i];
    ins_file.close();

    // Cargar tabla de eliminación
    ifstream elim_file("CostosVariables/costo_elim.txt");
    for (int i = 0; i < 26; ++i) elim_file >> fila_elim[i];
    elim_file.close();

    // Cargar matriz de sustitución
    ifstream sub_file("CostosVariables/costo_sub.txt");
    for (int i = 0; i < 26; ++i)
        for (int j = 0; j < 26; ++j)
            sub_file >> matriz_sub[i][j];
    sub_file.close();

    // Cargar matriz de transposición
    ifstream trans_file("CostosVariables/costo_trans.txt");
    for (int i = 0; i < 26; ++i)
        for (int j = 0; j < 26; ++j)
            trans_file >> matriz_trans[i][j];
    trans_file.close();

    tablas_cargadas = true; // Marcar las tablas como cargadas
}

// Función de costo de sustitución entre dos caracteres
int cost_sub(char a, char b) {
    cargarTablas(); // Asegurar que las tablas están cargadas
    int i = a - 'a';
    int j = b - 'a';
    return matriz_sub[i][j];
}

// Función de costo de inserción de un carácter
int cost_ins(char b) {
    cargarTablas(); // Asegurar que las tablas están cargadas
    int j = b - 'a';
    return fila_inser[j];
}

// Función de costo de eliminación de un carácter
int cost_del(char a) {
    cargarTablas(); // Asegurar que las tablas están cargadas
    int i = a - 'a';
    return fila_elim[i];
}

// Función de costo de transposición entre dos caracteres
int cost_trans(char a, char b) {
    cargarTablas(); // Asegurar que las tablas están cargadas
    int i = a - 'a';
    int j = b - 'a';
    return matriz_trans[i][j];
}