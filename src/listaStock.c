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

void nuevaLista(listaStock *p, int k) {
    p->ini = NULL;
    p->fin = NULL;
    p->vecinosMasCercanos = (vecino *)malloc(sizeof(vecino))
    p->vecinosMasCercanos->s = (t_stock *)malloc(sizeof(vecino) * k)
}

void insertar(listaStock *s, t_stock nuevoStock) {
    celdaStock *nueva;

    nueva = (celdaStock *)malloc(sizeof(celdaStock));
    nueva->s = (t_stock *)malloc(sizeof(t_stock));
    memcpy(nueva->s, &nuevoStock, sizeof(t_stock));
    if (esNulaLista(*p)) {
        nueva->sig = NULL;
        p->ini = nueva;
        p->fin = nueva;
    } else {
        p->fin->sig = nueva;
        nueva->sig = NULL;
        p->fin = nueva;
    }
}

bool esNulaLista(listaStock p) { 
    return (p.ini == NULL); 
}

void mostrarLista(listaStock s) {
    celdaStock *aux;
    int i=1;

    if ( esNulaLista(p) ) 
        errorListaStock("mostrarLista", "La lista es nula");
    aux = s.ini;
    while (aux != NULL) {
        printf("\n\nStock: %d\n", i);
        printf("Valor en apertura: %f\n", s.apertura);
        printf("Valor maximo: %f\n", s.valor_max_dia);
        printf("Valor minimo: %f\n", s.valor_min_dia);
        printf("Valor en cierre: %f\n", s.cierre);
        printf("Volumen total: %f\n", s.volumen);
        printf("RSI(7): %f\n", s.RSI_7);
        printf("RSI(14): %f\n", s.RSI_14);
        printf("CCI(7): %f\n", s.CCI_7);
        printf("CCI(14): %f\n", s.CCI_14);
        printf("SMA(50): %f\n", s.SMA_50);
        printf("EMA(50): %f\n", s.EMA_50);
        printf("SMA(100): %f\n", s.SMA_100);
        printf("EMA(100): %f\n", s.EMA_100);
        printf("MACD: %f\n", s.MACD);
        printf("Indice Bollinger: %f\n", s.bollinger);
        printf("Rango efectivo(TR): %f\n", s.TR);
        printf("Rango efectivo medio(ATR(7)): %f\n", s.ATR_7);
        printf("Rango efectivo medio(ATR(14)) %f\n", s.ATR_14);
        aux = aux->sig;
        i++;
    }
}

void vaciarLista(listaStock *p) {
    celdaStock *aux, *aux2;

    if ( esNulaLista(*p) ) 
        errorListaStock("vaciarLista", "La lista es nula");
    aux = p->ini;
    while (aux != NULL) {
        aux2 = aux;
        aux = aux->sig;
        free(aux2->s);
        free(aux2);
    }
    p->ini = NULL;
    p->fin = NULL;
}

