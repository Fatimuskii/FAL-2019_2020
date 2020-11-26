// Nombre del alumno Fatima Garcia Delgado
// Usuario del Juez E24


#include <iostream>
#include <iomanip>
#include <fstream>



// función que resuelve el problema
// devuelve el numero de digitos
long long int resolver(long long int num) {

    // Caso base 
    if (num < 10) {
        return 1;
    }
        
    else {

        return resolver(num / 10) +1;
    }

}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada

    long long int numero;
    std::cin >> numero;
    if (!std::cin)
        return false;

    long long int sol = resolver(numero);

    // escribir sol
    std::cout << sol << '\n';

    return true;


}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("23sample.in");
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