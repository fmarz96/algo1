#include <iostream>
#include <vector>
using namespace std;

vector<int> countingSort(vector<int> &lista) {
    vector<int> conteo = contar(lista);
    return reconstruir(lista, conteo);
}

vector<int> contar(vector<int> &lista) {
// creo un vector inicializado en 0
// cuya longitud sea igual a una cota maxima
    vector<int> conteo(maximo(lista)+1, 0);
    for (int i = 0; i < lista.size(); i++) {
        conteo[lista[i]]++;
    }
    return conteo;
}

vector<int> reconstruir(vector<int> &lista, vector<int> conteo) {
    vector<int> resultado(lista.size());
    int indice_conteo = 0;
    for (int i = 0; i < lista.size(); i++) {
        // Ignoro valores nulos
        while (conteo[indice_conteo] == 0) {
            indice_conteo++;
        }
        lista[i] = indice_conteo;
        conteo[indice_conteo]--;
    }
    return lista;
}