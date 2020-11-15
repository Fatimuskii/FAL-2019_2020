
// Nombre y apellidos del alumno Fatima Garcia Delgado
// Usuario del juez de clase E24

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

// Explicación del algoritmo utilizado

/* Iteramos sobre el vector que se nos da, agrupando los valores que queremos (en este caso las matriculas pares), y luego 
eliminamos el resto de valores que nos queremos (en este caso los impares)*/


// Coste del algoritmo utilizado

/* Coste lineal -> O(N) siendo N el numero de matriculas */

// Esta función recibe un vector con los números de matricula de los alumnos
// Modifica el vector de entrada eliminando los valores impares
void resolver (std::vector<int> & v) {
    // Codigo del alumno

    int contPar = 0; 
    for (int i = 0; i < v.size(); ++i) {
        if (v[i] % 2 == 0) { // par
            v[contPar] = v[i];
            ++contPar; 
        }
    }

    v.resize(contPar);

}

// Funcion que lee de la entrada, 
// LLama a la función que resuelve el problema
// Escribe la salida
bool resuelveCaso() {
    // Leer datos de entrada
    int numElem;
    std::cin >> numElem;
    if (numElem == -1) return false;
    std::vector<int> v(numElem);
    for (int i = 0; i < numElem; ++i) {
        std::cin >> v[i];
    }
    // LLamada a la función resolver
    resolver(v);
    // Escribir el vector resultado
    if (v.size() > 0) std::cout << v[0];
    for (int i = 1; i < v.size(); ++i)
        std::cout << ' ' << v[i];
    std::cout << '\n';
    return true;
}

int main() {
    // Para la entrada por fichero. Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("10sample.in");
    auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif

    int numCasos;
    std::cin >> numCasos;
    for (int i = 0; i < numCasos; ++i) resuelveCaso();
    
    // Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif

    return 0;
}
