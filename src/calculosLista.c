#include "calculosLista.h"

void calcularClase(listaStock lista, t_stock stock){
    celdaStock *aux = lista.ini;
    float distancia;
    float min = 1000000;
    while(aux != NULL){
        distancia = sqrt(pow(aux->s->apertura - stock.apertura, 2)
         + pow(aux->s->valor_max_dia - stock.valor_max_dia, 2) 
         + pow(aux->s->valor_min_dia - stock.valor_min_dia, 2) 
         + pow(aux->s->cierre - stock.cierre, 2) 
         + pow(aux->s->volumen - stock.volumen, 2) 
         + pow(aux->s->RSI_7 - stock.RSI_7, 2) 
         + pow(aux->s->RSI_14 - stock.RSI_14, 2) 
         + pow(aux->s->CCI_7 - stock.CCI_7, 2) 
         + pow(aux->s->CCI_14 - stock.CCI_14, 2) 
         + pow(aux->s->SMA_50 - stock.SMA_50, 2) 
         + pow(aux->s->EMA_50 - stock.EMA_50, 2) 
         + pow(aux->s->SMA_100 - stock.SMA_100, 2) 
         + pow(aux->s->EMA_100 - stock.EMA_100, 2) 
         + pow(aux->s->MACD - stock.MACD, 2) 
         + pow(aux->s->bollinger - stock.bollinger, 2) 
         + pow(aux->s->TR - stock.TR, 2) 
         + pow(aux->s->ATR_7 - stock.ATR_7, 2) 
         + pow(aux->s->ATR_14 - stock.ATR_14, 2));
        if(distancia < min){
            min = distancia;
            stock.variacion = aux->s->variacion;
        }
        aux = aux->sig;
    }
}

void calcularVecinosMasCercanos(listaStock s, t_stock stock, int k) {
    celdaStock *aux;
    int i, maxIndex;

    if (esNulaLista(s)) {
        printf("La lista es nula\n");
        return;
    }
    aux = s.ini;
    i = 0;
    for (int j = 0; j < k; j++) {
        s.vecinosMasCercanos[j].distancia = calcularDistancia(*aux->s, stock);
        s.vecinosMasCercanos[j].s = aux->s;
        aux = aux->sig;
    }
    while (aux != NULL) {
        i++;
        maxIndex = 0;
        for (int j = 1; j < k; j++) {
            if (s.vecinosMasCercanos[j].distancia > s.vecinosMasCercanos[maxIndex].distancia)
                maxIndex = j;
        }
        if (calcularDistancia(*aux->s, stock) < s.vecinosMasCercanos[maxIndex].distancia) {
            s.vecinosMasCercanos[maxIndex].distancia = calcularDistancia(*aux->s, stock);
            s.vecinosMasCercanos[maxIndex].s = aux->s;
        }
        aux = aux->sig;
    }
}