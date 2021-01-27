// Examen FAL enero 2020, grupos E,F,I
// Ejercicio 2
// Solución Isabel Pita

#include <iostream>
#include <fstream>
#include <vector>

// Funcion recursiva que resuelve el problema con la técnica divide y vencerás.
// Caso recursivo
// Se compara el valor de la posición de la mitad (m) con el valor de la posición de la mitad menos el ancho del escalon que nos dan (izda). El valor de la posición izda es imposible que sea igual que el valor de la posición m, por la definición del escalón más ancho. 
//       Si el valor de la posición izda es mayor que el valor de la mitad es que estamos decreciendo y por lo tanto el máximo esta en la parte izquierda [ini..m]. Hay que tener en cuenta que el escalón en que se encuentra la mitad no tiene porque ser el más ancho y por lo tanto no sabemos lo que puede haber entre izda y m. Puede ocurrir que el máximo esté antes de izda o entre izda y m (desde izda sube un poco y luego ya baja hasta m)
// Se compara el valor e la posición de la mitad (m) con el valor de la posición de la mitad mas el ancho del escalon que nos dan (drcha). El valor de la posición drcha es imposible que sea igual que el valor de la posición m, por la definición del escalón más ancho. 
//       Si el valor de la posición drcha es mayor que el valor de la mitad es que estamos creciendo y por lo tanto el máximo esta en la parte derecha [m..fin]. Hay que tener en cuenta que el escalón en que se encuentra la mitad no tiene porque ser el más ancho y por lo tanto no sabemos lo que puede haber entre m y drcha. Puede ocurrir que el máximo esté despues de drcha o entre m y drcha (desde m sube mucho y luego baja  un poco hasta drcha)
// En otro caso, v[m] es mayor que v[izda] y que v[drcha] por lo tanto el maximo está entre v[izda] y v[drcha]
// El número de elementos del intervalo [izda.. drcha] es 2 * ancho escalon. Podemos considerar esto como caso base y buscar aqui el máximo de forma secuencial
// Con esta solución el coste del algoritmo viene dado por la recurrencia (n = numero de elementos del vector, a = ancho del escalón)
// T(n) = 2*a si n == fin - ini <= 2*a
// T(n) = T(n/2) + c si n == fin - ini > 2*a
// Desplegado
// T(n) = T(n/2) + c = T(n/4) + c + c = T(n/8) + c+ c+ c = .... T(n/2^k) + kc =....
// Se alcanza el caso base cuando k = log(n) - log(2a) = ... = T(2a) + (log(n) - log(2a))c = 2a  + (log(n)- log(2a)) c. 
// El desplegado lo podéis consultar en el cuaderno de problemas de la asignatura.
// Coste final del algoritmo O(a + log(n)) = O(max(a,log(n))

int resolver(std::vector<int> const& v, int tamEscalon, int ini, int fin) {
    if (fin - ini <= 2 * tamEscalon) { //caso base, calcula el máximo del intervalo
        int maxi = v[ini]; 
        for (int i = ini + 1; i < fin; ++i)
            if (v[i] > maxi) maxi = v[i];
        return maxi;
    }
    else { // caso recursivo
        int m = (ini + fin) / 2;
        int izda = std::max(0,m-tamEscalon);
        int drcha = std::min((int)v.size() - 1, m+tamEscalon);
        if (v[izda] > v[m]) // ir a la izquierda
            return resolver(v,tamEscalon,ini,m);
        else if (v[drcha] > v[m]) return resolver(v,tamEscalon,m,fin); // ir a la derecha
        else return resolver(v,tamEscalon, izda + 1, drcha); // LLamada con tamaño 2*a
    }
}

bool resuelveCaso () {
    // Lectura de datos
    int nElems; int tamMax;
    std::cin >> nElems;
    if (nElems == -1) return false;
    std::cin >> tamMax;
    std::vector<int> v(nElems);
    for (int &i : v) std::cin >> i;
    // LLamada a la función que resuelve el problema
    int altura = resolver(v,tamMax,0,(int)v.size());
    // Escribir el resultado
    std::cout << altura << '\n';
    return true;
}


int main() {
    
     #ifndef DOMJUDGE
     std::ifstream in("sample2.txt");
     auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
     #endif
     
    while (resuelveCaso());
    
     #ifndef DOMJUDGE // para dejar todo como estaba al principio
     std::cin.rdbuf(cinbuf);
     system("PAUSE");
     #endif
      
    return 0;
}
