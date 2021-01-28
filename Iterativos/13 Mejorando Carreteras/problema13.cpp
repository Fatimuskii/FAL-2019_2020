// Nombre del alumno Fatima Garcia Delgado 
// Usuario del Juez E24

// Mejorando carreteras. 

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <algorithm>

// función que resuelve el problema
int resolver(std::vector<int>const&v) {
   
    int valorActual = v[0];  
    int longActual = 0; 
    int maxLongitud = 0;
    int sol = valorActual; 
    int k = 1;
    while (k  < v.size()) {
        if (v[k] == valorActual) {
            longActual++;
            if (longActual > maxLongitud) {
                maxLongitud = longActual;
                sol = valorActual;
            }

        }
        else {
            valorActual = v[k]; 
            longActual = 0; 
        }      
        k++; 
    }

    return sol; 
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada

    long long int numAccidentes; // Numero de accidentes ocurridos
    std::cin >> numAccidentes; 
    if (numAccidentes == -1)
        return false;

    std::vector<int> vAccidentes(numAccidentes); 

    for (int i = 0; i < numAccidentes; ++i)
        std::cin >> vAccidentes[i]; 

    std::sort(vAccidentes.begin(), vAccidentes.end());

    // Parametros de entrada: vector con los accidentes ordenados, k para saber por donde voy, longActual para llevar). 
    int sol = resolver(vAccidentes);

    // escribir sol
    std::cout << sol << '\n'; 
    return true;

}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("13sample.in");
    auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif 


    while (resuelveCaso())
        ;


    // Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif

    return 0;
}