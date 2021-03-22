#include <iostream>
#include <vector>
using namespace std;

bool busquedaBinaria(vector<int> lista, int desde, int hasta, int elem){
	while(desde <= hasta) {
		int m = desde + (hasta - desde)/2;
		if (lista[m] == elem) { // encontre el elemento
			return true;
		}
		if (lista[m] < elem) { // esta en la mitad derecha
			desde = m + 1;
		} else { // esta en la mitad izquierda
			hasta = m - 1;
		}
	}
	// el elemento no esta
	return false;
}

int main() {
	vector<int> v = {3, 4, 5, 6, 7, 7, 20, 22};
	int numero = 8;
	int desde = 0;
	int hasta = v.size();

	if(busquedaBinaria(v, desde, hasta, numero)){
		cout << numero << " está en la lista" << endl;
	} else {
		cout << numero << " no está en la lista" << endl;
	}
	return 0;
}