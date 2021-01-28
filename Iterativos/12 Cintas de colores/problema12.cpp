// Nombre del estudiante. Fatima Garcia Delgado
// Usuario del juez.    E24

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>


// Explicación del algoritmo utilizado
/* El problema nos pide modificar el vector original que contendrá las citnas de colores. Así quedarán de izq a derecha primero 
las cintas de color azules, verdes y rojas. */
// Coste del algoritmo utilizado

/* Especificacion: Precondicion: ¿qué cumplen los datos del algoritmo?

    *P(alg) = { v.size() >= 0 && forall j: 0 <= j < v.size(): v[j] in {'a','v', 'r'}  && v=V (permutacion)

    particion(vector<psi> & v) dev {int p, int q}

    Q(blucle) = Q(alg) ={ forall j: 0 <=j < p: v[j] =='a'
            && forall j: p <=j <=q: v[j] =='v'
            && forall j : q < j< v.size(): v[j] =='r'
            && permutacion (v, V) 
            }  // permutacion
*/
using psi = std::pair<char, int>;

// Recibe un vector con los datos de entrada del problema
// Modifica este vetor dejando en las primeras posiciones 
// las cintas azules, luego las verdes y uego las rojas
// NO se puede utilizar sort
// p es la primera posicion de una cinta verde, q es la ultima posicion de una cinta verde
void particion (std::vector<psi> & v, int &p, int &q) {
    // Aqui codigo del estudiante

    p = 0; q = v.size() - 1; 
    int k = 0;

    /* P(bucle)*: { P(alg) && p=0 && q = v.size()-1 && k = 0;
        Inv = forall j: 0 <= j < p: v[j] == 'a' && forall j: p <= j < k: v[j] =='v'
               && forall j: q< j <v.size(): v[j] == 'r'  
               && 0 <= p <= k <= q +1 < v.size()
        t(k, q) = q - k + 2 

        Q(bucle) = P(alg)

*/
           
            
    while (k<= q ) {
        if (v[k].first == 'v') ++k; // si me encuentro un verde incremento( de p a k serán verdes) 

        else if (v[k].first == 'a') {
            std::swap(v[p], v[k]); 
            ++p; ++k;
        }
        else { // Ambos elementos fuera de sitio
            std::swap(v[q], v[k]); 
           
            --q; 

        }
    }

}


// Entrada y salida de datos
bool resuelveCaso() {
    // Lectura de los datos de entrada
    int numCintas;
    std::cin >> numCintas;
    if (!std::cin) return false;
    std::vector<psi> v(numCintas); // nombre y altura
    for (psi & n : v) {
        std::cin  >> n.first >> n.second;
    }
    // LLamada a la función paticion
    int p, q;
    // mostrar el vector antes de ser ordenado: 
 
    particion(v, p, q);


    // Ordena cada parte para la salida de datos
    std::sort(v.begin(), v.begin()+p); // azules van de [0 - p)
    std::sort(v.begin()+p, v.begin()+1+q); // verdes [p-q)
    std::sort(v.begin()+1+q, v.end()); 
    // Escribe las cintas azules
    std::cout << "Azules:";
    for (int i = 0; i < p; ++i){
        std::cout << ' ' << v[i].second ;
    }
    std::cout << '\n';
    // Escribe la segunda parte
    std::cout << "Verdes:";
    for (int i = p; i <= q; ++i){
        std::cout << ' ' << v[i].second ;
    }
    std::cout << '\n';
    // Escribe la tercera parte
    std::cout << "Rojas:";
    for (int i = q+1; i < v.size(); ++i){
        std::cout << ' ' << v[i].second ;
    }
    std::cout << '\n';
    return true;
}



int main() {

#ifndef DOMJUDGE
    std::ifstream in("12sample.in");
    auto cinbuf = std::cin.rdbuf(in.rdbuf()); 
#endif
    
    while (resuelveCaso()) {} //Resolvemos todos los casos
    
#ifndef DOMJUDGE // para dejar todo como estaba al principio
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif
    
    return 0;
}
