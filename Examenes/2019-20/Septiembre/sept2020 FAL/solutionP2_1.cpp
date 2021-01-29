// Examen convocatoria extraordinaria
// Septiembre 2020

// segundo problema

#include <iostream>
#include <fstream>
#include <vector>

// Coste del algoritmo
// Se trata de un algoritmo recursivo. Escribimos su recurrencia
// En cada llamada recursiva se realiza una única llamada recursiva. 
// Si n es el valor del número
// T(n) = c_0 si n < 10
// T(n) = T(n/10) + c_1 si n >= 10
// El resultado de esta recurrencia (ver el desplegado en los apuntes) es O(log n), siendo n el valor de entrada

// si n es el número de dígitos del número de entrada la recurrencia es
// T(n) = c_0 si n < 10
// T(n) = T(n-1) + c_1 si n >= 10
// El resultado de esta recurrencia en O(n) siendo n el número de dígitos

// Explicación del algoritmo
// Se comprueba la propiedad para todos los dígitos del número empezando por el dígito de menor peso (derecha)
// En cada llamada el numero se divide por 10 para comprobar el siguiente dígito
// El parametro sumaDerecha lleva la suma de los dígitos de la parte que ya se ha tratado del número (parte derecha). Cada llamada recibe el valor de la suma de la parte derecha del número original.
// La suma de la parte izquierda del número se devuelve como resultado de la función. Cuando termina una llamada recursiva, el valor de retorno sumaIzquierda lleva la suma de los dígitos que quedan a la izquierda del dígito que se está tratando en esa llamada. 

struct tSolRec {
    bool interes;
    int sumaIzquierda;
};

tSolRec interesante (int num, int sumaDerecha) {
    int digito = num%10;
    if (digito == 0) return {false, 0}; // Si el numero tiene un digito 0 no es interesante
    else if (num < 10) { // caso base, un digito
        if (sumaDerecha%num==0) return {true,num}; 
        else return {false, 0};
    }
    else { // caso recursivo
        // Comprueba propiedad derecha
        if (sumaDerecha%digito != 0) return {false,0};
        else {
            // En la llamada se incrementa la suma derecha
            tSolRec s = interesante(num/10, sumaDerecha + digito);
            if (!s.interes) return {false, 0};
            // Comprueba propiedad izquierda
            else if (s.sumaIzquierda % digito != 0) return {false, 0};
            else return {true, s.sumaIzquierda + digito}; // Se incrementa la suma izquierda
        }
    }
    
}
void resuelveCaso() {
    int num; std::cin >> num;
    if (interesante(num, 0).interes) std::cout << "SI\n";
    else std::cout << "NO\n";
    
}



int main() {

    
#ifndef DOMJUDGE
    std::ifstream in("ej2sample.in");
    auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
    #endif
 
    int numCasos; std::cin >> numCasos; std::cin.ignore();
    for (int i = 0; i < numCasos; ++i) 
        resuelveCaso();

    
#ifndef DOMJUDGE // para dejar todo como estaba al principio
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif
    
    return 0;
}
