// Nombre del alumno Fatima Garcia Delgado
// Usuario del Juez E24

// Los km mas duros de la etapa

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>


struct tSol {
    int maxDesnivel;
    int comienzo;
    int fin;
};
// función que resuelve el problema
tSol resolver(std::vector<int> const&v, int const& L) {

    tSol sol = { -100 , -1, -1 }; 
    int desActual = 0;

    // calculamos el primer segmento de tam L,  guardamos su maxDes
    for (int i = 0; i < L; ++i) {
        desActual += v[i];
    }
    sol.maxDesnivel = desActual; 
    sol.comienzo = 0; 
    
    // Ahora partiendo del primer intervalo calculado, continuamos a partir de la pos L, para ver si avanzamos o no
    for (int j = L; j < v.size(); ++j) {
        desActual = desActual + v[j] -v[j - L]; // coste del tramo actual 
        if (desActual > sol.maxDesnivel) {
            sol.maxDesnivel = desActual; 
            sol.comienzo = j - L +1; 
            sol.fin = sol.comienzo;
        }
        else if (desActual == sol.maxDesnivel ) { // sin solapar seria añadirle:: && !(j-L+1 < L )
            sol.fin = j - L +1; 
        }

    }

    if (sol.fin == -1)
        sol.fin = sol.comienzo;
    return sol; 

}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada

    int numKm, longTramo; 
    std::cin >> numKm >> longTramo; 
    if (numKm == 0 && longTramo==0)
        return false;
    std::vector<int> desniveles(numKm); 

    for (int i = 0; i < numKm; ++i) {
        std::cin >> desniveles[i]; 
    }

    tSol sol = resolver(desniveles, longTramo);

    // escribir sol
    std::cout << sol.maxDesnivel << " " << sol.comienzo << " " << sol.fin << '\n';
    return true;

}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("18sample.in");
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