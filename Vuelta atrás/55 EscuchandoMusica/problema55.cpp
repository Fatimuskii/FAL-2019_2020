// Nombre del alumno Fatima Garcia Delgado
// Usuario del Juez E24


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <algorithm>

struct tDatos {
    int N; 
    int T1; 
    int T2; 
    std::vector<std::pair<int, int>>canciones;
};

class comparador {
public:
    // de mayor a menor (durancion/satis)
    bool operator ()(std::pair <int, int > cancion1, std::pair <int, int > cancion2) {
        return (float)cancion1.second / cancion1.first > (float)cancion2.second / cancion2.first;
    }
};

// función que resuelve el problema
int iniSatisfacionMejor(tDatos const& datos) {
    // tiempo de ida
    int i = 0; int sumaSatis = 0; int sumatiempoIda = 0; int sumatiempoVuelta= 0;//sumatorios
    while (i < datos.N && sumatiempoIda + datos.canciones[i].first <= datos.T1) {
        sumatiempoIda += datos.canciones[i].first;
        if(sumatiempoIda == datos.T1)
            sumaSatis += datos.canciones[i].second;
        ++i;
    }
    // tiempo de vuelta
  
    while (i < datos.N && sumatiempoVuelta + datos.canciones[i].first <= datos.T2) {
        sumatiempoVuelta += datos.canciones[i].first;
        if(sumatiempoVuelta ==datos.T2 )
            sumaSatis += datos.canciones[i].second;
        ++i;
    }


    return  sumatiempoIda == datos.T1 && sumatiempoVuelta == datos.T2 ? sumaSatis : 0;

}

void resolver(tDatos const& datos, int k, int tiempoIda, int tiempoVuelta, int satisAct, int& satisMejor) {

    // Cancion viajeIda
    tiempoIda += datos.canciones[k].first; 
    satisAct += datos.canciones[k].second;
    
    if (tiempoIda <= datos.T1) { // es valida
        if (k == datos.N - 1) { // es sol
            if (satisAct > satisMejor && tiempoIda == datos.T1 && tiempoVuelta == datos.T2) // sol mejor
                satisMejor = satisAct; 
        }
        else {
            resolver(datos, k + 1, tiempoIda, tiempoVuelta, satisAct, satisMejor); 
        }
    }
    // desmarco
    tiempoIda-= datos.canciones[k].first;
    //satisAct -= datos.canciones[k].second; No haria falta quitarla

    //Cancion viajeVuelta
    tiempoVuelta += datos.canciones[k].first;
    if (tiempoVuelta <= datos.T2 ) { // es valida
        if (k == datos.N - 1) { // es sol
            if (satisAct > satisMejor && tiempoIda == datos.T1 && tiempoVuelta == datos.T2) // sol mejor
                satisMejor = satisAct;
        }
        else {
            resolver(datos, k + 1, tiempoIda, tiempoVuelta, satisAct, satisMejor);
        }
    }

    //desmarco
    tiempoVuelta -= datos.canciones[k].first;
    satisAct -= datos.canciones[k].second;

    // Si no escojo la cancion
    if (k == datos.N - 1) {
        if (satisAct > satisMejor && tiempoIda == datos.T1 && tiempoVuelta == datos.T2) {
            satisMejor = satisAct;
        }
    }
    else {
        resolver(datos, k + 1, tiempoIda, tiempoVuelta, satisAct, satisMejor);
    }

}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int N, T1, T2; // numCanciones, t1 tiempo de ida, t2 tiempo de vuelta
    std::cin >> N >> T1 >> T2; 
    if (N == 0 && T1 ==0 && T2 ==0)
        return false;

    std::vector< std::pair<int, int>> canciones(N); // <duracion, gradoSatisfaccion>
   
    for (int i = 0; i < N; ++i) {
        std::cin >> canciones[i].first >> canciones[i].second; 
    }
    //ordenamos los datos por superficie/coste de cada adorno de mayor a menor
    std::sort(canciones.begin(), canciones.end(), comparador());

    tDatos datos = { N, T1, T2, canciones };

    int maxSatisfaccion = iniSatisfacionMejor(datos);
    //std::vector<bool> sol(N);

    //datos, int k, int tiempoIda, int tiempoVuelta, int satisAct, int& satisMejor)
    resolver(datos, 0, 0, 0,0, maxSatisfaccion);
  
    // escribir sol
    if (maxSatisfaccion > 0)
        std::cout << maxSatisfaccion << '\n';
    else
        std::cout << "Imposible\n"; 

    return true;

}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("55sample.in");
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