#include <algorithm>
#include "ejercicios.h"
#include "auxiliares.h"

// EJERCICIO 1
bool toroideValido(toroide const &t) {
    bool resp = false;
    resp = esToroide(t);
    return resp;
}

// EJERCICIO 2
bool toroideMuerto(toroide const &t) {
    bool resp = false;
    int cantidadDeCeldas = filas(t) * columnas(t);
    int celdasMuertas = 0;
    for (int indiceDeFila = 0; indiceDeFila < t.size(); indiceDeFila++){
        for (int indiceDeColumna = 0; indiceDeColumna < t[indiceDeFila].size(); indiceDeColumna++){
            if(esCeldaMuerta(t, indiceDeFila, indiceDeColumna)){
                celdasMuertas++;
            }
        }
    }
    if (celdasMuertas == cantidadDeCeldas){
        resp = true;
    }
    return resp;
}

// EJERCICIO 3
vector<posicion> posicionesVivas(toroide const &t) {
    vector<posicion> vivos;
	for(int indiceDeFila = 0; indiceDeFila < t.size(); indiceDeFila++){
        for(int indiceDeColumna = 0; indiceDeColumna < t[indiceDeFila].size(); indiceDeColumna++){
            if(esCeldaViva(t, indiceDeFila, indiceDeColumna)){
                vivos.push_back({indiceDeFila, indiceDeColumna});
            }
        }
    }
    return vivos;
}

// EJERCICIO 4
float densidadPoblacion(toroide const &t) {
    float resp = -1;
    int cantidadCeldasVivas = posicionesVivas(t).size();
    resp = cantidadCeldasVivas/(filas(t)*columnas(t));
    return resp;
}

// EJERCICIO 5
int cantidadVecinosVivos(toroide const &t, int f, int c) {
    int resp = 0;
    for (int indiceDeFila = -1; indiceDeFila <= 1; ++indiceDeFila){
        for (int indiceDeColumna = -1; indiceDeColumna <= 1; ++indiceDeColumna){
            if (indiceDeFila != 0 || indiceDeColumna != 0) {
                if (esCeldaViva(t, filaToroide(f + indiceDeFila, t), columnaToroide(c + indiceDeColumna, t))) {
                    resp++;
                }
            }
        }
    }
    return resp;
}

// EJERCICIO 6
bool evolucionDePosicion(toroide const &t, posicion x) {
    bool resp = false;
	resp = debeVivir(t,x);
    return resp;
}

// EJERCICIO 7
void evolucionToroide(toroide &t){
    toroide tEvolucionadoUnTick = t;
    for (int indiceDeFila = 0; indiceDeFila < t.size() ; ++indiceDeFila) {
        for (int indiceDeColumna = 0; indiceDeColumna < t[indiceDeFila].size(); ++indiceDeColumna) {
            if (evolucionDePosicion(t, {indiceDeFila, indiceDeColumna})){
                tEvolucionadoUnTick[indiceDeFila][indiceDeColumna] = true;
            } else {
                tEvolucionadoUnTick[indiceDeFila][indiceDeColumna] = false;
            }
        }
    }
    t = tEvolucionadoUnTick;
}

// EJERCICIO 8
toroide evolucionMultiple(toroide const &t, int K) {
    toroide out = t;
    for (int tick = 1; tick <= K; ++tick) {
        evolucionToroide(out);
    }
    return out;
}

// EJERCICIO 9
bool esPeriodico(toroide const &t, int &p) {
    bool resp = false;
    if (evolucionMultiple(t, p) == t){
        resp = true;
    }
    return resp;
}

// EJERCICIO 10
bool primosLejanos(toroide const &t, toroide const &u) {
    bool resp = false;
	toroide tEvolucionado = t;
    toroide uEvolucionado = u;
    bool tEsPeriodico = false;
    bool uEsPeriodico = false;
    for (int tick = 1; ((resp != true) && ((!toroideMuerto(tEvolucionado)) || (!toroideMuerto(uEvolucionado)))
                                    && ((!tEsPeriodico) || (!uEsPeriodico))
                                    && ((!toroideMuerto(tEvolucionado)) || (!tEsPeriodico))
                                    && ((!toroideMuerto(uEvolucionado)) || (!uEsPeriodico))); ++tick) {
        if (esPeriodico(t, tick)){
            tEsPeriodico = true;
        }
        if (esPeriodico(u, tick)){
            uEsPeriodico = true;
        }
        tEvolucionado = evolucionMultiple(t, tick);
        uEvolucionado = evolucionMultiple(u, tick);
        if ((tEvolucionado == u) || (uEvolucionado == t)){
            resp = true;
        }
    }
    return resp;
}

// EJERCICIO 11
int seleccionNatural(vector <toroide> ts) {
    int resp = -1;
    vector<int> ticksHastaMorir(ts.size());
    for (int indice = 0; indice < ts.size(); ++indice) {
        ticksHastaMorir[indice] = cantidadDeTicksEnQueMuere(ts[indice]);
    }
    resp = indiceDelMaximo(ticksHastaMorir);
    return resp;
}

// EJERCICIO 12
toroide fusionar(toroide const &t, toroide const &u) {
    toroide out = t;
    for (int indiceDeFila = 0; indiceDeFila < t.size(); ++indiceDeFila) {
        for (int indiceDeColumna = 0; indiceDeColumna < t[indiceDeFila].size(); ++indiceDeColumna) {
            if ((esCeldaViva(t, indiceDeFila, indiceDeColumna)) && (esCeldaViva(u, indiceDeFila, indiceDeColumna))){
                out[indiceDeFila][indiceDeColumna] = true;
            } else {
                out[indiceDeFila][indiceDeColumna] = false;
            }
        }
    }
    return out;
}

// EJERCICIO 13
bool vistaTrasladada(toroide const &t, toroide const &u){
    bool resp = false;
    for (int traslacionEnY = 0; (traslacionEnY < u.size()) && (resp != true); ++traslacionEnY) {
        for (int traslacionEnX = 0; (traslacionEnX < u[0].size()) && (resp != true); ++traslacionEnX) {
            if(traslacionEnY != 0 || traslacionEnX != 0){ //Si no estoy en el caso traslacion x=0 e y=0
                if(t == traslacion(u, traslacionEnX, traslacionEnY)){
                    resp = true;
                }
            }
        }
    }
    return resp;
}

// EJERCICIO 14
int menorSuperficieViva(toroide const &t){
    int resp = -1;
    vector<int> areasRectangulo = {areaDelRectangulo(t, posicionesVivas(t))};
    toroide tTrasladado = t;
    for (int traslacionEnY = 0; (traslacionEnY < t.size()); ++traslacionEnY) {
        for (int traslacionEnX = 0; (traslacionEnX < t[0].size()); ++traslacionEnX) {
            if (traslacionEnY != 0 || traslacionEnX != 0) {
                tTrasladado = traslacion(t, traslacionEnX, traslacionEnY);
                areasRectangulo.push_back(areaDelRectangulo(tTrasladado, posicionesVivas(tTrasladado)));
            }
        }
    }
    resp = menorArea(areasRectangulo);
    return resp;
}