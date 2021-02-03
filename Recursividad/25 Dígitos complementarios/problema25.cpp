// Nombre del alumno Fatima Garcia Delgado
// Usuario del Juez E24


#include <iostream>
#include <iomanip>
#include <fstream>

// Eliminar los digitos pares de un numero

// función que resuelve el problema
// devuelve el numero de digitos
// Final & No Final 

// FINAL 
int resolverFinal(int num,int suma, int potencia) {
    // caso base
    if (num < 10) {
        return (9 - num) * potencia + suma;

    }

    else {
        int digito = num / 10; // para hacer la recursion 
        return resolverFinal(digito, (9 - (num % 10)) * potencia + suma, potencia * 10);

    }

}

// NO FINAL 
int resolverNoFinal(int num) {

    // 1 digito
    if (num < 10) {
        return 9 - num; 
    }
    // resto de casos 
    else {
        int digito = num / 10;
        return resolverNoFinal(digito) * 10 + (9- num % 10); // lo que me llega + lo impar que es lo que me interesa
       
    }

}

int invertir(int numero, int res) {
   if (res == 0 && numero < 10) 
        return 9- numero;
   
    else if (numero == 0)
       return res;

    else 
        return invertir(numero / 10,res*10 + (9 - (numero % 10)));
      
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada

     int numero;
    std::cin >> numero;

    int sol = resolverNoFinal(numero); // no final

    //long long int sol = resolverFinal(numero, 0, 1);
    
    auto inv = invertir(numero, 0); 
    // escribir sol
    std::cout << sol <<" " << inv << '\n';

    return true;


}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("25sample.in");
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