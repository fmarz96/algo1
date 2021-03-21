#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

// Ejercicio 1

// 1.1)
bool divide(vector<int> v, int n){
    int cantDivVector = 0;
    for(int i = 0; i < v.size(); i++){
        if(v[i] % n == 0){
            cantDivVector += 1;
        }
    }
    return cantDivVector == v.size();
}

// 1.2)
int maximo(vector<int> v){
    int max = v[0];
    for(int i = 0; i < v.size(); i++){
        if(v[i] >= max){
            max = v[i];
        }
    }
    return max;
}

// 1.3)
bool pertenece(int elem, vector<int> v){
    bool pertenece = false;
    for(int i = 0; i < v.size(); i++){
        if(v[i] == elem){
            pertenece = true;
        }
    }
    return pertenece;
}

// 1.4)
void mostrarVector(vector<int> v){
    std::cout << "[";
    for(int i = 0; i < v.size(); i++){
        if(i < v.size() - 1){
            std::cout << v[i] << ", ";
        } else {
            std::cout << v[i] << "]" << std::endl;
        }
    }
}

// 1.5)
vector<int> sinImpares(vector<int> &v){
    for(int i = 0; i < v.size(); i++){
        if(v[i] % 2 == 1){
            v[i] = 0;
        }
    }
    return v;
}

// 1.6)
int cantidad_apariciones(int elem, vector<int> v){
    int apariciones = 0;
    for(int i = 0; i < v.size(); i++){
        if(v[i] == elem){
            apariciones += 1;
        }
    }
    return apariciones;
}
vector<int> limpiarDuplicados(vector<int> v){
    vector<int> v1, s;
    for(int i = 0; i < v.size(); i++){
        v1.push_back(v[i]);
        if(cantidad_apariciones(v[i], v1) == 1){
            s.push_back(v[i]);
        }
    }
    return s;
}

// 1.7)
vector<int> rotar(vector<int> v, int k){
    vector<int> s;
    if(k > v.size()){
        k = k % v.size();
    }
    for(int i = k; i < v.size(); i++){
        s.push_back(v[i]);
    }
    for(int j = 0; j < k; j++){
        s.push_back(v[j]);
    }
    return s;
}
/*vector<int> rotar (const vector<int>& v, int k){
    vector<int> res;
    for (int i = 0; i < v.size() - k; i++){
        res.push_back(v[i + k]);
    }
    for (int i = 0; i < k; i++){
        res.push_back(i);
    }
    return res;
}*/

// 1.8)
vector<int> reverso(vector<int> v){
    vector<int> s;
    int size = v.size() - 1;
    /*for(int i = size; i >= 0; i--){
        s.push_back(v[i]);
    }*/
    for(int i = 0; i < v.size(); i++){
        s.push_back(v[v.size() - 1 - i]);
    }
    return s;
}

// 1.9)
bool esPrimo(int n){
    int cant_divisores = 0;
    for(int i = 2; i < n; i++){
        if(n % i == 0){
            cant_divisores++;
        }
    }
    return cant_divisores == 0;
}
vector<int> factoresPrimos(int n){
    vector<int> v;
    if(esPrimo(n)){
        v.push_back(n);
    } else {
        for(int i = 2; i < n; i++){
            if(n % i == 0 && esPrimo(i)){
                v.push_back(i);
            }
        }
    }
    return v;
}

// 1.10)
bool ordenCreciente(vector<int> v){
    bool creciente = true;
    for(int i = 0; i < v.size()-1; i++){
        creciente = creciente && (v[i] <= v[i+1]);
    }
    return creciente;
}
bool estaOrdenado(vector<int> v){
    bool ordenado = ordenCreciente(v) || ordenCreciente(reverso(v));
    return ordenado;
}

// 1.11)
void mostrarVectorBools(vector<bool> v){
    std::cout << "[";
    for(int i = 0; i < v.size(); i++){
        if(i < v.size() - 1){
            std::cout << v[i] << ", ";
        } else {
            std::cout << v[i] << "]" << std::endl;
        }
    }
}
vector<bool> negar(vector<bool> &v){
    for(int i = 0; i < v.size(); i++){
        v[i] = !v[i];
    }
    return v;
}

// 1.12)
void mostrarVectorTuplas(vector<pair<int, int>> v){
    std::cout << "[";
    for(int i = 0; i < v.size(); i++){
        if(i < v.size() - 1){
            std::cout << "<" << v[i].first << ", " << v[i].second << ">" << ", ";
        } else {
            std::cout << "<" << v[i].first << ", " << v[i].second << ">" << "]" << std::endl;
        }
    }
}

