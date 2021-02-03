// Nombre del alumno Fatima Garcia Delgado
// Usuario del Juez E24
// Link al video : https://youtu.be/y90clPcrnC4
// Notas: sample1.in contiene casos pequeños
// Sample2.in contiene datos mas grandes

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <algorithm>
#include <ctime> // para mostrar el tiempo de ejecucion del programa

/*  - El problema se resuelve con la técnica de VA con un árbol de soluciones binario.
    - En la solucion  obtendremos las calles de las cuales quitaremos la sal. Para resolverlo utilizaremos un vector sol de dim Num de calles
        y en cada etapa marcamos si quitamos sal de esa calle o no.
    - El arbol de soluciones es binario:


                            .
                /                         \
           (limpiamos)             (No limpiamos)
              /                             \
              .                              .
       (si) /    \(No)              (si)  /      \ (No)
            .     .                      .        .
          /   \  / \                    / \      / \

    - Se trata de un problema de optimizacion, donde tenemos que maximizar los metro de calle que se limpian.
    - Vamos guardando la solucion mejor a medida que vamos recorriendo el arbol, y en el momento que encontramos una sol mejor, la actualizamos/cambiamos.
    - Inicializamos la solucion mejor antes de llamar a la solucion recursiva. Esto nos permitirá podar más el arbol de soluciones.
    - En este problema la solucion válida debe cumplir que no nos pasemos del maximo de sal que tenemos disponible, y cubrir un min de vecinos en total.

 */
struct tDatos {
    int C; // numero de calles
    int cSal; // Cantidad de sal que tenemos
    int mPersonas; // minimo total de personas que tenemos que satifacer

};

struct tCalle {
    int id; // numero de la calle inicial
    int longitud;
    int cantidadSal;
    int numVecinos;
};

// función que resuelve el problema
class comparador {
public:
    // de mayor a menor (longCalle/cantidadSal)
    bool operator ()(tCalle const& calle1, tCalle const& calle2) {
        return (float)calle1.longitud / calle1.cantidadSal > (float)calle2.longitud / calle2.cantidadSal;
    }
};


//Funcion para poder inicializar la mejor solucion y asi poder ahcer mejor una poda de las soluciones "malas" 
int iniLongitudMejor(tDatos const& datos, std::vector<tCalle> const& calles, std::vector<std::pair<bool, int>>& sol) {

    int i = 0; int sumaLongitud = 0; int sumaSal = 0; int contVecinos = 0; //sumatorios
    while (i < datos.C && sumaSal + calles[i].cantidadSal <= datos.cSal) {
        sol.push_back({ true, calles[i].id });
        sumaSal += calles[i].cantidadSal;
        sumaLongitud += calles[i].longitud;
        contVecinos += calles[i].numVecinos;
        ++i;
    }
    // cuando acabamos de buscar la mejor sol, tenemos que comprobar tb que cumple el min de Personas que pide el problema
    if (contVecinos >= datos.mPersonas)
        return sumaLongitud;
    else {

        sol.clear();
        return 0;
    }

}

// Se estima a partir de la calle en el que estamos para estimar la mayor longitud
float estimacion(tDatos const& datos, std::vector<tCalle> const& calles, int cantidadSalAct, int k) {
    int i = k + 1;
    int sumaSal = cantidadSalAct;
    int sumaLong = 0;

    // estimacion como tal 
    while (i < datos.C && sumaSal+ calles[i].cantidadSal <= datos.cSal) {
        sumaSal += calles[i].cantidadSal;
        sumaLong += calles[i].longitud;
        ++i;
    }

    // La parte que queda sin completar
    // cogemos la parte proporcional. 
    if (i < datos.C && sumaSal < datos.cSal) {
        float rest = datos.cSal - sumaSal;
        sumaLong += calles[i].longitud* (rest / (float)calles[i].cantidadSal);
    }

    return sumaLong;

}

