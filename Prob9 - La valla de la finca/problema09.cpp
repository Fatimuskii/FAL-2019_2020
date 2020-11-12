// Nombre del alumno Fatima Garcia Delgado
// Usuario del Juez E24


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
/* Como el problema debe devolver el max del intervalo desde la izq, empezamos a recorrer el vector por la izq. 
Primero marcamos el intervalo primero, poniendo las variables actualizadas si se cumple la condicion (en este caso, que haya 0s y a en caso de haberlos marcar el posIni como la posible sol

El coste de este algoritmo es lineal, al recorrer el vector una unica vez. O(N) siendo N el numero de elementos del vector*/

// función que resuelve el problema
int resolver(std::vector<int> const&v, int const&metrosTela) {
    int maxCont = 0;
    int cont = 0; // contador del tamaño que vamos usando de la tela metalica
    int posIni = -1; 
    for (int i =v.size()-metrosTela; i < v.size(); ++i) { // Miramos el primer posible intervalo desde la izquierda
        if (v[i] == 0) {
            cont++;// contamos los 0 que haya en el intervalo   
        }       
    }
    // Estuadiamos el primer intervalo que hemos recorrido
    // Si tiene ceros tenemos que marcar este intervalo como posible solucion 
    if (cont > 0) {
        posIni = v.size() - metrosTela;
        maxCont = cont;
    }
    
    int ultimoValor = v.size() - 1;
    //Bucle ppal->  recorremos el resto del vector que nos queda
    for (int j = v.size()-metrosTela-1; j > -1; --j) {
        //Si el ultimo valor ha sido un 0 tenemos que quitarlo
        if (v[ultimoValor] == 0) cont--;
        //Miramos el valor actual, si es 0 incrementamos el cont
        if (v[j] == 0) cont++;

        // Actualizamos los valores que tenemos ahora
        if (cont > maxCont ) {
            maxCont = cont;
            posIni = j;
        }

        // actualizamos el ultimo para la siguiente iteracion
        ultimoValor--;
        

    }

    return posIni;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int num,metrosValla, metrosTela; 
    std::cin >> metrosValla >> metrosTela;
    if (metrosValla == 0)
        return false;

    std::vector<int> vector; 
    for (int i = 0; i < metrosValla; ++i) {
        std::cin >> num; 
        vector.push_back(num);
    }
    
    int sol = resolver(vector, metrosTela);

    // escribir sol
    if (sol!=-1 )
        std::cout << sol<< '\n';
    else
        std::cout << "No hace falta\n";

    return true;

}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("09sample.in");
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
