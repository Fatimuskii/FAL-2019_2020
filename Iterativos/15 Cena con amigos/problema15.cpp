// Nombre del alumno Fatima Garcia Delgado
// Usuario del Juez ED24


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

struct tSol {
    int sum; 
    int pos; 
    int size; 
};

// función que resuelve el problema
tSol resolver(std::vector<int> const& v) {

    tSol sol = { 0,0,0 }; 
    int size = 0; 
    int sum= 0; 
    int ini = 0; 

    for (int i = 0; i < v.size(); ++i) {
        sum += v[i]; 
        if (sum > 0) { // positive 
            if (size == 0) ini = i; 

            size++;

            if (sum > sol.sum) {
                sol.sum = sum; 
                sol.size = size; 
                sol.pos = ini; 
            }
           
        }

        else {
            if (sum > sol.sum) {
                sol.sum = sum;
                sol.size = size;
                sol.pos = ini;
            }

            else { // se cancela la suma
                size = 0;
                sum = 0;
            }
        }
        if (sol.sum == sum && sol.size > size) { // si la suma es igual se coge la secuencia mas corta. 
            sol.size = size;
            sol.pos = ini;
        }

    }

    return sol; 
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int numElementos; 
    std::cin >> numElementos; 
    if (!std::cin)
        return false;

    std::vector<int> v(numElementos); 

    for (int i = 0; i < numElementos; ++i) {
        std::cin >> v[i]; 
    }
   
    auto sol = resolver(v);

    // escribir sol

    std::cout << sol.sum << " " << sol.pos << " " << sol.size << '\n'; 
    return true;

}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("15sample.in");
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