// Nombre del alumno Fatima Irene Garcia Delgado
// Usuario del Juez E24

// Papa Noel reparte juguetes. Versión simplificada
#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>


void tratarSolucion(const std::vector<int>& v) {
    for (int i = 0; i < v.size(); ++i) {
        std::cout << v[i];
        if (i== v.size()-1)
            std::cout << '\n';
        else
            std::cout << " ";
    }

}

bool esValida( std::vector<int>const& sol, int& k, int i, std::vector<std::string>const&v) {

    //Comprobar primero que el segundo jueguete del jugador que le toque no sea el mismo q el primer juguete
    if (k > 0 && k % 2 != 0 && (v[sol[k]] == v[sol[k - 1]])) return false; 

    //Comprobar que no podemos tener jueguete1 y jueguete0 (ya que tendríamos ya juguete0 y 1)
    if (k > 0 && k % 2 != 0 && v[sol[k - 1]] > v[sol[k]]) return false;

    return true; 

}
// función que resuelve el problema
void resolver(int k, std::vector<std::string> const& v,bool &haySol, std::vector<int> &sol) {

    for (int i = 0; i < v.size(); ++i) {
        sol[k] = i; 
        if (esValida(sol, k, i, v)) {

            if (k == sol.size() - 1) {
                tratarSolucion(sol);
                haySol = true;
            }

            else {
                resolver(k + 1, v, haySol, sol);
            }

        }
    }

}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int m, n; // m: num Juguetes | n num niñxs
    std::cin >> m >> n; 
    if (!std::cin)
        return false;

    std::vector<std::string> juguetes(m); 
    
    for (int i = 0; i < m; ++i) {
        std::cin >> juguetes[i]; 
    }

    std::vector<int> sol(n*2, -1);
    bool haySol = false;

    resolver(0, juguetes, haySol, sol);
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
    std::ifstream in("50Asample.in");
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