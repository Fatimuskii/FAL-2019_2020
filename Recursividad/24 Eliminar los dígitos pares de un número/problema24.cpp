// Nombre del alumno Fatima Garcia Delgado
// Usuario del Juez E24


#include <iostream>
#include <iomanip>
#include <fstream>

// Eliminar los digitos pares de un numero

// función que resuelve el problema
// devuelve el numero de digitos
long long int resolver(long long int num, int potencia) {


    if (num < 10) {
        if (num % 2 == 1) return num * potencia;
        else return 0;
    }
    else {
        if ((num % 10) % 2 == 1) {
            long long int resto = num % 10 * potencia;
            potencia = potencia * 10;
            return resolver(num / 10, potencia) + resto;
        }
        else
            return resolver(num / 10, potencia) + 0;

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
    
    int potencia = 1;

    long long int sol = resolver(numero, potencia);

    // escribir sol
    std::cout << sol<< '\n';

    return true;


}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("24sample.in");
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