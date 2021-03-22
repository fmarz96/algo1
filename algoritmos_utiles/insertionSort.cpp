#include <iostream>
#include <vector>
using namespace std;

vector<int> insertionSort(vector<int> lista){
    for(int i = 0; i < lista.size(); i++){
        insertar(lista, i);
    }
    return lista;
}

void insertar(vector<int> &lista, int i){
    while(i > 0 && lista[i] < lista[i-1]){
        swap(lista, i, i-1);
        i--;
    }
}

void swap(vector<int> &lista, int i, int j){
	int k = lista[i];
    lista[i] = lista[j];
    lista[j] = k;
}