
// Nombre y apellidos del alumno Fatima Garcia Delgado 
// Usuario del juez de clase E24

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

// Explicación del algoritmo utilizado
// Tenemos que calcula el segmento maximo de elementos de un vector que cumplen la propiedad, en este caso de ser estrcitamente mayores a un tam (alturaNave). 
/*
Recorremos el vector guardando aquellos segmentos que cumplen la condicion, y llevando un contador de cuantos elemenos han cumplido la condicion. 

*/


// Coste del algoritmo utilizado
/* Se recorre todos lo elementos del vector, con operaciones de incremento y consulta del valor del vector que son constantes. 
Luego el coste es lineal -> O(N) siendo N el numero de elemtnos del vector */


// La función recibe un vector con las alturas de los edificios, y la altura de la nave que realizará el rescate
// Devuelve las posiciones de inicio y fin del segmento máximo encontrado.
void resolver(std::vector<int> const& v, int alturaNave, int & posIni, int& posFin) {

// Codigo del alumno
    int contEdificios = 0;
    int contMaxEdificios = 0;

    for (int i = 0; i < v.size(); ++i) {
        if (v[i] > alturaNave) { // elemento cumple la condicion
            ++contEdificios; // incrementamos el contador de edificios que cumplen la propiedad

            if (contEdificios > contMaxEdificios) { // actualizamos el max
                contMaxEdificios = contEdificios;
                posFin = i;
                posIni = posFin - contMaxEdificios + 1;
            }

        }
        else { // reseteamos el cont
            contEdificios = 0;
        }
    }


}

// Funcion que lee de la entrada, 
// LLama a la función que resuelve el problema
// Escribe la salida
void resuelveCaso() {
    // Lectura de los datos de entrada
    int numElem, alturaNave;
    std::cin >> numElem >> alturaNave;
    std::vector<int> v(numElem);
    for (int& i : v) std::cin >> i;
    // LLamada a la función resolver
    int p, q;
    resolver(v, alturaNave, p, q);
    // Escribir el resultado
    std::cout << p << ' ' << q << "\n";
}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("11sample.in");
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
