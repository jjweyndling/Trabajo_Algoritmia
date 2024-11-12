#include "calculosLista.h"

void calcularDistancia(listaStock lista, t_stock per){
    celdaStock *aux = lista.ini;
    float distancia;
    float min = 1000000;
    while(aux != NULL){
        distancia = sqrt(pow(aux->s->apertura - per.apertura, 2) + pow(aux->s->valor_max_dia - per.valor_max_dia, 2) + pow(aux->s->valor_min_dia - per.valor_min_dia, 2) + pow(aux->s->cierre - per.cierre, 2) + pow(aux->s->volumen - per.volumen, 2) + pow(aux->s->RSI_7 - per.RSI_7, 2) + pow(aux->s->RSI_14 - per.RSI_14, 2) + pow(aux->s->CCI_7 - per.CCI_7, 2) + pow(aux->s->CCI_14 - per.CCI_14, 2) + pow(aux->s->SMA_50 - per.SMA_50, 2) + pow(aux->s->EMA_50 - per.EMA_50, 2) + pow(aux->s->SMA_100 - per.SMA_100, 2) + pow(aux->s->EMA_100 - per.EMA_100, 2) + pow(aux->s->MACD - per.MACD, 2) + pow(aux->s->bollinger - per.bollinger, 2) + pow(aux->s->TR - per.TR, 2) + pow(aux->s->ATR_7 - per.ATR_7, 2) + pow(aux->s->ATR_14 - per.ATR_14, 2));
        if(distancia < min){
            min = distancia;
            per.variacion = aux->s->variacion;
        }
        aux = aux->sig;
    }
}

void calcularVecinosMasCercanos(listaStock p, t_stock per, int k) {
    celdaStock *aux;
    int i, maxIndex;

    if (esNulaLista(p)) {
        printf("La lista es nula\n");
        return;
    }
    aux = p.ini;
    i = 0;
    for (int j = 0; j < k; j++) {
        p.vecinosMasCercanos[j].distancia = calcularDistancia(*aux->p, per);
        p.vecinosMasCercanos[j].p = aux->p;
        aux = aux->sig;
    }
    while (aux != NULL) {
        i++;
        maxIndex = 0;
        for (int j = 1; j < k; j++) {
            if (p.vecinosMasCercanos[j].distancia >
                p.vecinosMasCercanos[maxIndex].distancia) {
                maxIndex = j;
            }
        }
        if (calcularDistancia(*aux->p, per) <
            p.vecinosMasCercanos[maxIndex].distancia) {
            p.vecinosMasCercanos[maxIndex].distancia =
                calcularDistancia(*aux->p, per);
            p.vecinosMasCercanos[maxIndex].p = aux->p;
        }
        aux = aux->sig;
    }
}