// Nombre del alumno Fatima Irene Garcia Delgado
// Usuario del Juez E24

// Papa Noel reparte juguetes. Versión simplificada
#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

using Matriz = std::vector<std::vector<int>>;

struct tJuguete {
    int ud; 
    std::string tipo; 
};
void tratarSolucion(const std::vector<int>& v) {
    for (int i = 0; i < v.size(); ++i) {
        std::cout << v[i];
        if (i == v.size() - 1)
            std::cout << '\n';
        else
            std::cout << " ";
    }

}

bool esValida(std::vector<int>const& sol, int& k, Matriz const& matriz, int jAct, std::vector<tJuguete>const& juguetes, int const&SAT) { 
    //int niñoActu = k / 2;
    //int numJuguete = k%2; // == 0 (juguete1) || ==1 (juguete2)

    // Comprobar unidades disponibles
    if (juguetes[jAct].ud < 0) return false; 

    //Comprobar primero que el segundo jueguete del jugador que le toque no sea el mismo tipo q el primer juguete
    if (k > 0 && k % 2 != 0 && (juguetes[jAct].tipo == juguetes[sol[k-1]].tipo)) return false;

    //Comprobar que no podemos tener jueguete1 y jueguete0 (ya que tendríamos ya juguete0 y 1)
    if (k > 0 && k % 2 != 0 && sol[k - 1] > sol[k]) return false;

    //Comprobar el grado de Satis
    if (k > 0 && k % 2 != 0 && matriz[k / 2][sol[k]] + matriz[k / 2][sol[k - 1]] < SAT) return false;

    return true;

}
// función que resuelve el problema
void resolver(int const&S, int k, std::vector<tJuguete>& juguetes, Matriz const& matriz, bool& haySol, std::vector<int>& sol) {

    for (int jugAct = 0; jugAct < juguetes.size(); ++jugAct) {
        sol[k] = jugAct;
        //marcaje
        juguetes[jugAct].ud--;

        if (esValida(sol, k, matriz, jugAct, juguetes, S)) {
            if (k == sol.size() - 1) {
                tratarSolucion(sol);
                haySol = true;
            }else {
                resolver(S, k + 1, juguetes, matriz,haySol, sol);
            }
        }
        //desmarcaje
        juguetes[jugAct].ud++;
    }

}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int M, N, S; // m: num Juguetes | n num niñxs | s: min satisfaccion 
    std::cin >> M >> N >> S;
    if (!std::cin)
        return false;

    std::vector<tJuguete> juguetes(M);

    for (int i = 0; i < M; ++i) {
        std::cin >> juguetes[i].ud;
    }
    for (int i = 0; i < M; ++i) {
        std::cin >> juguetes[i].tipo;
    }

    Matriz matriz(N, std::vector<int>(M));

    for (int fila = 0; fila < N; ++fila) {
        for (int col = 0; col < M; ++col) {
            std::cin >> matriz[fila][col];
        }
    }
        

    std::vector<int> sol(N * 2, -1);
    bool haySol = false;

    resolver(S, 0, juguetes,matriz, haySol, sol);
    // escribir sol
    if (!haySol)
        std::cout << "SIN SOLUCION" << '\n';
    std::cout << '\n';

    return true;

}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("50Bsample.in");
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