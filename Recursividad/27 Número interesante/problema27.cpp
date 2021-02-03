// Nombre del alumno Fatima Garcia Delgado
// Usuario del Juez E24

// Numero interesante
#include <iostream>
#include <iomanip>
#include <fstream>

/* Explicacion de como se desarrolla: 
    
   En cada llamada recursiva le pasamos:
    - El siguiente digito que le toca
    - La suma acumulativa que lleva por la izquierda (este valor se va actualizando en cada llamada recursiva)
   En cada llamada recursiva devolvemos al necesitar 2 valores creamos un struct tSol):
    - Un true/false si cumple la propiedad
    - la sum de la parte de la derecha acumulada. 

*/

/*
    coste: 
                Co  n < 10 
    T(n) = {
                T(n-1) + C1 n>=0

    Orden de esta recurrencia es: O(n) siendo n el numero de digitos del numero a analizar
*/

struct tSol {
    bool esInteresante;
    int sumaIzq; 
};
// función que resuelve el problema
// 2 parametros de entrada: el numero y sumaDerecha
// Forma no final
tSol resolver(int num, int sumaDrch) {

    //caso base
    if (num < 10) {
        //Si es 0, el numero ya no es interesante
        if (num == 0) return { false, 0 };
        // divisible por el acumulado a la drcha y el digito
        else if (sumaDrch % num != 0) return { false, 0 };
        else return { true, num };

    }
    else {
        if (sumaDrch % (num % 10))
            return { false, 0 };
        //hacemos la llamada recursiva
        auto sol = resolver(num / 10, sumaDrch + num % 10); // 621348 --> 62134 , 0 + 8(...)

        if (!sol.esInteresante) return { false, 0 };
        else if (sol.sumaIzq % (num % 10) != 0) return { false, 0 };
        else return { true, sol.sumaIzq + (num % 10) }; 

    }

}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
    int num; 
    std::cin >> num;

    tSol sol = resolver(num, 0); 

    // escribir sol
    if (sol.esInteresante) std::cout << "SI\n";
    else std::cout << "NO\n";

}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("27sample.in");
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