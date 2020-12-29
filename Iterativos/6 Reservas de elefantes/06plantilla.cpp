
// Nombre y apellidos del estudiante Fatima Garcia Delgado  
// Usuario del juez E24

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <cmath>
#include <iomanip>

using lli = long long int;

// Calcula un vector con los valores acumulados
void resolver(std::vector<int> const& a, std::vector<lli>& v)
{
    // Aqui codigo del estudiante
    lli acum = a[0];
    v.push_back(a[0]);
    for (int i = 1; i < a.size(); ++i) {
        acum += a[i];
        v.push_back(acum);
    }

}
// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // Lee las dos fechas entre las que tenemos datos
    int a1, a2;
    std::cin >> a1 >> a2;
    if (a1 == 0 && a2 == 0) return false;

    // Lee el resto de los datos y calcula el vector de acumulados
    int years = a2 - a1 + 1;
    std::vector<int> nacimientos; 
    int value;
    for (int i = 0; i < years; ++i) {
        std::cin >> value;
        nacimientos.push_back(value);
    }
    // Aqui código del estudiante
   
    std::vector<lli> acumulados;
    resolver(nacimientos, acumulados);

    // Lectura de las preguntas
    int m; std::cin >> m;
    for (int i = 0; i < m; ++i) {
        int f1, f2;
        std::cin >> f1 >> f2;
        // Escribir la respuesta
        // Aqui codigo del estudiante
        int j = f1 - a1;
        int k = f2 - a1;
        lli sol = acumulados[k] - acumulados[j] + nacimientos[j];
        std::cout << sol << '\n';
    }
    std::cout << "---\n";

    return true;
    
}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
    
#ifndef DOMJUDGE
    std::ifstream in("06sample.in");
    auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif

    
    while (resuelveCaso())
        ;
    
    
#ifndef DOMJUDGE // para dejar todo como estaba al principio
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif

    return 0;
}



