#include "maxMonticulo.h"
#include <stdlib.h>

void errorMaxMonticulo(char * func, char * msg) {
    printf("ERROR (%s): %s\n", func, msg);
    exit(-1);
}

void nuevoMaxMonticulo(tipoMaxMonticulo *m, int numElem) {
    m->numEl = numElem;
    m->array = (tipoElementoMaxMonticulo*)malloc(sizeof(tipoElementoMaxMonticulo)*numElem);
    m->pos = -1;
}

void insertarMaxMonticulo(tipoMaxMonticulo *m, tipoElementoMaxMonticulo e) {
    if (estaLleno(*m)) errorMaxMonticulo("insertarMaxMonticulo", "El montículo está lleno");
    m->pos = m->pos + 1; // Incrementar la posición del último elemento e insertar el nuevo
    m->array[m->pos] = e;
    int actual = m->pos;
    int padre = (actual - 1) / 2; // Ajustar el nuevo elemento hacia arriba en el montículo
    while (actual > 0 && m->array[padre].distancia < e.distancia) { // Mientras el padre sea menor que el nuevo elemento
        intercambio(&m->array[actual], &m->array[padre]);
        actual = padre;
        padre = (actual - 1) / 2;
    }
}

void eliminarMaxMonticulo(tipoMaxMonticulo *m, tipoElementoMaxMonticulo e) {
    if(esVacio(*m)) errorMaxMonticulo("eliminarMaxMonticulo", "El monticulo está vacio");
    int i = 0;
    while (m->array[i].distancia != e.distancia && i < m->numEl) i++;
    if(m->array[i].distancia != e.distancia) errorMaxMonticulo("eliminarMaxMonticulo", "El elemento no esta");
    intercambio(&m->array[i],&m->array[m->pos]);
    m->pos--;
    if(2*i+1 >= m->pos && 2*i+2 >= m->pos) { //si tiene 2 hijos cambiarlo por el mayor
        if(m->array[2*i+1].distancia > m->array[2*i+2].distancia) {
            if(m->array[2*i+1].distancia > m->array[i].distancia) 
                intercambio(&m->array[2*i+1], &m->array[i]);
        } else { 
            if(m->array[2*i+2].distancia > m->array[i].distancia) 
                intercambio(&m->array[2*i+2], &m->array[i]);
        }
    } else if(2*i+1 >= m->pos) { //si tiene solo el hijo izquierdo se cambia si es mayor
        if(m->array[2*i+1].distancia > m->array[i].distancia) 
            intercambio(&m->array[2*i+1], &m->array[i]);
    }
}

tipoElementoMaxMonticulo devolverRaiz(tipoMaxMonticulo m) {
    if(esVacio(m)) errorMaxMonticulo("devolverRaiz" ,"El monticulo está vacio");
    return m.array[0];
}

void mostrarAnchura(tipoMaxMonticulo m){
    if(!esVacio(m))
        for(int i = 0; i < m.pos ;i++)
            printf("%d : %f\n",i+1, m.array[i].distancia);
    else
        errorMaxMonticulo("mostrarAnchura", "El monticulo está vacio");
}

bool esVacio(tipoMaxMonticulo m){
    return m.pos == -1;
}

bool estaLleno(tipoMaxMonticulo m){
    return m.numEl == m.pos;
}

void intercambio(tipoElementoMaxMonticulo *a, tipoElementoMaxMonticulo *b){
    tipoElementoMaxMonticulo aux;
    aux = *a;
    *a = *b;
    *b = aux;
}

void mostrarMaxMonticulo(tipoMaxMonticulo m){
    if(!esVacio(m)) {
        for(int i = 0; i < m.pos ;i++){
            printf("\n--------------------------------------------------\n");
            printf("\t(KNN %d) Valor en apertura: %f\n", i+1, m.array[i].s->apertura);
            printf("\t(KNN %d) Valor maximo: %f\n", i+1, m.array[i].s->valor_max_dia);
            printf("\t(KNN %d) Valor minimo: %f\n", i+1, m.array[i].s->valor_min_dia);
            printf("\t(KNN %d) Valor en cierre: %f\n", i+1, m.array[i].s->cierre);
            printf("\t(KNN %d) Volumen total: %f\n", i+1, m.array[i].s->volumen);
            printf("\t(KNN %d) RSI(7): %lf\n", i+1, m.array[i].s->RSI_7);
            printf("\t(KNN %d) RSI(14): %f\n", i+1, m.array[i].s->RSI_14);
            printf("\t(KNN %d) CCI(7): %f\n", i+1, m.array[i].s->CCI_7);
            printf("\t(KNN %d) CCI(14): %f\n", i+1, m.array[i].s->CCI_14);
            printf("\t(KNN %d) SMA(50): %f\n", i+1, m.array[i].s->SMA_50);
            printf("\t(KNN %d) EMA(50): %f\n", i+1, m.array[i].s->EMA_50);
            printf("\t(KNN %d) SMA(100): %f\n", i+1, m.array[i].s->SMA_100);
            printf("\t(KNN %d) EMA(100): %f\n", i+1, m.array[i].s->EMA_100);
            printf("\t(KNN %d) MACD: %f\n", i+1, m.array[i].s->MACD);
            printf("\t(KNN %d) Indice Bollinger: %f\n", i+1, m.array[i].s->bollinger);
            printf("\t(KNN %d) Rango efectivo(TR): %f\n", i+1, m.array[i].s->TR);
            printf("\t(KNN %d) Rango efectivo medio(ATR(7)): %f\n", i+1, m.array[i].s->ATR_7);
            printf("\t(KNN %d) Rango efectivo medio(ATR(14)) %f\n", i+1, m.array[i].s->ATR_14);
            printf("\t(KNN %d) Variacion: %d\n", i+1, m.array[i].s->variacion);
            printf("\n--------------------------------------------------\n");
        }
    } else {
        errorMaxMonticulo("mostrarMaxMonticulo", "El monticulo está vacio");
    }
}

void vaciarMaxMonticulo(tipoMaxMonticulo * m){
    m->pos = -1;
    m->numEl = 0;
}
