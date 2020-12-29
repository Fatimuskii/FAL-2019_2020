// Nombre del alumno Fátima García
// Usuario del Juez E24

// Torneo de Tenis

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

/*
Coste :

				Co n=2
	T(n) = {
				2T(n/2) + c1 n>2

					n= num elementos del vector

	Coste= O(n)
*/

struct tRonda {
	int rondaActual; // indicador de ronda
	int cont; // contador de partidas
	bool presentada; // ha habido jugadores
};

// función que resuelve el problema
tRonda resolver(int ini, int fin, std::vector<std::string> const& datos, int const& ronda) {

	if (ini + 2 == fin) {

		return {
			1 ,
			datos[ini].compare("NP") != 0 && datos[fin - 1].compare("NP") != 0 ,
			datos[ini].compare("NP") != 0 || datos[fin - 1].compare("NP") != 0
		};
	}
	else {

		int mitad = (ini + fin) / 2;

		tRonda izq = resolver(ini, mitad, datos, ronda);

		tRonda drch = resolver(mitad, fin, datos, ronda);

		if (izq.rondaActual + 1 <= ronda) {

			return {
				izq.rondaActual + 1 ,
				izq.cont + drch.cont +
				(izq.presentada && drch.presentada) ,
				izq.presentada || drch.presentada
			};
		}

		else {

			return {
				izq.rondaActual + 1 ,
				izq.cont + drch.cont ,
				izq.presentada || drch.presentada
			};
		}
	}

}


// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta


bool resuelveCaso() {
	// leer los datos de la entrada
	int elementos = 0, ronda = 0;
	std::cin >> elementos;
	if (!std::cin)
		return false;
	std::cin >> ronda;

	std::vector<std::string>rondas(elementos);

	for (int i = 0; i < elementos; ++i) {
		std::cin >> rondas[i];
	}

	int ini = 0;
	int fin = elementos;


	tRonda sol = resolver(ini, fin, rondas, ronda);

	// escribir sol
	std::cout << sol.cont << '\n';

	return true;

}

int main() {
	// Para la entrada por fichero.
	// Comentar para acepta el reto
#ifndef DOMJUDGE
	std::ifstream in("38sample.in");
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