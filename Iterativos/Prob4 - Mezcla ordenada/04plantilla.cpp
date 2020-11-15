// Nombre del estudiante. Fatima Garcia
// Usuario del juez. E24

#include <iostream>
#include <fstream>
#include <vector>

// Explicación del algoritmo utilizado
// Recorremos los mismos valores de cada vector, comparandolos. 
// SI un vector es mas grande que otro, lo que quede del vector grande.

// Coste del algoritmo utilizado
// Recorremos cada vector (v1 y v2) unicamente 1 vez. Luego el coste es O(N) + O (M) == O(N), siendo N y M el numero de elementos del vector. 

std::vector<int> resolver(std::vector<int>const& v1, std::vector<int>const& v2) {
    // Declaración de variables
    // Codigo del alumno

    int i = 0;
    int j = 0;

    std::vector<int> sol;
    while (i < v1.size() && j < v2.size()) {

        // Aqui codigo del alumno
        if (v1[i] == v2[j]) {
            sol.push_back(v1[i]);
            i++;
            j++;
        }
        else if (v1[i] < v2[j]) {
            sol.push_back(v1[i]); 
            i++;
        }
        else {
            sol.push_back(v2[j]);
            j++;
        }             
    }

    while (i < v1.size()) {
        // Aqui codigo del alumno
        sol.push_back(v1[i]);
        i++;
    }
    while (j < v2.size()) {
        // Aqui codigo del alumno
        sol.push_back(v2[j]);
        j++;
    }

    return sol;
}


void resuelveCaso() {
    // Lectura de los datos de entrada
    int n1, n2; 
    std::cin >> n1 >> n2;
    std::vector<int> v1(n1);
    std::vector<int> v2(n2);
    for (int& i : v1) std::cin >> i;
    for (int & j : v2) std::cin >> j;
    // LLamada a la función que resuelve el problema
    std::vector<int> sol = resolver(v1, v2);
    // Escribir los resultados
    if (!sol.empty()) {
        std::cout << sol[0];
        for (int i = 1; i < sol.size(); ++i) 
            std::cout << ' ' << sol[i];
    }
    std::cout << '\n';
}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto

 #ifndef DOMJUDGE
    std::ifstream in("04sample.in");
    auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
 #endif

    int numCasos;
    std::cin >> numCasos;
    for (int i = 0; i < numCasos; ++i) {
        resuelveCaso();
    }
    
    // Para restablecer entrada. Comentar para acepta el reto

#ifndef DOMJUDGE // para dejar todo como estaba al principio
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif

    return 0;
}
