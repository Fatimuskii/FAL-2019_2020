// Nombre del alumno  Fatima Garcia Delgado 
// Usuario del Juez E24


// Degrado de una imagen
#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>



struct tFila {
    bool degradado;
    int suma;
};

// función que resuelve el problema
// Recorre cada fila (tratandola como un vector
tFila resolver(std::vector<int>const& v, int ini, int fin) {

    if (ini + 1 == fin) // 1 elemento es valido, 2^0=1
        return { true,v[ini] };

    else {

        int mitad = (ini + fin) / 2;
        tFila sIzq = resolver(v,ini, mitad);
        tFila sDer = resolver(v,mitad, fin);

        tFila sol;
        sol.suma = sIzq.suma + sDer.suma;
        sol.degradado = sIzq.degradado && sDer.degradado && sIzq.suma < sDer.suma;

        return  sol;
    }


}


// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada

    int N, M, num; // N: filas, M: columnas
    std::cin >> N >> M;
    if (!std::cin)
        return false;

    std::vector<int>v; // guardamos en un mismo vector toda la matriz

    for (int j = 0; j < N * M; ++j) {
        std::cin >> num;
        v.push_back(num);
    }

    // recorremos toda la matriz analizando cada fila
    // v[0] - v[M-1]
    bool noDegradada = false;
    tFila fila;

    int i = 0;
    int ini = 0;
    int fin = M;
    while (i < N && !noDegradada) {

        fila = resolver(v,ini, fin);

        if (!fila.degradado) {
            noDegradada = true;
        }
        ini = fin;
        fin += M;
        i++;
    }

    // escribir sol
    // escribir salida
    if (!noDegradada)
        std::cout << "SI\n";
    else
        std::cout << "NO\n";

    return true;

}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("36sample.in");
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