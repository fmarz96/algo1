#include <iostream>
#include <vector>
using namespace std;

bool busquedaLineal(vector<int> lista, int elem){
	bool res = false;
	for(int i = 0; i < lista.size(); i++){
		if(lista[i] == elem){
			res = true;
		}
	}
	return res;
}

int main() {
	vector<int> v = {3, 4, 5, 6, 7, 7, 3, -20, 2};
	int numero = 5;

	if(busquedaLineal(v, numero)){
		cout << numero << " está en la lista" << endl;
	} else {
		cout << numero << " no está en la lista" << endl;
	}
	return 0;
}