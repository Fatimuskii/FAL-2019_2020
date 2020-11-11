// Nombre del estudiante. 
// Usuario del juez.

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <vector>
#include <algorithm>

// Explicación del algoritmo utilizado

// Coste del algoritmo utilizado


// Recibe un vector con los datos de entrada del problema
// Debe contar el número de veces que aparece cada valor usando un vector auxiliar.
// Devuelve un vector con los valores que se repiten el número máximo de veces
// para que la función resuelveCaso solo tenga que escribirlos. 
// Si solo hay un valor que se repite el número máximo de veces el vector de salida
// tendrá solo ese valor 
std::vector<int> resolver(std::vector<int> const& v, int maximoValores){
   // Aqui codigo del estudiante
    
    std::vector<int> aux(maximoValores, 0);
    // relleno el vector aux
    for (int i = 0; i < v.size(); ++i) {
        aux[v[i] - 1]++;
    }

    // valor maximo del vector aux
    int maxElement = *std::max_element(aux.begin(), aux.end());
    std::vector<int> sol;
    // vamos a coger los maximos
    for (int i = 0; i < aux.size(); ++i) {
        if (aux[i] == maxElement) {
            sol.push_back(i);
        }
    }
    return sol; 

}

// Entrada y salida de datos
bool resuelveCaso() {
    int numTiradas, valorMax;
    std::cin >> numTiradas >> valorMax;
    if (numTiradas == -1) return false;  // Entrada con centinela
    std::vector<int> v(numTiradas);
    for (int& i : v) std::cin >> i;
    // LLamada a la funcion resolver para calcular los valores que 
    // aparecen más veces
    auto sol = resolver(v, valorMax);
                // Codigo
    std::cout << sol[sol.size()-1]+1;
    for (int i=sol.size()-2; i >=0; --i){
        std::cout << " " << sol[i] + 1 ;
    }

    std::cout << '\n';
    // Escribir los valores del vector que ha calculado resolve
    
    return true;
}

int main() {
    
#ifndef DOMJUDGE
    std::ifstream in("08sample.in");
    auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt    
#endif
    
    while (resuelveCaso()) 
        ;
    
#ifndef DOMJUDGE // para dejar todo como estaba al principio
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif
    
    return 0;
}

