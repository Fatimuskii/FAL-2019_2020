// Nombre del alumno Fátima G. 
// Usuario del Juez E24


// ¿ Está bien dividido el vector ?

// O(n): lineal respecto al numero de elementos del vector
#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>



// función que resuelve el problema
bool resolver(std::vector<int> const& v, int pos) {

    int max = v[0]; // max desde [0-p]

    // recorremos de [0-p] y nos quedamos con el valor maximo.
    for (int i = 0; i <= pos; ++i) {
        if (v[i] > max) {
            max = v[i]; 
        }
    }

    // recorremos de [p+1 - n-1] comprobando que sea < que el max 
    int j = pos + 1;
    while (j < v.size()) {
        if (v[j] <= max)
            return false;
        ++j;
    }

    return true;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada

    int numElementos, pos, num; 
    std::cin >> numElementos >> pos; 

    std::vector<int> vector; 
    for (int i = 0; i < numElementos; ++i){
        std::cin >> num;
        vector.push_back(num); 
    }

    bool sol = resolver(vector, pos);
    // escribir sol
    std::cout << (sol ? "SI\n" : "NO\n"); 


}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("datos.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif 


    int numCasos;
    std::cin >> numCasos;
    for (int i = 0; i < numCasos; ++i)
        resuelveCaso();


    // Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif

    return 0;
}