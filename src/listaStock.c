#include "listaStock.h"
#include <float.h>
#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void errorListaStock(char * func, char * msg) {
    printf("ERROR (%s): %s\n", func, msg);
    exit(-1);
}

void nuevaLista(listaStock *lista, int k) {
    lista->ini = NULL;
    lista->fin = NULL;
    lista->vecinosMasCercanos = (vecino *)malloc(sizeof(vecino));
    lista->vecinosMasCercanos->s = (t_stock *)malloc(sizeof(vecino) * k);
}

void insertar(listaStock *lista, t_stock nuevoStock) {
    celdaStock *nueva;

    nueva = (celdaStock *)malloc(sizeof(celdaStock));
    nueva->s = (t_stock *)malloc(sizeof(t_stock));
    memcpy(nueva->s, &nuevoStock, sizeof(t_stock));
    if (esNulaLista(*lista)) {
        nueva->sig = NULL;
        lista->ini = nueva;
        lista->fin = nueva;
    } else {
        lista->fin->sig = nueva;
        nueva->sig = NULL;
        lista->fin = nueva;
    }
}

bool esNulaLista(listaStock p) { 
    return (p.ini == NULL); 
}

void mostrarLista(listaStock lista) {
    celdaStock *aux;
    int i=1;

    if ( esNulaLista(lista) ) 
        errorListaStock("mostrarLista", "La lista es nula");
    aux = lista.ini;
    while (aux != NULL) {
        printf("\n\nStock: %d\n", i);
        printf("Valor en apertura: %f\n", aux->s->apertura);
        printf("Valor maximo: %f\n", aux->s->valor_max_dia);
        printf("Valor minimo: %f\n", aux->s->valor_min_dia);
        printf("Valor en cierre: %f\n", aux->s->cierre);
        printf("Volumen total: %f\n", aux->s->volumen);
        printf("RSI(7): %f\n", aux->s->RSI_7);
        printf("RSI(14): %f\n", aux->s->RSI_14);
        printf("CCI(7): %f\n", aux->s->CCI_7);
        printf("CCI(14): %f\n", aux->s->CCI_14);
        printf("SMA(50): %f\n", aux->s->SMA_50);
        printf("EMA(50): %f\n", aux->s->EMA_50);
        printf("SMA(100): %f\n", aux->s->SMA_100);
        printf("EMA(100): %f\n", aux->s->EMA_100);
        printf("MACD: %f\n", aux->s->MACD);
        printf("Indice Bollinger: %f\n", aux->s->bollinger);
        printf("Rango efectivo(TR): %f\n", aux->s->TR);
        printf("Rango efectivo medio(ATR(7)): %f\n", aux->s->ATR_7);
        printf("Rango efectivo medio(ATR(14)) %f\n", aux->s->ATR_14);
        aux = aux->sig;
        i++;
    }
}

void vaciarLista(listaStock *lista) {
    celdaStock *aux, *aux2;

    if ( esNulaLista(*lista) ) 
        errorListaStock("vaciarLista", "La lista es nula");
    aux = lista->ini;
    while (aux != NULL) {
        aux2 = aux;
        aux = aux->sig;
        free(aux2->s);
        free(aux2);
    }
    lista->ini = NULL;
    lista->fin = NULL;
}

