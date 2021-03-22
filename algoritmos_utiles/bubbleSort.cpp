#include <iostream>
#include <vector>
using namespace std;

vector<int> bubbleSort(vector<int> lista){
    for(int i = 0; i < lista.size(); i++){
        burbujeo(lista, i);
    }
    return lista;
}

void burbujeo(vector<int> &lista, int i){
    for(int j = lista.size() -1; j > i; j--){
        if(lista[j] < lista[j-1]){
            swap(lista, j, j-1);
        }
    }
}

void swap(vector<int> &lista, int i, int j){
    int k = lista[i];
    lista[i] = lista[j];
    lista[j] = k;
}