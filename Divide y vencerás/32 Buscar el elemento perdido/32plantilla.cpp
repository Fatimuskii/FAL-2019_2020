//*****************
// IMPORTANTE
//
// Nombre y apellidos del alumno Fatima Irene Garcia Delgado
// Usuario del juez E24
//
//***************************************************

#include <iostream>
#include <fstream>
#include <vector>

//*******************************
// Explicacion del algoritmo utilizado
// Coste de la solucion. Recurrencia y orden de complejidad
//*******************

// Aqui la funcion recursiva que resuelve el problema
int resolver(std::vector<int> const& vA, std::vector<int> const& vB, int ini, int fin) {

    // caso base (vB 1 elemento, y vA 2 elementos)
    if (ini + 1 == fin) {
        return vB[ini] == vA[ini] ? vA[fin] : vB[ini]; 
    }

    else {

        int m = (ini + fin) / 2; 

        if (vA[m] == vB[m])
            return resolver(vA, vB, m, fin);
        else
            return resolver(vA, vB, ini, m); 

    }

}


// Tratar cada caso
void resuelveCaso() {
    int numA;
    // lectura del vector A
    std::cin >> numA;
    std::vector<int> vA(numA);
    for (int i = 0; i < numA; ++i)
        std::cin >> vA[i];
    // lectura del vector B
    std::vector<int> vB(numA-1);
    for (int j = 0; j < numA - 1; ++j)
        std::cin >> vB[j];

    if(vA.size() == 1 || vA[0] != vB[0])
        std::cout << vA[0] << '\n';

    else if(vA[numA-1] != vB[vB.size()-1])
        std::cout << vA[numA-1] << '\n';
    
    else {
        // resolver
        int n = resolver(vA, vB, 0, vB.size() - 1);
        // mostrar resultado
        std::cout << n << '\n';
    }

}


int main() {
    // Para la entrada por fichero.
#ifndef DOMJUDGE
    std::ifstream in("32sample.in");
    auto cinbuf = std::cin.rdbuf(in.rdbuf()); 
#endif

    int casos;
    std::cin >> casos;
    for (int i = 0; i < casos; ++i)
        resuelveCaso();
    
    // Para restablecer entrada.
#ifndef DOMJUDGE // para dejar todo como estaba al principio
    std::cin.rdbuf(cinbuf);
    //system("PAUSE");
#endif
    
    return 0;
}
