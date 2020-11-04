// Nombre del alumno Fatima Garcia  
// Usuario del Juez E24

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

// función que resuelve el problema
// devolveremos un vector con los años que cumplen la condicion
std::vector<int> resolver(std::vector<std::pair<int, int>> const&vector) {
    
    auto init = vector[0]; // primer dato 
    std::vector<int> sol;
    for (int i = 1; i < vector.size(); ++i) {
        if (vector[i].second > init.second){ // si la cantidad actual es mayor que el  anterior
            sol.push_back(vector[i].first);
            init = vector[i];
        }
    }

    return sol;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
   
    int first_year, last_year;
    std::cin >> first_year >> last_year;

    std::vector<std::pair<int, int>> vector; // elementos par de <year, value> 
    int years = last_year - first_year + 1;
    int value;
    for (int i = 0; i < years; ++i) {
        std::cin >> value; 
        vector.push_back({ first_year, value });
        first_year++;
    }
    auto sol = resolver(vector);
    // escribir sol
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
    std::ifstream in("05sample.in");
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