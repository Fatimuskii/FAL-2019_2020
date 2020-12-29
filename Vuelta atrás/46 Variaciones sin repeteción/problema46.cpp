// Nombre del alumno Fatima Garíc Delgado   
// Usuario del Juez E24


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

// Variaciones sin repetición 

//Mostrar por pantalla la soluciobn
void escribirSolucion(std::vector<char> const& v) {
    for (char c : v)
        std::cout << c;
    std::cout << '\n';
}

// función que resuelve el problema
void resolver(int m, int n, int k, std::vector<bool>&marcas, std::vector<char>& sol) {

    for (char i = 'a'; i < 'a' + m; ++i) {
        //sol
        sol[k] = i;
        
        if (!marcas[i - 'a']) { // Si la letra no se ha usado
            //marcamos como usada
            marcas[i - 'a'] = true; 
            if (k == n - 1) { // Es solucion (n: tam de la solucion)
                escribirSolucion(sol);
            }
            else { // seguimos construyendo la solucion 
                resolver(m, n, k + 1, marcas, sol);
            }
            // desmarcamos para seguir viendo mas soluciones
            marcas[i - 'a'] = false;

        }

       
    }


}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int m, n;
    std::cin >> m >> n;
    if (!std::cin)
        return false;

    // Generar las soluciones
    std::vector<char>sol(n);
    // Marcaje para saber si se ha usado ya o no
    std::vector<bool>marcas(m, false);

    resolver(m, n, 0, marcas, sol);
    std::cout << '\n';
    return true;

}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("46sample.in");
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