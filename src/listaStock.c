#include "listaStock.h"
#include <float.h>
#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static void nuevoVecinosMasCercanos(vecino *, int);

float calcularDistancia(Persona vecino, Persona per) {
    float diferencia, distancia;
    // Valores ponderados por peso de relevancia en el diagnóstico del
    // diabetes
    diferencia = 0;
    diferencia += pow(vecino.genero - per.genero, 2) * FACTOR_GENERO;
    diferencia += pow(vecino.edad - per.edad, 2) * FACTOR_EDAD;
    diferencia +=
        pow(vecino.hipertension - per.hipertension, 2) * FACTOR_HIPERTENSION;
    diferencia += pow(vecino.enfermedad_corazon - per.enfermedad_corazon, 2) *
                  FACTOR_ENF_CORAZON;
    diferencia +=
        pow(vecino.historia_fumador - per.historia_fumador, 2) * FACTOR_FUMADOR;
    diferencia += pow(vecino.bmi - per.bmi, 2) * FACTOR_BMI;
    diferencia += pow(vecino.HbA1c - per.HbA1c, 2) * FACTOR_HBA1C;
    diferencia +=
        pow(vecino.nivel_glucosa_sangre - per.nivel_glucosa_sangre, 2) *
        FACTOR_GLUCOSA_EN_SANGRE;
    distancia = sqrt(diferencia);

    return distancia;
}

void nuevaLista(listaPersona *p, int k) {
    p->ini = NULL;
    p->fin = NULL;
    if ((p->vecinosMasCercanos = (vecino *)malloc(sizeof(vecino))) == NULL) {
        printf("Error asignando memoria para p->vecinos, en inicializar");
        return;
    }
    nuevoVecinosMasCercanos(p->vecinosMasCercanos, k);
}

void insertar(listaPersona *p, Persona nuevaPersona) {
    celdaPersona *nueva;

    if ((nueva = (celdaPersona *)malloc(sizeof(celdaPersona))) == NULL) {
        printf("Error en insertar, no se puede asignar mas memoria nueva\n");
        return;
    }

    if ((nueva->p = (Persona *)malloc(sizeof(Persona))) == NULL) {
        printf("Error en insertar, no se puede asignarm memoria a nueva->p\n");
    }

    memcpy(nueva->p, &nuevaPersona, sizeof(Persona));

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

bool esNulaLista(listaPersona p) { return (p.ini == NULL); }

void mostrarLista(listaPersona p) {
    celdaPersona *aux;
    int i;

    if (esNulaLista(p)) {
        printf("La lista es nula\n");
        return;
    }
    i = 1;
    aux = p.ini;
    while (aux != NULL) {
        printf("\n\nPersona: %d\n", i);
        if (aux->p->genero == 0.0) {
            printf("Genero: Masculino\n");
        } else {
            printf("Genero: Femenino\n");
        }
        printf("Edad: %g\n", aux->p->edad);
        printf("Hipertension: %f\n", aux->p->hipertension);
        printf("Enfermedad corazon: %g\n", aux->p->enfermedad_corazon);
        if (aux->p->historia_fumador == 0.0) {
            printf("Historia fumador: nunca\n");
        } else if (aux->p->historia_fumador == 1.0) {
            printf("Historia fumador: antiguo\n");
        } else if (aux->p->historia_fumador == 2.0) {
            printf("Historia fumador: sin informacion\n");
        } else if (aux->p->historia_fumador == 3.0) {
            printf("Historia fumador: actualmente no\n");
        } else if (aux->p->historia_fumador == 4.0) {
            printf("Historia fumador: de vez en cuando\n");
        } else if (aux->p->historia_fumador == 5.0) {
            printf("Historia fumador: fumador\n");
        }
        printf("BMI: %f\n", aux->p->bmi);
        printf("HbA1c: %f\n", aux->p->HbA1c);
        printf("Nivel de glucosa en sangre: %f\n",
               aux->p->nivel_glucosa_sangre);
        printf("Diabetes: %g\n", aux->p->diabetes);
        aux = aux->sig;
        i++;
    }
}

void calcularVecinosMasCercanos(listaPersona p, Persona per, int k) {
    celdaPersona *aux;
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

void vaciarLista(listaPersona *p) {
    celdaPersona *aux, *aux2;

    if (esNulaLista(*p)) {
        printf("La lista es nula\n");
        return;
    }

    aux = p->ini;
    while (aux != NULL) {
        aux2 = aux;
        aux = aux->sig;
        free(aux2->p);
        free(aux2);
    }

    p->ini = NULL;
    p->fin = NULL;
}

static void nuevoVecinosMasCercanos(vecino *v, int k) {
    if ((v->p = (Persona *)malloc(sizeof(vecino) * k)) == NULL) {
        printf("Error asignando memoria para p->vecinos->vecino en "
               "nuevoVecinosMasCercanos\n");
        return;
    }
}