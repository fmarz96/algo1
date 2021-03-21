#include "definiciones.h"
#include "auxiliares.h"
#include "ejercicios.h"

using namespace std;
// aqui se pueden ubicar todas las funciones auxiliares de soporte para la resolucion de los ejercicios
pair<int,int> mp(int a, int b) {
    return make_pair(a, b);
}
//No pueden usar esta función para resolver el TPI.
//Tampoco pueden usar iteradores, como usa esta función.
vector<posicion> ordenar(vector<posicion> &v) {
    sort(v.begin(), v.end());
    return v;
}

// EJERCICIO 1

int filas(toroide const &t) {

    return t.size();
}

int columnas(toroide const &t) {

    if (filas(t) > 0){

        return t[0].size();

    }
    else{

        return 0;

    }
}

bool distintaCantidadDeColumnas(toroide const &t, int indiceDeFila) {

    return t[indiceDeFila].size() != t[0].size();
}

bool mismaCantidadDeColumnas(toroide const &t) {

    bool resp = true;

    for(int indiceDeFila = 0; indiceDeFila < t.size(); indiceDeFila++){

        if (distintaCantidadDeColumnas(t, indiceDeFila)){

            resp = false;

        }

    }

    return resp;
}

bool esToroide(toroide const &t) {

    return ((columnas(t) >= 3) && (filas(t) >= 3) && mismaCantidadDeColumnas(t));
}

// EJERCICIO 2

bool esCeldaMuerta(toroide const &t, int indiceDeFila, int indiceDeColumna) {

    bool resp = false;

    if (t[indiceDeFila][indiceDeColumna] == false){

        resp = true;

    }

    return resp;
}

// EJERCICIO 3

bool esCeldaViva(const toroide &t, int indiceDeFila, int indiceDeColumna) {

    return !esCeldaMuerta(t, indiceDeFila, indiceDeColumna);
}

// EJERCICIO 5

int columnaToroide(int indiceDeColumna,toroide const &t){

    int resp = 0;

    resp = indiceDeColumna % columnas(t);

    if (resp < 0){

        resp = resp + columnas(t);

    }

    return resp;
}

int filaToroide(int indiceDeFila,toroide const &t){

    int resp = 0;

    resp = indiceDeFila % filas(t);

    if (resp < 0){

        resp = resp + filas(t);

    }

    return resp;
}

// EJERCICIO 6

bool valeSegundaRegla(toroide const &t, int indiceDeFila, int indiceDeColumna){

    if ((esCeldaViva(t, indiceDeFila, indiceDeColumna)) && (2 <= cantidadVecinosVivos(t, indiceDeFila, indiceDeColumna)) && (cantidadVecinosVivos(t, indiceDeFila, indiceDeColumna) <= 3)) {

        return true;

    }

    return false;
}

bool valeCuartaRegla(toroide const &t, int indiceDeFila, int indiceDeColumna){

    if (esCeldaMuerta(t, indiceDeFila, indiceDeColumna) && (cantidadVecinosVivos(t, indiceDeFila, indiceDeColumna) == 3)){

        return true;

    }

    return false;
}

bool debeVivir(toroide const &t, posicion &x) {

    bool resp = false;

    if(valeSegundaRegla(t, x.first, x.second) || valeCuartaRegla(t, x.first, x.second)){

        resp = true;

    }

    return resp;
}

// EJERCICIO 11

int indiceDelMaximoK(vector<int> KsHastaMorir) {

    int maximoK = KsHastaMorir[0];
    int indiceMaximoK = 0;

    for(int indice = 1; indice < KsHastaMorir.size(); indice++){

        if(maximoK < KsHastaMorir[indice]){

            maximoK = KsHastaMorir[indice];

            indiceMaximoK = indice;
        }

    }

    return indiceMaximoK;
}

int cantidadDeTicksEnQueMuere(toroide t){

    int tick = 0;

    while(!toroideMuerto(t)){

        evolucionToroide(t);

        tick++;
    }

    return tick;
}

// EJERCICIO 13

toroide traslacion(toroide const &u, int traslacionEnX, int traslacionEnY) {

    toroide res = u;

    for (int indiceDeFila = 0; indiceDeFila < u.size(); ++indiceDeFila) {

        for (int indiceDeColumna = 0; indiceDeColumna < u[0].size(); ++indiceDeColumna) {

            res[filaToroide(indiceDeFila + traslacionEnY, u)][columnaToroide(indiceDeColumna + traslacionEnX, u)] = u[indiceDeFila][indiceDeColumna];

        }
    }

    return res;
}

// EJERCICIO 14

int menorArea(vector<int> areasRectangulo) {

    int menorArea = areasRectangulo[0];

    for(int indice = 1; indice < areasRectangulo.size(); indice++){

        if(menorArea > areasRectangulo[indice]){

            menorArea = areasRectangulo[indice];

        }

    }

    return menorArea;
}

bool menorEstricto(int a, int b) {

    return a < b;
}

bool mayorEstricto(int a, int b) {

    return a > b;
}

int areaDelRectangulo(toroide const &t, vector<posicion> posicionesVivas) {

    int filaDesde = t.size() - 1;
    int filaHasta = 0;

    int columnaDesde = t[0].size() - 1;
    int columnaHasta = 0;

    for (int indice = 0; indice < posicionesVivas.size(); ++indice) {

        if (menorEstricto(posicionesVivas[indice].first, filaDesde)){

            filaDesde = posicionesVivas[indice].first;

        }

        if (mayorEstricto(posicionesVivas[indice].first, filaHasta)){

            filaHasta = posicionesVivas[indice].first;

        }

        if (menorEstricto(posicionesVivas[indice].second, columnaDesde)){

            columnaDesde = posicionesVivas[indice].second;

        }

        if (mayorEstricto(posicionesVivas[indice].second, columnaHasta)){

            columnaHasta = posicionesVivas[indice].second;

        }

    }

    int base = (columnaHasta - columnaDesde) + 1;

    int altura = (filaHasta - filaDesde) + 1;

    return base * altura;
}