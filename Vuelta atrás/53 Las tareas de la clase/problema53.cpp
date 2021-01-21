// Nombre del alumno Fatima Irene Garcia Delgado
// Usuario del Juez E24

// Tareas de Clase
#include <iostream>
#include <vector>
#include <fstream>

using Matriz = std::vector<std::vector<int>>;

struct tDatos {
    int N;
    int A;
    int maxT;
    Matriz matriz; 
};

bool esValida(tDatos const& datos, std::vector<int>& marcas, std::vector<int>& sol, int const& k, int const& alumnoAct) {
    
    // El alumno que le toca no tenga mas de las t puestos 
    if (marcas[alumnoAct] >= datos.maxT) return false;

    // Que el alumno no tenga las mismas tareas
    if (k > 0 && k % 2 != 0 && sol[k - 1] == sol[k]) return false;

    return true;

}
void resolver(tDatos const& datos, int k, std::vector<int>& marcas, std::vector<int>& sol,int& satAcum, int& mejorSat) {

    for (int i = 0; i < datos.A; ++i) {
        sol[k] = i;
        satAcum += datos.matriz[i][k / 2];
        if (esValida(datos,marcas,sol, k, i)) {
            if (k == sol.size()-1) { //Es solucion
                if (satAcum > mejorSat) { //Es mejor solucion
                    mejorSat = satAcum;
                }
            }
            else {
                ++marcas[i];
                resolver(datos, k+1, marcas, sol, satAcum, mejorSat);
                --marcas[i];
            }
        }
        satAcum -= datos.matriz[i][k / 2];
      
    }

}

bool resuelveCaso() {
    int N, A, maxT; // n: numTaresas || a: numAlumnos || t: numMaxTareasPorAlumno
    std::cin >> N >> A >> maxT;

    if (N == 0 && A == 0 && maxT == 0) 
        return false;

    Matriz matriz(A, std::vector<int>(N));

    for (int f = 0; f < A; ++f) {
        for (int c = 0; c < N; ++c)
            std::cin >> matriz[f][c];
    }

    tDatos datos = { N, A, maxT, matriz }; 
    std::vector<int> sol(N * 2, -1); // vector sol
    std::vector<int> marcas(A, 0); // contador de los trabajos de cada alumno
    int mejorSat = 0;
    int satAcum = 0; 
    resolver(datos,0, marcas, sol, satAcum, mejorSat);
    std::cout << mejorSat << '\n';
    return true;
}

int main() {

    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("53sample.in");
    auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif

    while (resuelveCaso());

    // Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
    std::cin.rdbuf(cinbuf);
    //system("PAUSE");
#endif

}
