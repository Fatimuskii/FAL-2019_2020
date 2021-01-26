// Nombre del alumno Fatima Irene Garcia Delgado
// Usuario del Juez E24

// Adornando la casa por navidad con estimacion

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <algorithm>

struct tDatos {
    int N;
    int P;
    std::vector<std::pair<int, int>>adornos;
};
// función que resuelve el problema
class comparador {
public:
    // de mayor a menor (superficie/coste)
    bool operator ()(std::pair <int, int > objeto1, std::pair <int, int > objeto2) {
        return (float)objeto1.second / objeto1.first > (float)objeto2.second / objeto2.first;
    }
};

//Funcion para poder inicializar la mejor solucion y asi poder ahcer mejor una poda de las soluciones "malas" 
int iniSuperficieMejor(tDatos const& datos) {

    int i = 0; int sumaSuperficie = 0; int sumaCoste = 0; //sumatorios
    while (i < datos.N && sumaCoste + datos.adornos[i].first <= datos.P) {
        sumaCoste += datos.adornos[i].first;
        sumaSuperficie += datos.adornos[i].second;
        ++i;
    }
    return sumaSuperficie;
}

// Se estima a partir del adorno en el que estamos para estimar la mayor superficie
float estimacion(tDatos const& datos, int costeActual, int k) {
    int i = k+1; 
    int sumaCoste = costeActual; 
    int sumaSuperf = 0;
    
    // estimacion como tal 
    while (i < datos.N && sumaCoste + datos.adornos[i].first <= datos.P) {
        sumaCoste += datos.adornos[i].first;
        sumaSuperf += datos.adornos[i].second;
        ++i;
    }

    // La parte que queda sin completar
    // cogemos la parte proporcional. 
    if (i < datos.N && sumaCoste < datos.P) {
        float rest = datos.P - sumaCoste; 
        sumaSuperf += datos.adornos[i].second * (rest/(float)datos.adornos[i].first) ;
    }
     
    return sumaSuperf;

}
void resolver(tDatos const& datos, int k, std::vector<bool>& sol, int superficie, int coste, int& superficieMejor, int& costeMejor) {

    // Cojo el objeto 
    sol[k] = true;
    //marcaje
    coste += datos.adornos[k].first;
    superficie += datos.adornos[k].second;

    if (coste <= datos.P) { // es valida
        if (k == datos.N - 1) { //es solucion
            if (superficie > superficieMejor) { // Solucion mejor
                superficieMejor = superficie;
            }
        }
        else
            resolver(datos, k + 1, sol, superficie, coste, superficieMejor, costeMejor);
    }
    //desmarcaje
    coste -= datos.adornos[k].first;
    superficie -= datos.adornos[k].second;

    //No cojo el objeto
    sol[k] = false;
    if (k == datos.N - 1) {
        if (superficie > superficieMejor) { // Solucion mejor
            superficieMejor = superficie;
        }
    }
    else {
        if ((estimacion(datos, coste, k) + superficie) > superficieMejor) {
            resolver(datos, k + 1, sol, superficie, coste, superficieMejor, costeMejor);
        }
    }
       
        

}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int N, P; //N: num objetos || P: presupuesto 
    std::cin >> N >> P;

    if (!std::cin)
        return false;

    std::vector<std::pair<int, int>>adornos(N);

    for (int i = 0; i < N; ++i) {
        std::cin >> adornos[i].first >> adornos[i].second;
    }

    //ordenamos los datos por superficie/coste de cada adorno de mayor a menor
    std::sort(adornos.begin(), adornos.end(), comparador());

    tDatos datos = { N, P, adornos };
    //Inicializar la solucion mejor antes de llamar a la funcion recursiva
    int minCoste = 0;
    int maxSuperficie = iniSuperficieMejor(datos);
    std::vector<bool> sol(N);


    resolver(datos, 0, sol, 0, 0, maxSuperficie, minCoste);

    // escribir sol
    std::cout << maxSuperficie << '\n';

    return true;

}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("54Asample.in");
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