vector<pair<int, int>> apariciones(vector<int> v){
    vector<pair<int, int>> s;
    vector<int> s1;
    for(int i = 0; i < v.size(); i++){
        s1.push_back(v[i]);
        if(cantidad_apariciones(v[i], s1) == 1){
            s.push_back({v[i], cantidad_apariciones(v[i], v)});
        }
    }
    return s;
}

// Ejercicio 2

// 2.1)
bool esPalindromo(string p1){
    int contadorLetras = 0;
    for(int i = 0; i < p1.length()/2; i++){
        if(p1[p1.length() - 1 - i] == p1[i]){
            contadorLetras += 1;
        }
    }
    return contadorLetras == (p1.length() / 2);
}

void palindromos(string rutaArchivoIn, string rutaArchivoOut){
    ifstream fin;
    fin.open(rutaArchivoIn);
    ofstream fout;
    fout.open(rutaArchivoOut);
    while(!fin.eof()){
        string p1;
        string p1Mayus;
        fin >> p1;
        if(esPalindromo(p1)){
            for(int i = 0; i < p1.length(); i++){
                p1Mayus = toupper(p1[i]);
                fout << p1Mayus;
            }
            fout << endl;
        }
    }
    fin.close();
    fout.close();
}

// 2.2)
void promedios(string rutaArchivoIn1, string rutaArchivoIn2, string rutaArchivoOut){
    ifstream fin1;
    fin1.open(rutaArchivoIn1);
    ifstream fin2;
    fin2.open(rutaArchivoIn2);
    ofstream fout;
    fout.open(rutaArchivoOut);
    while(!fin1.eof() && !fin2.eof()){
        float n1;
        float n2;
        fin1 >> n1;
        fin2 >> n2;
        float promedio = (n1 + n2)/2;
        fout << promedio << " ";
    }
    fin1.close();
    fin2.close();
    fout.close();
}

// 2.3
vector<int> fileToArray(string rutaArchivoIn){
    ifstream fin;
    fin.open(rutaArchivoIn);
    vector<int> v;
    while(!fin.eof()){
        int n;
        fin >> n;
        v.push_back(n);
    }
    return v;
}
int cantApariciones(vector<int> v, int elem){
    int apariciones = 0;
    for(int i = 0; i < v.size(); i++){
        if(v[i] == elem){
            apariciones++;
        }
    }
    return apariciones;
}
void cantidadApariciones(string rutaArchivoIn, string rutaArchivoOut){
    ifstream fin;
    fin.open(rutaArchivoIn);
    ofstream fout;
    fout.open(rutaArchivoOut);
    vector<int> lista = fileToArray(rutaArchivoIn);
    vector<int> sin_repe = limpiarDuplicados(lista);
    for(int j = 0; j < sin_repe.size(); j++){
        fout << sin_repe[j] << " " << cantApariciones(lista, sin_repe[j]) << endl;
    }
    fout.close();
    fin.close();
}

// 2.4
void estadisticas(string rutaArchivo){
    ifstream fin;
    fin.open(rutaArchivo);
    vector<int> largo_palabras;
    while(!fin.eof()){
        string pal;
        fin >> pal;
        int largo_pal = pal.length();
        int largo_vec = largo_palabras.size();
        if(largo_pal <= largo_vec){
            largo_palabras[largo_pal-1] += 1;
        } else {
            int dif = largo_pal - largo_vec;
            for(int i = 0; i < dif; i++){
                largo_palabras.push_back(0);
            }
            largo_palabras[largo_pal-1] += 1;
        }
    }
    int j = 0;
    while(j < largo_palabras.size()){
        std::cout << "Palabras de longitud " << j+1 << ": " << largo_palabras[j] << std::endl;
        j++;
    }
}

// 2.5
void interseccion(){
    string file1;
    cin >> file1;
    string file2;
    cin >> file2;
    vector<int> v1 = fileToArray(file1);
    vector<int> v2 = fileToArray(file2);
    vector<int> inter;
    if(v1.size() > v2.size()){
        for(int i = 0; i < v1.size(); i++){
            if(cantidad_apariciones(v1[i], v2) >= 1) {
                inter.push_back(v1[i]);
                //std::cout << v1[i] << std::endl;
            }
        }
    } else {
        for(int i = 0; i < v2.size(); i++){
            if(cantidad_apariciones(v2[i], v1) >= 1) {
                inter.push_back(v2[i]);
                //std::cout << v2[i] << std::endl;
            }
        }
    }
    inter = limpiarDuplicados(inter);
    int j = 0;
    while(j < inter.size()){
        std::cout << inter[j] << std::endl;
        j++;
    }
}

int main (){

    std::cout << "Hello, World!" << std::endl;
    cantidadApariciones("apariciones.txt", "apariciones_out.txt");
    estadisticas("estadisticas.txt");
    interseccion();
    vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    v.push_back(4);
    //std::cout << estaOrdenado(v) << std::endl;
    return 0;
}