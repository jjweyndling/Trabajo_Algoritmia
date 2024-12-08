#include <stdio.h>
#include <string.h>
#include "cargarDatos.h"
#include "clasificar.h"

int main(){
    char pathname[120] = "../data/aapl_2014_2023.csv";
    listaStock lista;
    tipoMaxMonticulo knn;
    t_stock stockSujeto, maximo, minimo;
    int k, aciertos=0, opcion, nMuestras, cont=0;
    nuevaLista(&lista);
    cargarEntradas(pathname, &lista);
    normalizarLista(&lista, &maximo, &minimo);
    // mostrarLista(lista); // DEBUG
    printf("K: ");
    scanf("%d", &k);
    nuevoMaxMonticulo(&knn, k);
    printf("Pulse 1 si desea comprobar la precision con un archivo de testeo, 0 si desea introducir los datos de un sujeto manualmente para clasificar: ");
    scanf("%d", &opcion);
    if(opcion) {
        char test_pathname[120];  
        printf("Elige el número de muestras\n0 - 200 \n1 - 500\nMuestras:");
        scanf("%d", &nMuestras);
        if(!nMuestras) {
            strcpy(pathname, "../data/data_test_200/data1.csv");
            strcpy(test_pathname, "../data/data_test_200/test_200.csv");
        } else {
            strcpy(pathname, "../data/data_test_500/data2.csv");
            strcpy(test_pathname, "../data/data_test_500/test_500.csv");
        }
        listaStock lista_test;    
        t_stock *stockTest;
        nuevaLista(&lista_test);
        cargarEntradas(test_pathname, &lista_test);
        // mostrarLista(lista_test); // DEBUG
        while(!esNulaLista(lista_test)) {
            stockTest = obtenerPrimero(lista_test);
            normalizarStock(stockTest, maximo, minimo);
            seleccionarKNN(lista, &knn, *stockTest);
            // mostrarMaxMonticulo(knn); // DEBUG   
            switch(predecirClase(knn)) {
                case(DECRECE):
                    if(stockTest->variacion == DECRECE) aciertos++;
                    break;
                case(NEUTRO):
                    if(stockTest->variacion == NEUTRO) aciertos++;
                    break;
                default:
                    if(stockTest->variacion == CRECE) aciertos++;
                    break;
            }
            cont++;
            vaciarMaxMonticulo(&knn);
            eliminarPrimero(&lista_test);
        }
        printf("Eficacia: %f\n", (float)aciertos/cont*100); 
    } else {
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
        scanf("%lf", &stockSujeto.volumen);
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
        normalizarStock(&stockSujeto, maximo, minimo);
        seleccionarKNN(lista, &knn, stockSujeto);
        // mostrarMaxMonticulo(knn); // DEBUG
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
}