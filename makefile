# Ejecutable
EXEC = main

# Archivos usados
SOURCES = main.cpp Algoritmos/bf.cpp Algoritmos/dp.cpp CostosVariables/costos.cpp

# Compilador y banderas
CXX = g++
CXXFLAGS = -Wall -std=c++17

# Regla para compilar todo
$(EXEC): $(SOURCES)
	$(CXX) $(CXXFLAGS) $(SOURCES) -o $(EXEC)

# Regla para limpiar archivos compilados
clean:
	rm -f $(EXEC)
