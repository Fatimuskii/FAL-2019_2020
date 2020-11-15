// Nombre del alumno Fátima García Delgado
// Usuario del Juez E24


#include <iostream>
#include <iomanip>
#include <fstream>
#include <algorithm> // sort
#include <vector>


// función que resuelve el problema
// nos llegan los dos vectores con los elementos ordenados para poder ir iterando uno a uno. 
std::vector<int> resolver(std::vector<int>const& v1, std::vector<int>const& v2) {

	std::vector<int> sol;

	int i = 0;
	int j = 0;
	std::pair <int, int> contRep1 = { -1, 0 };
	std::pair <int, int> contRep2 = { -1, 0};

	while (i < v1.size() && j < v2.size()) {
	

		// Aqui codigo del alumno
		if (v1[i] == v2[j] ) {
			if (v1[i] == contRep1.first) contRep1.second++;
			else contRep1 = { v1[i],1 };
			if (v2[j] == contRep2.first) contRep2.second++;
			else contRep2 = { v2[j],1 };
			if (contRep1 == contRep2 ) {
				sol.push_back(v1[i]);
			}
			i++;
			j++;
		}

		else if (v1[i] < v2[j] ) {
			if (v1[i] == contRep1.first) contRep1.second++;
			else contRep1 = { v1[i],1 };
			i++;
		}
		else {
			if (v2[j] == contRep2.first) contRep2.second++;
			else contRep2 = { v2[j],1 };
			j++;
		}
	}


	return sol;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
	// leer los datos de la entrada
	int value;

	std::vector<int> v1;
	std::vector<int> v2;

	std::cin >> value;
	while (value != 0) {
		v1.push_back(value);
		std::cin >> value;
	}
	std::cin >> value;
	while (value != 0) {
		v2.push_back(value);
		std::cin >> value;
	}


	// antes de hacer la interseccion ordenamos ambos vectores
		// coste de la cada sort 0(nlogn)
	std::sort(v1.begin(), v1.end());
	std::sort(v2.begin(), v2.end());
	auto sol = resolver(v1, v2);
	
	// escribir sol
	if (!sol.empty()) {
		std::cout << sol[0];
		for (int i = 1; i < sol.size(); ++i)
			std::cout << ' ' << sol[i];
	}
	std::cout << '\n';

}

int main() {
	// Para la entrada por fichero.
	// Comentar para acepta el reto
#ifndef DOMJUDGE
	std::ifstream in("07sample.in");
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