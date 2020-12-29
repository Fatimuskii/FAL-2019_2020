// Nombre del alumno Fatima García Delgado   
// Usuario del Juez E24


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

// Torres de colores.

// Colores disponibles: azul(0), rojo(1) y verde(2)
int const COLORES = 3;

struct tSol {
    bool haySol; 
    std::vector<int> v; 
};
//Condicion que comprueba que no se colocan dos piezas verdes seguidas. 
bool esValida(std::vector<int>piezasDisponibles, std::vector<int> contadorPiezasUsadas, tSol sol, int colorActual, int pos) {
    
    //No quedan piezas disponibles de la pieza que toca
    if (piezasDisponibles[colorActual] < 1)
        return false; 
    //Dos piezas verdes juntas
    if (colorActual == 2 && colorActual == sol.v[pos - 1])
        return false;
    // Numero de piezas verdes > piezas azules
    if (colorActual == 2 && contadorPiezasUsadas[2]+1 > contadorPiezasUsadas[0])
        return false;
    
    return true;
}


//Mostrar por pantalla la soluciobn
void escribirSolucion(std::vector<int> contadorPiezasUsadas, tSol &sol) {

    // Comprobar si numero de piezas rojas > suma (azules y verdes)
    if (contadorPiezasUsadas[1] > (contadorPiezasUsadas[0] + contadorPiezasUsadas[2])) {
        sol.haySol = true;
        for (int c : sol.v) {
            switch (c) {
            case 0:
                std::cout << "azul" << ' ';
                break;
            case 1:
                std::cout << "rojo" << ' ';
                break;
            case 2:
                std::cout << "verde" << ' ';
                break;
            }
        }
        std::cout << '\n';
    }
  
}

// función que resuelve el problema
void resolver(int altura, std::vector<int> piezasDisponibles, int k, std::vector<int> &contadorPiezasUsadas, tSol&sol) {

    for (int i = 0; i < COLORES; ++i) {
        //sol
        if (esValida(piezasDisponibles, contadorPiezasUsadas, sol, i, k)) {
            sol.v[k] = i;
            piezasDisponibles[i]--; 
            contadorPiezasUsadas[i]++;
            if (k == altura - 1) { // Es solucion (n: tam de la solucion)
                escribirSolucion(contadorPiezasUsadas, sol);
            }
            else { // seguimos construyendo la solucion 
                resolver(altura,piezasDisponibles, k + 1, contadorPiezasUsadas, sol);
            }
            piezasDisponibles[i]++;
            contadorPiezasUsadas[i]--;
        }
    }
    
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int altura;
    std::cin >> altura;
    if (altura == 0)
        return false;

    std::vector<int>piezasDisponibles(COLORES, -1);
    for (int i = 0; i < COLORES; ++i) {
        std::cin >> piezasDisponibles[i];
    }

    // Generar las soluciones
    tSol sol;
    std::vector<int>vector(altura, -1);
    sol.v = vector;
    
    std::vector<int> contadorPiezasUsadas(COLORES, 0); 

    // Primera pieza es siempre roja

    sol.v[0] = 1;
    sol.haySol = false;

    piezasDisponibles[1]--; 
    contadorPiezasUsadas[1]++;
    resolver(altura, piezasDisponibles, 1, contadorPiezasUsadas, sol);
 
    if (!sol.haySol)
        std::cout << "SIN SOLUCION\n";

    std::cout << '\n';
    return true;

}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("47Csample.in");
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