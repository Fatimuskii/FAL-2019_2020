// Nombre del alumno Fatima Garcia Delgado	
// Usuario del Juez E24

//Necesito un abrigo
#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

bool esValida(std::vector<int> const& precipitaciones, std::vector<int> const& cant,
	std::vector<int> const& sol, std::vector<int>& marcar, int k, int i) {

	if ((k >= 1) && (sol[k - 1] == sol[k])) return false; //dos seguidas;
	if (precipitaciones[k] > cant[sol[k]]) return false; //se moja;
	if (marcar[i] > (k / 3) + 2) return false; //abrigo mas usado < (un tercio + 2 dias transcuridos):

	return true;
}


// función que resuelve el problema
void resolver(int numDias, int numAbrigos, std::vector<int> const& precip,
	std::vector<int> const& cant, std::vector<int>& sol, int& cont,
	std::vector<int>& marcar, int k) {

	for (int i = 0; i < numAbrigos; ++i) {
		sol[k] = i; //Guardo un abrigo en un dia en concreto;
		++marcar[i]; //Marco el abrigo usado;

		if (esValida(precip, cant, sol, marcar, k, i)) {
			if (k == numDias - 1) { //final?
				if (sol[0] != sol[k]) { //abrigo distinto el primer y ultimo dia;
					cont++;
				}
			}

			else resolver(numDias, numAbrigos, precip, cant, sol, cont, marcar, k + 1); //siguiente etapa;
		}

		sol[k] = -1; //Quito el abrigo cuando no es valido
		--marcar[i]; //Desmarco el abrigo usado;
	}
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	// leer los datos de la entrada
	int numDias, numAbrigos;

	std::cin >> numDias >> numAbrigos;
	if (numDias == 0 && numAbrigos == 0)
		return false;


	std::vector<int> precip(numDias);
	for (int i = 0; i < numDias; ++i)
		std::cin >> precip[i];

	std::vector<int> cant(numAbrigos);
	for (int i = 0; i < numAbrigos; ++i)
		std::cin >> cant[i];


	std::vector<int> sol(numDias, -1);
	std::vector<int> marcaje(numAbrigos);
	int cont = 0;
	resolver(numDias, numAbrigos, precip, cant, sol, cont, marcaje, 0);

	// escribir sol
	if (cont == 0) std::cout << "Lo puedes comprar\n";
	else std::cout << cont << '\n';

	return true;

}

int main() {
	// Para la entrada por fichero.
	// Comentar para acepta el reto
#ifndef DOMJUDGE
	std::ifstream in("48sample.in");
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