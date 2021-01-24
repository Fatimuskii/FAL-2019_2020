// Nombre del alumno Fatima Garcia Delgado
// Usuario del Juez E24


#include <iostream>
#include <iomanip>
#include <fstream>

// Eliminar los digitos pares de un numero

// función que resuelve el problema
// devuelve el numero de digitos
// Final & No Final 

// NO FINAL 
long long int resolverNoFinal(long long int num) {

    // 1 digito
    //caso base
    if (num < 10) {
        if (num % 2 == 1) // es impar
            return num;
        else
            return 0; 
    }
    else {
        long long digito = num / 10; 
        if ((num % 10) % 2 == 1) { // es impar 
            return resolverNoFinal(digito)*10 + num%10; // lo que me llega + lo impar que es lo que me interesa
        }
        else
            return resolverNoFinal(digito);  
    }

}


// FINAL 
long long int resolverFinal(long long int num, long long int suma, int potencia) {

    // caso base
    if (num< 10) {
        if (num % 2 == 1) // es impar
            return (num*potencia) + suma;
        else
            return suma;
    }

    else {

        long long int digito = num / 10; // para hacer la recursion 
        if ((num % 10) % 2 == 1) // ultimo digito 
            return resolverFinal(digito,  (num%10)*potencia + suma, potencia*10);
        else
            return resolverFinal(digito, suma, potencia); 
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
    
    //long long int sol = resolverNoFinal(numero); // no final
    long long int sol= resolverFinal(numero, 0, 1); 

    // escribir sol
    std::cout << sol << '\n';

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