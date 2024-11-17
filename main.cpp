#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <chrono>
#include <filesystem>

#include "Algoritmos/bf.h"
#include "Algoritmos/dp.h"

using namespace std;
using namespace std::chrono;

namespace fs = std::filesystem;

// Función para leer un CSV
vector<vector<string>> leerCSV(const string &ruta) {
    vector<vector<string>> data;
    ifstream archivo(ruta);
    string linea;
    while (getline(archivo, linea)) {
        stringstream ss(linea);
        string valor;
        vector<string> fila;
        while (getline(ss, valor, ',')) {
            fila.push_back(valor);
        }
        data.push_back(fila);
    }
    archivo.close();
    return data;
}

// Función principal
int main() {
    // Procesar DataSet_comun
    string ruta_dataset_comun = "DataSet_comun";
    string archivo_resultados_comun = "resultados/resultados_comun.csv";

    ofstream salida_comun(archivo_resultados_comun);
    salida_comun << "subdataset,tipo_dataset,tamanioS1,tamanioS2,costobf,costodp,tiempo_bf,tiempo_dp\n";

    int subdataset_id_comun = 1;
    for (const auto &entrada : fs::directory_iterator(ruta_dataset_comun)) {
        if (entrada.path().extension() == ".csv") {
            string tipo_dataset = entrada.path().stem().string();
            vector<vector<string>> dataset = leerCSV(entrada.path().string());

            for (size_t i = 1; i < dataset.size(); i++) {
                int tamanio_s1 = stoi(dataset[i][0]);
                int tamanio_s2 = stoi(dataset[i][1]);
                string s1 = dataset[i][2];
                string s2 = dataset[i][3];

                // BF
                auto start_bf = high_resolution_clock::now();
                int costo_bf = edit_distance_BF(s1, s2);
                auto end_bf = high_resolution_clock::now();
                float tiempo_bf = duration_cast<microseconds>(end_bf - start_bf).count() / 1000.0f;

                // DP
                auto start_dp = high_resolution_clock::now();
                int costo_dp = edit_distance_DP(s1, s2);
                auto end_dp = high_resolution_clock::now();
                float tiempo_dp = duration_cast<microseconds>(end_dp - start_dp).count() / 1000.0f;

                // Escribir resultados
                salida_comun << subdataset_id_comun << "," << tipo_dataset << ","
                             << tamanio_s1 << "," << tamanio_s2 << ","
                             << costo_bf << "," << costo_dp << ","
                             << fixed << tiempo_bf << "," << fixed << tiempo_dp << "\n";
            }
            subdataset_id_comun++;
        }
    }
    salida_comun.close();

    // Procesar DataSet_dp
    string ruta_dataset_dp = "DataSet_dp";
    string archivo_resultados_dp = "resultados/resultados_dp.csv";

    ofstream salida_dp(archivo_resultados_dp);
    salida_dp << "subdataset,tipo_dataset,tamanioS1,tamanioS2,costodp,tiempo_dp\n";

    int subdataset_id_dp = 1;
    for (const auto &entrada : fs::directory_iterator(ruta_dataset_dp)) {
        if (entrada.path().extension() == ".csv") {
            string tipo_dataset = entrada.path().stem().string();
            vector<vector<string>> dataset = leerCSV(entrada.path().string());

            for (size_t i = 1; i < dataset.size(); i++) {
                int tamanio_s1 = stoi(dataset[i][0]);
                int tamanio_s2 = stoi(dataset[i][1]);
                string s1 = dataset[i][2];
                string s2 = dataset[i][3];

                auto start_dp = high_resolution_clock::now();
                int costo_dp = edit_distance_DP(s1, s2);
                auto end_dp = high_resolution_clock::now();
                float tiempo_dp = duration_cast<microseconds>(end_dp - start_dp).count() / 1000.0f;

                salida_dp << subdataset_id_dp << "," << tipo_dataset << ","
                          << tamanio_s1 << "," << tamanio_s2 << ","
                          << costo_dp << "," << fixed << tiempo_dp << "\n";
            }
            subdataset_id_dp++;
        }
    }
    salida_dp.close();

    cout << "Resultados guardados correctamente :)" << endl;
    return 0;
}