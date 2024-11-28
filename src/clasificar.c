#include <math.h>
#include "clasificar.h"

#define MAX(X, Y) (((X) > (Y)) ? (X) : (Y))

float calcularDistancia(t_stock stock, t_stock modelo){
    return sqrt(
          pow(modelo.apertura - stock.apertura, 2)
        + pow(modelo.valor_max_dia - stock.valor_max_dia, 2) 
        + pow(modelo.valor_min_dia - stock.valor_min_dia, 2) 
        + pow(modelo.cierre - stock.cierre, 2) 
        + pow(modelo.volumen - stock.volumen, 2) 
        + pow(modelo.RSI_7 - stock.RSI_7, 2) 
        + pow(modelo.RSI_14 - stock.RSI_14, 2) 
        + pow(modelo.CCI_7 - stock.CCI_7, 2) 
        + pow(modelo.CCI_14 - stock.CCI_14, 2) 
        + pow(modelo.SMA_50 - stock.SMA_50, 2) 
        + pow(modelo.EMA_50 - stock.EMA_50, 2) 
        + pow(modelo.SMA_100 - stock.SMA_100, 2) 
        + pow(modelo.EMA_100 - stock.EMA_100, 2) 
        + pow(modelo.MACD - stock.MACD, 2) 
        + pow(modelo.bollinger - stock.bollinger, 2) 
        + pow(modelo.TR - stock.TR, 2) 
        + pow(modelo.ATR_7 - stock.ATR_7, 2) 
        + pow(modelo.ATR_14 - stock.ATR_14, 2)
    );
}

void seleccionarKNN(listaStock lista, tipoMaxMonticulo * knn, t_stock stock) {
    if(esNulaLista(lista)) {
        printf("La lista es nula\n");
        exit(1);
    }
    celdaStock *aux = lista.ini;
    vecino vecino_mas_distante, nuevo_vecino;
    vecino_mas_distante.distancia = 1; // Incializado en la distancia máxima
    while(aux != NULL) {
        nuevo_vecino.distancia = calcularDistancia(stock, *aux->s);
        if(vecino_mas_distante.distancia > nuevo_vecino.distancia) {
            nuevo_vecino.s = aux->s;
            eliminarMaxMonticulo(&knn, vecino_mas_distante);
            insertarMaxMonticulo(&knn, nuevo_vecino);
        }
        vecino_mas_distante = devolverRaiz(*knn);
        aux = aux->sig;
    }
}

int predecirClase(tipoMaxMonticulo knn) {
    vecino vecino = devolverRaiz(knn);
    int claseCrece, claseDecrece, claseNeutro;
    for(int i=0; i <= knn.pos; i++) {
        switch(vecino.s->variacion) {
            case -1:
                claseDecrece++;
            case 0:
                claseNeutro++;
            case 1:
                claseCrece++;
        }
        vecino = knn.array[i];
    }
    // Devolver el nº correspondiente a la clase más repetida
}