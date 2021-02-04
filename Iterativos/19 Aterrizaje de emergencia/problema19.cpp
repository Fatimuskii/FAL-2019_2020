// Nombre del alumno Fatima Garcia 
// Usuario del Juez E24

#include <iostream>
#include <iomanip>
#include <fstream>
#include<vector> 


// Atterrizaje de emergencia

// función que resuelve el problema
void resolver(std::vector<int> const& v, int const& minValores, std::vector<int>&sol ) {

    int cont = 1; 
   
    for (int i = 1; i < v.size(); ++i) {

        if (std::abs(v[i] - v[i - 1]) == 1 || std::abs(v[i] - v[i - 1]) == 0) {

            cont++;
            if (cont >= minValores) {
                if (sol.empty() || sol[sol.size()-1]!= (i-cont+1)) {
                    sol.push_back(i - cont + 1);
                }   
            }
        }
        else {
            cont = 1;
        }
           


    }

}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada

    int numDatos, minValores; // num de datos tomados || cantidad de calores casi iguales que se necesitan
    std::cin >> numDatos >> minValores; 
    if (numDatos == 0)
        return false;

    std::vector<int> valoresTomados(numDatos); 
    for (int i = 0; i < numDatos; ++i) {
        std::cin >> valoresTomados[i];
    }

    std::vector<int>sol; // vector donde guardo los indices de las soluciones
    resolver(valoresTomados, minValores, sol);

    // escribir sol
    if (sol.empty()) std::cout << "0"; 
    else {
        std::cout << sol.size() <<" " << sol[0];
        for (int i = 1; i < sol.size(); ++i)
            std::cout << " " << sol[i]; 
    }

    std::cout << '\n'; 
    return true;

}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("19sample.in");
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