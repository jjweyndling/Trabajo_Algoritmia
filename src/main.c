#include <stdio.h>
#include "cargarDatos.h"
#include "clasificar.h"

#define PATHNAME "Trabajo_Algoritmia/data/aapl_2014_2023.csv"

int main(){
    listaStock l;
    tipoMaxMonticulo knn;
    int k;
    nuevaLista(&l);
    printf("K: ");
    scanf("%d", &k);
    nuevoMaxMonticulo(&knn, k);
    cargarEntradas(PATHNAME, &l);
    // Entrada del usuario: stockSujeto
    // seleccionarKNN(l, &knn, stockSujeto);
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