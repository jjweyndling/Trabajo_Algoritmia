#include "listaStock.h"
#include <float.h>
#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static void nuevoVecinosMasCercanos(vecino *, int);

float calcularDistancia(t_stock vecino, t_stock per) {
    float diferencia, distancia;

    return distancia;
}

void nuevaLista(listaStock *p, int k) {
    p->ini = NULL;
    p->fin = NULL;
    if ((p->vecinosMasCercanos = (vecino *)malloc(sizeof(vecino))) == NULL) {
        printf("Error asignando memoria para p->vecinos, en inicializar");
        return;
    }
    nuevoVecinosMasCercanos(p->vecinosMasCercanos, k);
}

void insertar(listaStock *p, t_stock nuevaStock) {
    celdaStock *nueva;

    if ((nueva = (celdaStock *)malloc(sizeof(celdaStock))) == NULL) {
        printf("Error en insertar, no se puede asignar mas memoria nueva\n");
        return;
    }

    if ((nueva->s = (t_stock *)malloc(sizeof(t_stock))) == NULL) {
        printf("Error en insertar, no se puede asignarm memoria a nueva->p\n");
    }

    memcpy(nueva->s, &nuevaStock, sizeof(t_stock));

    if (esNulaLista(*p)) {
        nueva->sig = NULL;
        p->ini = nueva;
        p->fin = nueva;
        return;
    }

    p->fin->sig = nueva;
    nueva->sig = NULL;
    p->fin = nueva;
}

bool esNulaLista(listaStock p) { 
    return (p.ini == NULL); 
}

void mostrarLista(listaStock p) {
    celdaStock *aux;
    int i;

    if (esNulaLista(p)) {
        printf("La lista es nula\n");
        return;
    }
    i = 1;
    aux = p.ini;
    while (aux != NULL) {
        printf("\n\nStock: %d\n", i);
        if ( == 0.0) {
            printf("Genero: Masculino\n");
        } else {
            printf("Genero: Femenino\n");
        }
        printf("Edad: %g\n", );
        printf("Hipertension: %f\n", );
        printf("Enfermedad corazon: %g\n", );
        printf("BMI: %f\n", );
        printf("HbA1c: %f\n", );
        printf("Nivel de glucosa en sangre: %f\n", );
        printf("Diabetes: %g\n", );
        aux = aux->sig;
        i++;
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

void vaciarLista(listaStock *p) {
    celdaStock *aux, *aux2;

    if (esNulaLista(*p)) {
        printf("La lista es nula\n");
        return;
    }

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

static void nuevoVecinosMasCercanos(vecino *v, int k) {
    if ((v->s = (t_stock *)malloc(sizeof(vecino) * k)) == NULL) {
        printf("Error asignando memoria para p->vecinos->vecino en "
               "nuevoVecinosMasCercanos\n");
        return;
    }
}