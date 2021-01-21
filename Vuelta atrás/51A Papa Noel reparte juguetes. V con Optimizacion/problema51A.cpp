// Nombre del alumno Fatima Irene Garcia Delgado
// Usuario del Juez E24

// Papa Noel reparte juguetes. Versión con optimizacion 
#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

using Matriz = std::vector<std::vector<int>>;

// Datos de entrada
struct tDatos {
    int numJuguetes, numNinos;
    Matriz matriz;
};

// función que resuelve el problema
void resolver(tDatos const& datos, int k, std::vector <int> &sol, int &sumaSatis, std::vector<bool>& asignados, int& satisMejor,std::vector<int>const& acum) {

    for (int i = 0; i < datos.numJuguetes; ++i) {
        sol[k] = i;
        if (!asignados[i]) { // juguete no asignado (false)

            //marcaje
            asignados[i] = true;
            sumaSatis += datos.matriz[k][i];
           
            if (k == sol.size() - 1) { // es solucion
                if (sumaSatis > satisMejor) satisMejor = sumaSatis; // solucion mejor
            }
            else { // No es solucion
                if (sumaSatis + acum[k + 1] > satisMejor) // Estimacion
                    resolver(datos, k + 1, sol,sumaSatis, asignados, satisMejor, acum);
            }
            //desmarcaje
            sumaSatis -= datos.matriz[k][i];
            asignados[i] = false;
            
        }
    }
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int M, N; // m: num Juguetes | n num niñxs | s: min satisfaccion 
    std::cin >> M >> N;
    if (!std::cin)
        return false;

    Matriz matriz(N, std::vector<int>(M));
   
    // Lee la satisfaccion que les proporcionan los juguetes a los ninnos
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            std::cin >> matriz[i][j];
        }
    }

 
    // Calcula el vector de maximos
   
    std::vector <int > acum(N);
    for (int i = 0; i < N; ++i) {
        int auxMax = matriz[i][0];
        for (int j = 1; j < M; ++j) {
            if (auxMax <matriz[i][j]) {
                auxMax =matriz[i][j];
            }
                acum[i] = auxMax;
        }         
    }
    // Vector acumulados
    for (int i = acum.size()-1; i > 0; --i) {
        acum[i-1] += acum[i];
    }

    // Obtiene una inicializacion posible para la solucion mejor
    int satisMejor = 0;
    for (int i = 0; i < N; ++i) {
        satisMejor +=matriz[i][i];
    }

    // Prepara los datos de la funcion
    tDatos datos;
    datos.numJuguetes = M;
    datos.numNinos = N;
    datos.matriz = matriz;
    std::vector <int > sol(N);
    int sumaSatis = 0;
    std::vector<bool> asignados(M, false);
    resolver(datos, 0,sol ,sumaSatis, asignados, satisMejor, acum);
    std::cout << satisMejor << '\n';
    return true;

}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("51Asample.in");
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