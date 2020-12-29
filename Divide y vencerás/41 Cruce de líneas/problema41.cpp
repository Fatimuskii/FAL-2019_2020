// Nombre del alumno Fátima García
// Usuario del Juez E24


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

// Cruce de lineas 
struct sol {
    bool existe;
    int posicion;
};
// función que resuelve el problema
sol resolver(std::vector<int>const& v1, std::vector<int>const& v2, int ini, int fin) {


    //caso base
    if (ini == fin) {
        if (v1[ini] == v2[fin]) return { true,ini };
        else {
            if (v1[ini] > v2[ini])return { false,ini - 1 };
            else return { false, ini };
        }
    }
    else {
        int m = (ini + fin) / 2;

        if (v1[m] < v2[m]) return resolver(v1, v2, m + 1, fin);
        else return resolver(v1, v2, ini, m);
    }
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int numElem;
    std::cin >> numElem;
    if (numElem == 0)
        return false;
    std::vector<int>v1(numElem); // creciente
    std::vector<int>v2(numElem); // decreciente.


    for (int& p : v1) {
        std::cin >> p;
    }

    for (int& q : v2) {
        std::cin >> q;
    }

    int ini = 0;
    int fin = numElem - 1;

    sol sol = resolver(v1, v2, ini, fin);
    // escribir sol
    if (sol.existe)
        std::cout << "SI " << sol.posicion << '\n';
    else
        std::cout << "NO " << sol.posicion << " " << sol.posicion + 1 << '\n';

    return true;
}


int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("41sample.in");
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