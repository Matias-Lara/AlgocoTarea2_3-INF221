# Proyecto: Comparación de Algoritmos para la Distancia de Levenshtein

Este proyecto contiene la implementación de dos algoritmos, Fuerza Bruta (BF) y Programación Dinámica (DP), para calcular la distancia de Levenshtein extendida con costos variables y la operación de transposición. El objetivo es analizar y comparar el desempeño de ambos enfoques en términos de tiempos de ejecución y escalabilidad utilizando diferentes datasets.

## Estructura del Proyecto

A continuación, se describe la estructura de archivos y carpetas del proyecto:

```
.
├── Algoritmos
│   ├── bf.cpp
│   ├── bf.h
│   ├── dp.cpp
│   └── dp.h
├── CostosVariables
│   ├── costo_elim.txt
│   ├── costo_ins.txt
│   ├── costo_sub.txt
│   ├── costo_trans.txt
│   ├── costos.cpp
│   └── costos.h
├── DataSet_comun
│   ├── common_substring.csv
│   ├── empty_vs_n.csv
│   ├── high_similarity.csv
│   ├── random_nxm.csv
│   └── transpositions.csv
├── DataSet_dp
│   └── random_nxm.csv
├── README.md
├── generadorDataSet.py
├── generadorGraficos.ipynb
├── main
├── main.cpp
├── makefile
└── resultados
    ├── resultados_comun.csv
    └── resultados_dp.csv
```

## Descripción del Flujo de Trabajo

1. **Generación de Datasets**:
   - Utiliza el script `generadorDataSet.py` para generar los datasets necesarios para los experimentos.
   - Los datasets generados se almacenan en las carpetas `DataSet_comun` y `DataSet_dp`.

2. **Ejecución del Programa Principal**:
   - Compila el programa usando `make clean` seguido de `make` desde una terminal en un sistema Linux.
   - Ejecuta el programa con `./main`. Este procesará los datasets y generará los resultados en la carpeta `resultados`.

3. **Análisis de Resultados**:
   - Los archivos `resultados_comun.csv` y `resultados_dp.csv` contienen los tiempos y costos experimentales obtenidos.
   - Utiliza el notebook `generadorGraficos.ipynb` para procesar los resultados y generar gráficos comparativos.

## Requisitos

- Compilador de C++ compatible con `make`.

## Notas Importantes

- **Replicación de Resultados:** Asegúrate de colocar los archivos `resultados_comun.csv` y `resultados_dp.csv` en la misma carpeta desde la que ejecutas el notebook de gráficos.
- **Tiempo de Ejecución:** La ejecución del programa principal puede tardar varios minutos debido a la cantidad de pruebas realizadas y la complejidad del algoritmo de Fuerza Bruta en instancias grandes.
