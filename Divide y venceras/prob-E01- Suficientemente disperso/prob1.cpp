// Nombre del alumno Fátima García
// Usuario del Juez E27

// Problema 1 - Suficientemente Disperso

//Coste:
/*
                Co   n==1
    T(n) = {
                2T(n/2) + C1 n>=2

            siendo n el numero de elementos del vector (tiradas) 

    Por lo tanto el coste es de orden O(n)

*/

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include<string>



// función que resuelve el problema
bool resolver(std::vector<int> const& datos, int const&valorDispersion, int ini, int fin) {

    // Si solo hay 1 valor == suficientemente disperso
    if (ini+1 == fin)
        return true; 
    else {

        int mitad = (ini + fin) / 2; 
        bool izq = resolver(datos, valorDispersion, ini, mitad); 
        bool drch = resolver(datos, valorDispersion, mitad, fin); 

        return izq && drch && std::abs(datos[ini]- datos[fin - 1])>=valorDispersion; 
    }

}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada

    int numTiradas, valorDispersion, num;
    std::cin >> numTiradas;
    if (!std::cin)
        return false;

    std::cin >> valorDispersion; 

    std::vector<int>tiradas; 
    for (int i = 0; i < numTiradas; ++i) {
        std::cin >> num; 
        tiradas.push_back(num);
    }

    int ini = 0; 
    int fin = numTiradas;
    // escribir sol
    if (resolver(tiradas, valorDispersion, ini, fin))
        std::cout << "SI\n";
    else
        std::cout << "NO\n";

    return true;

}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("datos.txt");
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