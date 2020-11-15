// Nombre y apellidos del alumno Fátima Irene García Delgadp
// Usuario del juez de clase E24
// Usuario del juez de examen que has utilizado en la prueba de hoy E32

#include <iostream>
#include <cstdlib>
#include <vector>
#include <fstream>

//*******************************
// Aqui especificación de la función que resuelve el problema. 
// Aplicamos un algoritmo iterativo que contiene el numero de personas qu tienen esa altura
//
//
// Aqui la justificación del coste de la función que resuelve el problema
// 
// El coste es lineal para el primer bucle que calcula los acumulados. O(M)-> siendo M el numero de personas
// Y el coste de la funcion resolver es lineal sobre el numero de alturas que hay. O (N)-> siendo N el numero de alturasMaximas
// Total implementacion O(N) + O(M)
//*******************************



// Aqui la función implementada por el alumno

// 
int resolver(std::vector<int> acum, int const& tamIntervalo) {

    int maxAcum = 0; 
    int acumulados= 0; 
    int pos= 0;
    
    // Primero marco el primer intervalo que quiero estudiar 
    
    for (int i = 0; i < tamIntervalo; ++i) {
        acumulados += acum[i]; 
        maxAcum = acumulados;
    }


    int primero = 0;
    // Ahora recorremos el resto del vector actualizando el max y acum
    for (int j = tamIntervalo; j < acum.size(); ++j) {

        // quito el primero que he leido
        acumulados -= acum[primero];

        // añadimos el nuevo que toca
        acumulados += acum[j]; 

        // actualizamos 
        if (acumulados > maxAcum) {
            maxAcum = acumulados;
        }
        primero++; // pasamos el siguiente

    }


    return maxAcum; 

}


std::vector<int> calcularAcum(std::vector<int>const& v, int const&numMedidas) {


    std::vector<int> sol(numMedidas, 0);
    for (int i = 0; i < v.size(); ++i) { 
        sol[v[i]-1]++; // incrementamos el contador de esa altura
    }

    return sol; 

}




bool resuelveCaso() {
    int numMedidas, medidaMax, longIntervalo;
    std::cin >> numMedidas >> medidaMax >> longIntervalo;
    if (numMedidas == -1) return false;
    std::vector<int> v(numMedidas);
    for (int& i : v) std::cin >> i;
    // LLamada a la funcion que resuelve el problema

    // Primer vector donde se calculan cuantas veces se repite una altura 
    // y lo deveulve cmo vector acumulados

    std::vector<int> acum = calcularAcum(v, medidaMax);

    //Ahora tenemos que aplicar la funcion que nos calcula el maximo de los intervalos que cumplen la condicion que nos dice

    int sol = resolver(acum, longIntervalo); 

    // Escribir el resultado

    std::cout << sol << '\n'; 
    return true;
}

int main() {
    // Para la entrada por fichero.
#ifndef DOMJUDGE
    std::ifstream in("1.in");
    auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

    while (resuelveCaso())
        ;

    // Para restablecer entrada. 
#ifndef DOMJUDGE // para dejar todo como estaba al principio
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif

    return 0;
}