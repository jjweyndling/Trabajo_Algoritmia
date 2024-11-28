#include <stdio.h>
#include "listaStock.h"
#include "maxMonticulo.h"
#include "cargarDatos.h"

int main(){
    listaStock l;
    tipoMaxMonticulo knn;
    int k;
    nuevaLista(&l);
    printf("K: ");
    scanf("%d", &k);
    nuevoMaxMonticulo(&knn, k);
    // cargarDatos(&fichero, &l);
    // Entrada del usuario: stockSujeto
    // seleccionarKNN(l, &knn, stockSujeto);
    switch(predecirClase(knn)) {
        case(-1):
            printf("La tendencia del stock es DECRECIENTE\n");
            break;
        case(0):
            printf("La tendencia del stock es NEUTRAL\n");
            break;
        default:
            printf("La tendencia del stock es CRECIENTE\n");
            break;
    }
}