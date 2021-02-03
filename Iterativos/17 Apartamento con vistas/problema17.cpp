// Nombre del alumno Fatima Garcia Delgado
// Usuario del Juez E24

// Un apartamento con vistas

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <algorithm>


struct tEdificio {
    std::string identificador =""; 
    int altura = -1; 
    int pisoEnVenta=-1; 
};
// función que resuelve el problema
std::vector<std::string> resolver(std::vector <tEdificio> const& v) {
    int mayor = -1;
    std::vector <std::string> solucion;
    for (int i = v.size() - 1; i >= 0; i--){
        if (v[i].pisoEnVenta != -1 && v[i].pisoEnVenta > mayor)
            solucion.push_back(v[i].identificador);
       
        mayor = std::max(mayor, v[i].altura);
    }

    return solucion;
}
// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada

    int numEdificios; 
    std::cin >> numEdificios; 
    if (numEdificios == 0)
        return false;
    std::vector<tEdificio> edificios(numEdificios); 

    for (int i = 0; i < numEdificios; ++i) {
        std::cin >> edificios[i].identificador >> edificios[i].altura >> edificios[i].pisoEnVenta; 
    }
    auto sol = resolver(edificios);

    // escribir sol
    if (sol.size() == 0) 
        std::cout << "Ninguno";
    else {
        std::cout << sol.size() << '\n';

        std::cout << sol[0];
        for (int i = 1; i < sol.size(); ++i)
            std::cout <<" " << sol[i];
    }
    std::cout << '\n';
    return true;

}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("17sample.in");
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