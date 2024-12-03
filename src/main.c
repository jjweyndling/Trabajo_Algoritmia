#include <stdio.h>
#include "cargarDatos.h"
#include "clasificar.h"

int main(){
    char * pathname = "../data/aapl_2014_2023.csv";
    listaStock l;
    tipoMaxMonticulo knn;
    t_stock stockSujeto;
    int k;
    nuevaLista(&l);
    cargarEntradas(pathname, &l);
    mostrarLista(l); // DEBUG
    printf("K: ");
    scanf("%d", &k);
    nuevoMaxMonticulo(&knn, k);
    printf("INTRODUCIR SUJETO A CLASIFICAR\n");
    printf("--------------------------------------------------\n");
    printf("\tValor en apertura: ");
    scanf("%f", &stockSujeto.apertura);
    printf("\tValor maximo: ");
    scanf("%f", &stockSujeto.valor_max_dia);
    printf("\tValor minimo: ");
    scanf("%f", &stockSujeto.valor_min_dia);
    printf("\tValor en cierre: ");
    scanf("%f", &stockSujeto.cierre);
    printf("\tVolumen total: ");
    scanf("%ld", &stockSujeto.volumen);
    printf("\tRSI(7): ");
    scanf("%f", &stockSujeto.RSI_7);
    printf("\tRSI(14): ");
    scanf("%f", &stockSujeto.RSI_14);
    printf("\tCCI(7): ");
    scanf("%f", &stockSujeto.CCI_7);
    printf("\tCCI(14): ");
    scanf("%f", &stockSujeto.CCI_14);
    printf("\tSMA(50): ");
    scanf("%f", &stockSujeto.SMA_50);
    printf("\tEMA(50): ");
    scanf("%f", &stockSujeto.EMA_50);
    printf("\tSMA(100): ");
    scanf("%f", &stockSujeto.SMA_100);
    printf("\tEMA(100): ");
    scanf("%f", &stockSujeto.EMA_100);
    printf("\tMACD: ");
    scanf("%f", &stockSujeto.MACD);
    printf("\tIndice Bollinger: ");
    scanf("%f", &stockSujeto.bollinger);
    printf("\tRango efectivo(TR): ");
    scanf("%f", &stockSujeto.TR);
    printf("\tRango efectivo medio(ATR(7)): ");
    scanf("%f", &stockSujeto.ATR_7);
    printf("\tRango efectivo medio(ATR(14)): ");
    scanf("%f", &stockSujeto.ATR_14);
    printf("--------------------------------------------------\n");    
    seleccionarKNN(l, &knn, stockSujeto);
    switch(predecirClase(knn)) {
        case(DECRECE):
            printf("La tendencia del stock es DECRECIENTE\n");
            break;
        case(NEUTRO):
            printf("La tendencia del stock es NEUTRAL\n");
            break;
        default:
            printf("La tendencia del stock es CRECIENTE\n");
            break;
    }
}