#include <stdio.h>
#include <stdlib.h>
#include "listaStock.h"

void errorListaStock(char * func, char * msg) {
    printf("ERROR (%s): %s\n", func, msg);
    exit(-1);
}

void nuevaLista(listaStock *lista) {
    lista->ini = NULL;
    lista->fin = NULL;
}

void insertar(listaStock *lista, t_stock nuevoStock) {
    celdaStock *nueva = (celdaStock *)malloc(sizeof(celdaStock));
    nueva->s = (t_stock *)malloc(sizeof(t_stock));
    memcpy(nueva->s, &nuevoStock, sizeof(t_stock));
    if (esNulaLista(*lista)) {
        nueva->sig = NULL;
        lista->ini = nueva;
        lista->fin = nueva;
        return;
    }
    lista->fin->sig = nueva;
    nueva->sig = NULL;
    lista->fin = nueva;
}

bool esNulaLista(listaStock p) { 
    return (p.ini == NULL); 
}

void mostrarLista(listaStock lista) {
    if ( esNulaLista(lista) ) 
        errorListaStock("mostrarLista", "La lista es nula");
    int i=1;
    celdaStock *aux = lista.ini;
    while (aux != NULL) {
        printf("\n\n--------------------------------------------------\n");
        printf("Stock: %d\n", i++);
        printf("\tValor en apertura: %f\n", aux->s->apertura);
        printf("\tValor maximo: %f\n", aux->s->valor_max_dia);
        printf("\tValor minimo: %f\n", aux->s->valor_min_dia);
        printf("\tValor en cierre: %f\n", aux->s->cierre);
        printf("\tVolumen total: %f\n", aux->s->volumen);
        printf("\tRSI(7): %f\n", aux->s->RSI_7);
        printf("\tRSI(14): %f\n", aux->s->RSI_14);
        printf("\tCCI(7): %f\n", aux->s->CCI_7);
        printf("\tCCI(14): %f\n", aux->s->CCI_14);
        printf("\tSMA(50): %f\n", aux->s->SMA_50);
        printf("\tEMA(50): %f\n", aux->s->EMA_50);
        printf("\tSMA(100): %f\n", aux->s->SMA_100);
        printf("\tEMA(100): %f\n", aux->s->EMA_100);
        printf("\tMACD: %f\n", aux->s->MACD);
        printf("\tIndice Bollinger: %f\n", aux->s->bollinger);
        printf("\tRango efectivo(TR): %f\n", aux->s->TR);
        printf("\tRango efectivo medio(ATR(7)): %f\n", aux->s->ATR_7);
        printf("\tRango efectivo medio(ATR(14)) %f\n", aux->s->ATR_14);
        printf("\tVariacion: %d\n", aux->s->variacion);
        printf("--------------------------------------------------\n");
        aux = aux->sig;
    }
}

void vaciarLista(listaStock *lista) {
    if (esNulaLista(*lista)) 
        errorListaStock("vaciarLista", "La lista es nula");
    celdaStock *aux = lista->ini, *aux2;
    while (aux != NULL) {
        aux2 = aux;
        aux = aux->sig;
        free(aux2);
    }
    lista->ini = NULL;
    lista->fin = NULL;
}

