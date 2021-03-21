#include <iostream>
#include <vector>
using namespace std;

/********* Ejercicio 1 *********/
vector<vector<int>> mostrarMatriz(vector<vector<int>> m){
    for(int i = 0; i < m.size(); i++){
        for(int j = 0; j < m[i].size(); j++){
            std::cout << m[i][j] << "\t";
        }
        std::cout << "\n";
    }
}

/********* Ejercicio 2 *********/
// 2)a)
int prodEscalar(vector<int> v1, vector<int> v2){
    int res = 0;
    if(v1.size() == v2.size()){
        int i = 0;
        while(i < v1.size()){
            res += v1[i]*v2[i];
            i++;
        }
    }
    return res;
}

// 2)b)
vector<vector<int>> prodTranspuesta(vector<vector<int>> mat){
    vector<vector<int>> res(mat[0].size(), vector<int>(mat.size()));
    for(int i = 0; i < mat.size(); i++){
        for(int j = 0; j < mat[i].size(); j++){
            res[i][j] = prodEscalar(mat[i], mat[j]);
        }
    }
    return res;
}

/********* Ejercicio 3 *********/
vector<vector<int>> resizeMatriz(vector<vector<int>> mat, int f, int c){
    vector<vector<int>> res;
    vector<int> v;
    int filasMat = mat.size();
    int columnasMat = mat[0].size();
    if(f*c == filasMat*columnasMat) {
        for (int i = 0; i < mat.size(); i++) {
            for (int j = 0; j < mat[i].size(); j++) {
                v.push_back(mat[i][j]);
                if (v.size() == c) {
                    if (res.size() < f) {
                        res.push_back(v);
                    }
                    while (v.size() > 0) {
                        v.pop_back();
                    }
                }
            }
        }
    }
    return res;
}

vector<vector<int>> redimMatriz(vector<vector<int>> mat, int f, int c){
    vector<vector<int>> res(f, vector<int>(c));
    int filasMat = mat.size();
    int columnasMat = mat[0].size();
    if(f*c == filasMat*columnasMat) {
        int k = 0, l = 0;
        for (int i = 0; i < mat.size(); i++) {
            for (int j = 0; j < mat[i].size(); j++) {
                res[k][l] = mat[i][j];
                l++;
                if(l==c){
                    l = 0;
                    k++;
                }
            }
        }
    }
    return res;
}

/********* Ejercicio 4 *********/
void trasponer(vector<vector<int>>& mat){
    vector<vector<int>> transpuesta(mat[0].size(), vector<int>(mat.size()));
    for(int i = 0; i < mat.size(); i++){
        for(int j = 0; j < mat[i].size(); j++){
            transpuesta[i][j] = mat[j][i];
        }
    }
    mat = transpuesta;
}


int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}