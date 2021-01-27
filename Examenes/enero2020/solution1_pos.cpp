// Examen enero 2020 FAL. Grupos E, F, I
// Ejercicio 1
// Solución de Isabel Pita

#include <iostream>
#include <fstream>
#include <vector>


struct tSol {
    int lonEscalera; // Numero de elementos que forman escalera
    int tamEscalon;  // Longitud del escalon más ancho de la escalera
};

// Calcula la escalera de la parte izquierda. 
// Coste O(n) siendo n el número de elementos del vector
// La función tiene un solo bucle que se ejecuta como máximo n veces, cuando el 
// vector tiene forma de escalera con un tramo ascendente que cubre todo el vector.
// El coste de ejecutar cada vuelta del bucle es constante, ya que sólo hay instrucciones
// condicionales (cuya condición tiene coste constante) e instrucciones de asignación 
// de coste constante
tSol ascenderIzda (std::vector<int> const& v){
    int maxi = 1; // Longitud del escalon maximo
    int tamEscalon = 1; // Longitud del escalon actual
    int i;  // se recorre de izda a derecha
    for (i = 1; i < v.size() && v[i-1] <= v[i]; ++i){ // mientras sea escalera
        if (v[i-1] < v[i]) { // nuevo escalon
            tamEscalon = 1;
        }
        else { // continua el escalon
            ++tamEscalon;
            maxi = (tamEscalon > maxi)?tamEscalon:maxi;
        }
    }
    return {i,maxi};
}

// Calcula la escalera de la parte derecha
// Igual que la función anterior. El caso peor se tiene cuando el tramo descendente de 
// la escalera ocupa todo el vector
tSol ascenderDrcha (std::vector<int> const& v){
    int maxi = 1; // Longitud del escalon maximo
    int tamEscalon = 1; // Longitud del escalon actual
    int i; // Se recorre de derecha a izda
    for (i = (int)v.size()-1; i > 0 && v[i] <= v[i-1]; --i){ // mientras sea escalera
        if (v[i-1] > v[i]) { // nuevo escalon
            tamEscalon = 1;
        }
        else { // continua el escalon
            ++tamEscalon;
            maxi = (tamEscalon > maxi)?tamEscalon:maxi;
        }
    }
    return {v.size()-i,maxi};
}

// El coste de comprobar si el vector es escalera es la suma del coste de las llamadas a
// las funciones O(n), siendo n el número de elementos del vector, más un coste constante 
// de calcular si los dos tramos forman una escalera más el coste constante de calcular
// el máximo de dos valores. 
bool resuelveCaso () {
    int nElems; 
    std::cin >> nElems;
    if (nElems == -1) return false;
    std::vector<int> v(nElems);
    for (int &i : v) std::cin >> i;
    // LLamadas a las funciones
    tSol solIzda = ascenderIzda(v);
    tSol solDrcha = ascenderDrcha(v);
    // resultados
    if (solIzda.lonEscalera + solDrcha.lonEscalera > v.size()) 
            std::cout << "SI "<< std::max(solIzda.tamEscalon,solDrcha.tamEscalon) << '\n';
    else std::cout << "NO " << solIzda.lonEscalera  << ' ' <<  solDrcha.lonEscalera << '\n';
    return true;
}

int main() {
 #ifndef DOMJUDGE
    std::ifstream in("sample1.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif

    while (resuelveCaso());

#ifndef DOMJUDGE // para dejar todo como estaba al principio
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif
 
    return 0;
}
