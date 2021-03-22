#include <iostream>
#include <vector>
using namespace std;

vector<int> selectionSort(vector<int> lista){
    for(int i = 0; i < lista.size(); i++){
        seleccionarMinimo(lista, i);
    }
    return lista;
}

void seleccionarMinimo(vector<int> &lista, int i){
    int posMinimo = i;
    for(int j = i; j < lista.size(); j++){
        if(lista[posMinimo] > lista[j]){
            posMinimo = j;
        }
    }
    swap(lista, i, posMinimo);
}

void swap(vector<int> &lista, int i, int j){
	int k = lista[i];
    lista[i] = lista[j];
    lista[j] = k;
}