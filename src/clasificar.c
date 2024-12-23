#include <math.h>
#include <stdlib.h>
#include "clasificar.h"

float calcularDistancia(t_stock stock, t_stock modelo){
    return sqrt(
          (pow(modelo.apertura - stock.apertura, 2) * PESO_APERTURA) 
        + (pow(modelo.valor_max_dia - stock.valor_max_dia, 2) * PESO_VALORMAX) 
        + (pow(modelo.valor_min_dia - stock.valor_min_dia, 2) * PESO_VALORMIN) 
        + (pow(modelo.cierre - stock.cierre, 2) * PESO_CIERRE)
        + (pow(modelo.volumen - stock.volumen, 2) * PESO_VOLUMEN)
        + (pow(modelo.RSI_7 - stock.RSI_7, 2) * PESO_RSI7)
        + (pow(modelo.RSI_14 - stock.RSI_14, 2) * PESO_RSI14)
        + (pow(modelo.CCI_7 - stock.CCI_7, 2) * PESO_CCI7)
        + (pow(modelo.CCI_14 - stock.CCI_14, 2) * PESO_CCI14)
        + (pow(modelo.SMA_50 - stock.SMA_50, 2) * PESO_SMA50)
        + (pow(modelo.EMA_50 - stock.EMA_50, 2) * PESO_EMA50)
        + (pow(modelo.SMA_100 - stock.SMA_100, 2) * PESO_SMA100)
        + (pow(modelo.EMA_100 - stock.EMA_100, 2) * PESO_EMA100)
        + (pow(modelo.MACD - stock.MACD, 2) * PESO_MACD)
        + (pow(modelo.bollinger - stock.bollinger, 2) * PESO_BOLLINGER)
        + (pow(modelo.TR - stock.TR, 2) * PESO_TR)
        + (pow(modelo.ATR_7 - stock.ATR_7, 2) * PESO_ATR7)
        + (pow(modelo.ATR_14 - stock.ATR_14, 2) * PESO_ATR14)
    );
}

void seleccionarKNN(listaStock lista, tipoMaxMonticulo * knn, t_stock stock) {
    if(esNulaLista(lista)) {
        printf("La lista es nula\n");
        exit(1);
    }
    celdaStock *aux = lista.ini;
    vecino vecino_mas_distante, nuevo_vecino;
    vecino_mas_distante.distancia = 10000000.0; // Incializado en la distancia máxima
    while(aux != NULL) {
        nuevo_vecino.s = aux->s;
        nuevo_vecino.distancia = calcularDistancia(stock, *aux->s);
        if(!estaLleno(*knn)) {
            insertarMaxMonticulo(knn, nuevo_vecino);
        } else {
            if(vecino_mas_distante.distancia > nuevo_vecino.distancia) {
                eliminarMaxMonticulo(knn, vecino_mas_distante);
                insertarMaxMonticulo(knn, nuevo_vecino);
            }
        }
        vecino_mas_distante = devolverRaiz(*knn);
        aux = aux->sig;
    }
}

int predecirClase(tipoMaxMonticulo knn) {
    vecino vecino = devolverRaiz(knn);
    int claseCrece=0, claseDecrece=0, claseNeutro=0;
    float distanciaCrece=0, distanciaDecrece=0, distanciaNeutro=0;
    for(int i=0; i <= knn.pos; i++) {
        switch(vecino.s->variacion) {
            case DECRECE:
                claseDecrece++;
                distanciaDecrece += vecino.distancia;
                break;
            case NEUTRO:
                claseNeutro++;
                distanciaNeutro += vecino.distancia;
                break;
            default:
                claseCrece++;
                distanciaCrece += vecino.distancia;
                break;
        }
        vecino = knn.array[i];
    }
    if(claseCrece > claseDecrece && claseCrece > claseNeutro) {
        return CRECE;
    } else if(claseDecrece > claseCrece && claseDecrece > claseNeutro) {
        return DECRECE;
    } else if(claseNeutro > claseCrece && claseNeutro > claseDecrece) {
        return NEUTRO;
    } else { // Hay empate, se elige el que este a menor distancia total
        if(distanciaCrece < distanciaDecrece && distanciaCrece < distanciaNeutro) {
            return CRECE;
        } else if(distanciaDecrece < distanciaCrece && distanciaDecrece < distanciaNeutro) {
            return DECRECE;
        } else {
            return NEUTRO;
        }
    }
}
