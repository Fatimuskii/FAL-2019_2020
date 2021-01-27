// Examen enero 2020 FAL. Grupos E, F, I
// Ejercicio 3
// Solución de Isabel Pita

#include <iostream>
#include <fstream>
#include <vector>

const int INF = 1000000000;
struct tDatos {
    int nElems, numColores; // numero de escalones, numero de colores diferentes
    std::vector<int> valores; // ancho de cada escalon
    std::vector<std::pair<int,int>> colores; // cantidad de pintura y precio de esa pintura
};

struct tSol {
    std::vector<int> sol; // pintura seleccionada para cada escalon
    int coste; // coste de pintar los escalones con la pintura seleccionada
};

bool esValida(tDatos const& d, int k, tSol const& s, std::vector<int> const& marcas, tSol const& sMejor) {
    // Dos escalones seguidos del mismo color
    if (k > 0 && s.sol[k-1] == s.sol[k]) return false;
    // No tiene un coste mayor que una solución anterior
    if (s.coste > sMejor.coste) return false;
    // Tenemos pintura suficiente de ese color
    if (marcas[s.sol[k]] > d.colores[s.sol[k]].first) return false;
    return true;
}

// funcion recursiva que resuelve el problema por vuelta atrás
// El vector solución guarda el color del que pintamos cada escalón. Tiene dimensión el número de escalones
// El árbol de ejecución selecciona el color de cada escalón. Las ramas son los colores y la altura el número de escalones. 
// Se guarda la solución mejor hasta este momento y el coste mejor hasta este momento. 
// Las marcas guardan la cantidad de pintura de cada color utilizada hasta este momento.
// Para estimar calculamos el número 
void escalera(tDatos const& d, int k, tSol & s, std::vector<int> & marcas,tSol & sMejor, std::vector<int> const& estim){
    for (int i = 0; i < d.numColores; ++i) {
        s.sol[k] = i; // se selecciona un color
        s.coste += d.colores[i].second * d.valores[k]; // cantidad que se pinta por precio pintura
        marcas[i] += d.valores[k];
        if (esValida(d,k,s,marcas,sMejor)){  // es valida
            if (k == d.nElems - 1) {  // es solución
                if (s.coste < sMejor.coste) { // es solución mejor
                    sMejor.coste = s.coste;
                    sMejor.sol = s.sol;
                }
            }
            else{ 
                if (s.coste + estim[k+1] < sMejor.coste) // estimacion
                    escalera(d,k+1,s,marcas,sMejor, estim);
            }
        }
        // desmarcar
        s.coste -= d.colores[i].second * d.valores[k];
        marcas[i] -= d.valores[k];
    }
    
}

bool resuelveCaso () {
    // lectura de datos
    tDatos d;
    std::cin >> d.nElems;
    if (d.nElems == -1) return false;
    std::cin >> d.numColores;
    d.valores.resize(d.nElems);
    for (int &i : d.valores) std::cin >> i;
    d.colores.resize(d.numColores);
    int totalMin = INF;
    // Leer los datos de los colores
    // Se calcula la pintura de menor coste para la estimación
    for (int i = 0; i < d.numColores; ++i) {
        std::cin >> d.colores[i].first >> d.colores[i].second;
        if (d.colores[i].second < totalMin) totalMin = d.colores[i].second;
    }
    // Preparar los datos para la llamada a la función
    tSol s;
    s.sol.resize(d.nElems); s.coste = 0;
    std::vector<int> marcas(d.numColores,0);
    tSol sMejor;
    sMejor.sol.resize(d.nElems);
    // Para calcular una solución hay que tener cuidado porque se puede agotar la pintura de un color y dos escalones seguidos no pueden tener el mismo color
    sMejor.coste = INF;
    // Para estimar calculamos el ancho de los escalones que faltan por pintar en cada etapa.
    std::vector<int> estim(d.nElems);
    estim[d.nElems-1] = d.valores[d.nElems-1];
    for (int i = d.nElems-1; i > 0; --i) {
        estim[i-1] = estim[i] + d.valores[i-1];
    }
    for (int i = d.nElems-1; i >= 0; --i) {
        estim[i] *= totalMin;
    }
    // LLamada a la función de vuelta atrás
    escalera(d,0,s,marcas,sMejor, estim);
    // escribir el resultado
    if (sMejor.coste < INF){
        std::cout << sMejor.coste << '\n';
        std::cout << sMejor.sol[0];
        for (int i = 1; i < sMejor.sol.size(); ++i) 
            std::cout << ' ' << sMejor.sol[i];
        std::cout << '\n';
    }
    else 
        std::cout << "NO\n";
    return true;
}




int main() {

    while (resuelveCaso());
    return 0;
}