// función que resuelve el problema
/* Parametros
    - datos: datos de entrada
    - calles: datos de cada calle
    - k: etapa pro donde voy
    - sol: vector con dimension numero de calles, es la solucion Actual
    - longituAct: longitud de la solucion actual
    - salAct: cantidad de sal utilizada en la solucion actual
    - contVecinos: cantidad de vecinos satisfechos hasta la solucion actual
    - solMejor: solucion mejor calculada hasta el momento
    - maxLongitud: la longitud de la solucion mejor

*/
void resolver(tDatos const& datos, std::vector<tCalle> const& calles, int k, std::vector<std::pair<bool, int>>& sol, int& longitudAct, int& salAct, int& contVecinos, std::vector<std::pair<bool, int>>& solMejor, int& maxLongitud) {

    // Limpiamos la calle
    sol[k] = { true, calles[k].id };
    longitudAct += calles[k].longitud;
    salAct += calles[k].cantidadSal;
    contVecinos += calles[k].numVecinos;

    if (salAct <= datos.cSal) { // es valida
        if (k == sol.size() - 1) { // es solucion
            if (contVecinos >= datos.mPersonas && longitudAct > maxLongitud) { // es Solucion mejor
                maxLongitud = longitudAct;
                solMejor = sol;
            }
        }
        else
            resolver(datos, calles, k + 1, sol, longitudAct, salAct, contVecinos, solMejor, maxLongitud);
    }

    sol[k] = { false, calles[k].id };
    longitudAct -= calles[k].longitud;
    salAct -= calles[k].cantidadSal;
    contVecinos -= calles[k].numVecinos;

    //No limpiamos la calle
    if (k == sol.size() - 1) { // es solucion
        if (contVecinos >= datos.mPersonas && longitudAct > maxLongitud) { // es Solucion mejor
            maxLongitud = longitudAct;
            solMejor = sol;
        }
    }
    else
        if(estimacion(datos, calles, salAct,k) + longitudAct > maxLongitud)
            resolver(datos, calles, k + 1, sol, longitudAct, salAct, contVecinos, solMejor, maxLongitud);

}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada

    int numCalles, cantidadSal, minCantidadV;

    std::cin >> numCalles >> cantidadSal >> minCantidadV;
    if (!std::cin)
        return false;
    tDatos  datos = { numCalles, cantidadSal, minCantidadV };

    std::vector<tCalle> calles(numCalles);
    for (int i = 0; i < numCalles; ++i) {
        std::cin >> calles[i].longitud >> calles[i].cantidadSal >> calles[i].numVecinos;
        calles[i].id = i;
    }

    std::sort(calles.begin(), calles.end(), comparador());
    std::vector <std::pair<bool, int>> solMejor;
    //int maxLongitud = 0; Sin estimacion 
    int maxLongitud = iniLongitudMejor(datos, calles, solMejor);
    int longitudAct = 0;
    int contVecinos = 0;
    int salAct = 0;
    std::vector<std::pair<bool, int>> sol(numCalles);

    resolver(datos, calles, 0, sol, longitudAct, salAct, contVecinos, solMejor, maxLongitud);

    // escribir sol
    if (!solMejor.empty()) {
        std::cout << (solMejor[0].first ? "SI" : "NO") << "-Calle" << solMejor[0].second;
        for (int i = 1; i < solMejor.size(); ++i) {
            std::cout << "  " << (solMejor[i].first ? "SI" : "NO") << "-Calle" << solMejor[i].second;
        }
    }

    else
        std::cout << "SIN SOLUCION";

    std::cout << '\n';

    return true;

}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("sample2.in");
    auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
    clock_t t = clock();

#endif 
    // Code to execute
    while (resuelveCaso())
        ;


    double time = (float(clock() - t) / CLOCKS_PER_SEC);
    std::cout << "\nExecution Time: " << time << '\n';

    // Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif

    return 0;
}