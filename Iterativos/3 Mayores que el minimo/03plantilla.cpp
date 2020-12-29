// Nombre y apellidos del alumno FATIMA GARCIA DELGADO  
// Usuario del juez de clase E24 

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <algorithm>
#include <string>
#include <utility>

// Explicación del algoritmo utilizado


// Coste del algoritmo utilizado
struct tSol {
    int suma;
    int contador;
};

// Función que resuelve el problema
// Recibe un vector con los datos
// Devuelve suma de los valores y número de sumandos de la suma
tSol resolver(std::vector<int> v) {
    // Inicialización de variables
    // Codigo del alumno
    int suma = 0;
    int cont = 0;
    tSol minimo = { v[0], 1 };
    for (int i = 1; i < v.size(); ++i) {
        
        // Aqui el código del alumno
        // Si el numero que leo es menor que el actul, actualizamos nuestra suma y contador
        // tb actualizamos la variable menor 
        if (v[i] < minimo.suma) {
            suma += minimo.suma * minimo.contador;
            cont+= minimo.contador;
            minimo = { v[i], 1 };
        }

        // si es igual al menor, incremementamos el contador de minimo
        else if (v[i] == minimo.suma)
            minimo.contador++;
        // si es mayor vamos sumando y aumentamos el cont
        else {
            suma += v[i];
            cont++;
        }
           
        // No deben hacerse más bucles
        
    }
    return {suma, cont};
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // Lectura de los datos
    int numElem;
    std::cin >> numElem;
    std::vector<int> v(numElem);
    for (int& i : v) std::cin >> i;
    // LLamar a la función resolver
    tSol s = resolver(v);
    // Escribir los resultados
    std::cout << s.suma << ' ' << s.contador << '\n';
}

int main() {
    // Para la entrada por fichero. Comentar para mandar a acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("03sample.in");
    auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif
 
    int numCasos;
    std::cin >> numCasos;
    for (int i = 0; i < numCasos; ++i) resuelveCaso();
    
    // Para restablecer entrada. Comentar para mandar a acepta el reto

#ifndef DOMJUDGE // para dejar todo como estaba al principio
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif

    return 0;
}
