#include "maxMonticulo.h"
#include <stdlib.h>
void nuevoMaxMonticulo(tipoMaxMonticulo *m, int numElem){
    
    m->numEl = numElem;
    m->array = (tipoElementoMaxMonticulo*)malloc(sizeof(tipoElementoMaxMonticulo)*numElem);
    m->pos = -1;
}

void insertarMaxMonticulo(tipoMaxMonticulo *m, tipoElementoMaxMonticulo e) {
    if (estaLleno(*m)) {
        printf("El montículo está lleno.\n");
        return;
    }

    // Incrementar la posición del último elemento e insertar el nuevo
    m->pos = m->pos + 1;
    m->array[m->pos] = e;

    int actual = m->pos;
    int padre = (actual - 1) / 2;

    // Ajustar el nuevo elemento hacia arriba en el montículo
    while (actual > 0 && m->array[padre] < e) { // Mientras el padre sea menor que el nuevo elemento
        intercambio(&m->array[actual], &m->array[padre]);
        actual = padre;
        padre = (actual - 1) / 2;
    }
}


void eliminarMaxElemento(tipoMaxMonticulo *m, tipoElementoMaxMonticulo e){
    if(esVacio(*m)){
        printf("Esta vacio \n");
    }
    else{
        int i = 0;
        while (m->array[i] != e && i < m->numEl)
        {
            i++;
        }
        if(m->array[i] == e){
            intercambio(&m->array[i],&m->array[m->pos]);
            m->pos--;
            //si tiene 2 hijos cambiarlo por el mayor
            if(2*i+1 >= m->pos && 2*i+2 >= m->pos){
                if(m->array[2*i+1] > m->array[2*i+2]){
                    if(m->array[2*i+1] > m->array[i])
                        intercambio(&m->array[2*i+1], &m->array[i]);

                }
                else{
                    if(m->array[2*i+2] > m->array[i])
                        intercambio(&m->array[2*i+2], &m->array[i]);
                }
            }
            //si tiene solo el hijo izquierdo se cambia si es mayor
            else if(2*i+1 >= m->pos){
                if(m->array[2*i+1] > m->array[i])
                        intercambio(&m->array[2*i+1], &m->array[i]);
            }


        }
        else
            printf("El elemento no esta");
        
    }

}

tipoElementoMaxMonticulo devolverRaiz(tipoMaxMonticulo m){
    if(!esVacio(m)){
        return m.array[0];
    }
    else
        printf("Monticulo vacio");
        exit(-1);
}

void mostrarAnchura(tipoMaxMonticulo m){
    if(!esVacio(m)){
        for(int i = 0; i < m.pos ;i++){
            printf(" %d",m.array[i]);
        }
    }
    else
        printf("vacio\n");
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
