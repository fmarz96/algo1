//


#ifndef REUNIONESREMOTAS_AUXILIARES_H
#define REUNIONESREMOTAS_AUXILIARES_H

#include "definiciones.h"

using namespace std;
// definir aqui las funciones
pair<int,int> mp(int a, int b);
vector<posicion> ordenar(vector<posicion> &v);

// EJERCICIO 1
int filas(toroide const &t);
int columnas(toroide const &t);
bool distintaCantidadDeColumnas(toroide const &t, int indiceDeFila);
bool mismaCantidadDeColumnas(rectangulo const &r);
bool esToroide(toroide const &t);

// EJERCICIO 2
bool esCeldaMuerta(toroide const &t, int indiceDeFila, int indiceDeColumna);

// EJERCICIO 3
bool esCeldaViva(const toroide &t, int indiceDeFila, int indiceDeColumna);

// EJERCICIO 5
int columnaToroide(int indiceDeColumna,toroide const &t);
int filaToroide(int indiceDeFila,toroide const &t);

// EJERCICIO 6
bool valeSegundaRegla(toroide const &t, int indiceDeFila, int indiceDeColumna);
bool valeCuartaRegla(toroide const &t, int indiceDeFila, int indiceDeColumna);
bool debeVivir(toroide const &t, posicion &x);

// EJERCICIO 11
int indiceDelMaximo(vector<int> ticksHastaMorir);
int cantidadDeTicksEnQueMuere(toroide t);

// EJERCICIO 13
toroide traslacion(toroide const &u, int traslacionEnX, int traslacionEnY);

// EJERCICIO 14
int menorArea(vector<int> areasRectangulo);
bool menorEstricto(int a, int b);
bool mayorEstricto(int a, int b);
int areaDelRectangulo(toroide const &t, vector<posicion> posicionesVivas);

#endif //REUNIONESREMOTAS_AUXILIARES_H
