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
    if (estaLleno(*m)) 
        errorMaxMonticulo("insertarMaxMonticulo", "El montículo está lleno");
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
    if(esVacio(*m)) {
        errorMaxMonticulo("eliminarMaxMonticulo", "El monticulo está vacio");
    } else {
        int i = 0;
        while (m->array[i].distancia != e.distancia && i < m->numEl)
            i++;
        if(m->array[i].distancia == e.distancia) {
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
        } else {
            printf("El elemento no esta");        
        }
    }
}

tipoElementoMaxMonticulo devolverRaiz(tipoMaxMonticulo m) {
    if(esVacio(m))
        errorMaxMonticulo("devolverRaiz" ,"El monticulo está vacio");
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
