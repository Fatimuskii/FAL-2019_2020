// Nombre del alumno Fatima Irene Garcia Delgado    
// Usuario del Juez E24


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

// Fuga de prision
/*
 * Coste:
 *
 * 		T(n) = {
 *
 * 			Co 			si ini+1 == fin
 *
 * 			T(n/2) + C1 	resto de casos
 *
 * 		}

  * Complejidad: O( nlog(n) )
 *
 * 
*/
// función que resuelve el problema
char resolver(const std::vector<char>& v, const int& ini, const int& fin) {

	//caso base
	if (ini + 1 == fin)

		return v[ini] + 1;

	else {

		int m = (fin + ini) / 2;

		if ((v[ini] - ini) != (v[m] - m))

			return resolver(v, ini, m);

		else

			return resolver(v, m, fin);

	}

}


// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {


	char prim; //primera letra
	char ult; // ultima letra

	// leer los datos de la entrada
	std::cin >> prim >> ult;

	std::vector<char> v(ult - prim); 

	//cargamos los datos
	for (int i = 0; i < v.size(); ++i)
		std::cin >> v[i];

	// escribir sol
	if (v[0] != prim)
		std::cout << prim << '\n';

	else if (v[v.size() - 1] != ult)
		std::cout << ult << '\n';

	else
		std::cout << resolver(v, 0, v.size() - 1) << '\n';

}



int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
	std::ifstream in("31sample.in");
    auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif 


    int numCasos;
    std::cin >> numCasos;
    for (int i = 0; i < numCasos; ++i)
        resuelveCaso();


    // Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif

    return 0;
}