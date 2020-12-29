// Nombre del alumno Fatima García Delgado   
// Usuario del Juez E24


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

// Torres de colores. Version1

// Colores disponibles: azul, rojo y verde
int const COLORES = 3; 
//Mostrar por pantalla la soluciobn
void escribirSolucion(std::vector<int> const& v) {
    for (int c : v) {
        switch (c) {
        case 0:
            std::cout << "azul" << ' '; 
            break; 
        case 1: 
            std::cout << "rojo" << ' ';
            break;
        case 2:
            std::cout << "verde" << ' ';
            break;
        }

    }

    std::cout << '\n'; 
}

// función que resuelve el problema
void resolver( int altura, int k, std::vector<int>& sol) {

    for (int i = 0; i < COLORES; ++i) {
        //sol
        sol[k] = i;
        if (k == altura - 1) { // Es solucion (n: tam de la solucion)
            escribirSolucion(sol);
        }
        else { // seguimos construyendo la solucion 
            resolver(altura,k + 1, sol);
        }
    }


}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int alt; 
    std::cin >> alt;
    if (alt == 0)
        return false;

    // Generar las soluciones
    std::vector<int>sol(alt);
    resolver(alt,0, sol); 

    std::cout << '\n';
    return true;

}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("47Asample.in");
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