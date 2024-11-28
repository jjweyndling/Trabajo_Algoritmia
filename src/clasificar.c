#include "clasificar.h"

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

void seleccionarKNN(listaStock lista, tipoMaxMonticulo * knn, int k, t_stock stock) {
    if( esNulaLista(lista)) {
        printf("La lista es nula\n");
        exit(1);
    }
    nuevoMaxMonticulo(&knn, k);
    celdaStock *aux = lista.ini;
    vecino vecino_mas_distante, nuevo_vecino;
    while(aux != NULL) {
        vecino_mas_distante = mostrarMaximo(*knn);
        nuevo_vecino.distancia = calcularDistancia(stock, *aux->s);
        if(vecino_mas_distante.distancia > nuevo_vecino.distancia) {
            nuevo_vecino.s = aux->s;
            eliminarMaxMonticulo(&m, vecino_mas_distante);
            insertarMaxMonticulo(&m, nuevo_vecino);
        }
        aux = aux->sig;
    }
}

void predecirClase(tipoMaxMonticulo knn) {
    // Recorrer monticulo y contar nº de apariciones de cada clase
    // Predecir la clase mas repetida
}