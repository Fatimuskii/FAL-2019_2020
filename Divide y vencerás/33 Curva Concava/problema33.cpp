// Nombre del alumno Fátima García Delgado
// Usuario del Juez E24


//Perfil de una curva concava

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>


// función que resuelve el problema
int resolver(std::vector<int>const & v, int ini, int fin) {
  
    //Caso base, 1 elemento
    if (ini == fin - 1) {
        return v[ini];
    }
    // Caso base 2 elementos
    if (ini == fin - 2) {

        return v[ini] < v[ini + 1] ? v[ini] : v[ini + 1];
    }
    else {
        int m = (ini + fin) / 2;

        if (v[m - 1] > v[m] && v[m] < v[m + 1])
            return v[m];
        else if (v[m] < v[m - 1])
            return  resolver(v, m, fin);
        else
            return resolver(v, ini, m);
    }

}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int num, N;
    std::cin >> N;
    if (!std::cin)
        return false;

    std::vector<int> v;
    
    for (int i = 0; i < N; ++i) {
        std::cin >> num;
        v.push_back(num);
    }
    int sol = resolver(v, 0, N);

    // escribir sol
    std::cout << sol << '\n';

    return true;

}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("33sample.in");
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