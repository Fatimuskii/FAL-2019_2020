// Nombre del alumno Fátima García
// Usuario del Juez E24


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>


// función que resuelve el problema
/*
TipoSolucion resolver(TipoDatos datos) {


}

*/

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada

    int num;
    int max; 
    int cont = 0;

    std::cin >> num; 
    max = num; // asignamos el max al primer elemento 

    while (num != 0) {
        
        if (num > max) {// comparamos el max por si tenemos que actualizar
            max = num; 
            cont = 1; 
        }
        else if (num == max) { // si conicide con el max incrementamos su contador
            cont++;
        }
        //leemos el siguiente numero
        std::cin >> num;

    }
 
    // escribir sol
    std::cout << max << " " << cont << '\n'; 

}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("datos.txt");
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