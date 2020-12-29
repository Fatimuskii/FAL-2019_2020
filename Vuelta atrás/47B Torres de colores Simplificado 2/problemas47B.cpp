// Nombre del alumno Fatima García Delgado   
// Usuario del Juez E24


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

// Torres de colores. Version2

// Colores disponibles: azul(0), rojo(1) y verde(2)
int const COLORES = 3;

//Condicion que comprueba que no se colocan dos piezas verdes seguidas. 
bool esValida(std::vector<int> const& v, int colorActual, int pos) {

    if (colorActual == 2 && colorActual == v[pos - 1])
        return false; 

    return true;
}
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
void resolver(int altura, int k, std::vector<int>& sol) {

    for (int i = 0; i < COLORES; ++i) {
        //sol
        if (esValida(sol, i, k)) {
            sol[k] = i; 

            if (k == altura - 1) { // Es solucion (n: tam de la solucion)
                escribirSolucion(sol);
            }
            else { // seguimos construyendo la solucion 
                resolver(altura, k + 1, sol);
            }
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
    std::vector<int>sol(alt, -1);
    // Primera pieza es siempre roja
    sol[0] = 1;
    if (alt == 1) {
        escribirSolucion(sol);
    }
    else {
        resolver(alt, 1, sol);
    }

    

    std::cout << '\n';
    return true;

}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("47Bsample.in");
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