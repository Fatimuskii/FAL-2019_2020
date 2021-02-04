// Nombre del alumno Fatima Garcia Delgado
// Usuario del Juez E24


// Cuanto tiempo llevas sin batir tu mejor marca?


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>


struct tSol {
    int maxPruebasMalas; // maximo de pruebas en q el atleta no ha mejorado su mejor marca HASTa el momento
    int comienzo; // comienzo del ultimo periodo maximo de pruebas 
};

// función que resuelve el problema
tSol resolver(std::vector<int> const&v) {
    int mejorMarca = v[0];
    int ini = 0;
    int contPruebasMalas = 0;
    int maxMalas = -1; 

    for (int i = 1; i < v.size(); i++) {

        if (v[i] <= mejorMarca) {
            contPruebasMalas++;
            if(ini != i - contPruebasMalas +1)
                ini = i-contPruebasMalas+1;
        }

        else {
            if (v[i] > mejorMarca) {
                mejorMarca = v[i];
                if (contPruebasMalas > maxMalas) {
                    maxMalas = contPruebasMalas;
                    ini = i - maxMalas + 1;
                }
                contPruebasMalas = 0;
            }
        }
    }
    if (maxMalas == -1)
        maxMalas = contPruebasMalas;
    else if (maxMalas == 0) 
        ini = v.size();
    
    return { maxMalas, ini };
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int numMarcas; 
    std::cin >> numMarcas; 

    if (numMarcas == 0)
        return false;
    std::vector<int> marcas(numMarcas); 

    for (int i = 0; i < numMarcas; ++i) {
        std::cin >> marcas[i]; 
    }

    tSol sol = resolver(marcas);

    // escribir sol
    std::cout << sol.maxPruebasMalas << " " << sol.comienzo << '\n'; 
    return true;

}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("21sample.in");
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