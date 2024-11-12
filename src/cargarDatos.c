#include "listaStock.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void cargarStocks(char *file, listaPersona *pacientes) {
    FILE *f;
    char buffer[LECTURA_MAX];

    if ((f = fopen(file, "r")) == NULL) {
        printf("No se ha podido abrir el archivo\n");
        exit(1);
    }
    leePaciente(f, buffer); // Tratamiento inicial: saltar la cabecera con la lista de atributos
    while (!feof(f)) {
        leePaciente(f, buffer);
        if (strlen(buffer) > 30) { // Para evitar lecturas erróneas (cada entrada de paciente tiene al menos 30 carácteres)
        
            guardaPaciente(buffer, pacientes);
        }
    }
    fclose(f);
}

static void leePaciente(FILE *f, char *buf) {
    fscanf(f, "%[^\n]", buf);
    fgetc(f);
}

static void guardaPaciente(const char *atr, listaPersona *lista_pacientes) {
    Persona p;
    char **atributos;
    char *copia, *token;
    int i = 1;

    copia = (char *)malloc((strlen(atr) + 1) * sizeof(char));
    strcpy(copia, atr);

    token = strtok(copia, ",");
    while (token != NULL) {
        if (strlen(token) > 0)
            i++;
        token = strtok(NULL, ",");
    }

    atributos = (char **)malloc(i * sizeof(char *));

    token = strtok((char *)atr, ",");
    i = 0;
    while (token != NULL) {
        if (strlen(token) > 0) {
            atributos[i] = (char *)malloc((strlen(token) + 1) * sizeof(char));
            strcpy(atributos[i], token);
            i++;
        }

        token = strtok(NULL, ",");
    }

    /*
     *  //Imprime los datos recogidos, para asegurarse de que son correctos
        for (int i = 0; i < 9; i ++)
        {
            printf ("%s\n", atributos [i]);
        }

        printf ("\n");
        */

    if (!strcmp(atributos[0], "Male")) {
        p.genero = 0.0;
    }

    else {
        p.genero = 1.0;
    }

    p.edad = strtof(atributos[1], NULL);

    p.hipertension = strtof(atributos[2], NULL);

    p.enfermedad_corazon = strtof(atributos[3], NULL);

    if (!strcmp(atributos[4], "never")) {
        p.historia_fumador = 0.0;
    }

    else if (!strcmp(atributos[4], "former")) {
        p.historia_fumador = 1.0;
    }

    else if (!strcmp(atributos[4], "No Info")) {
        p.historia_fumador = 2.0;
    }

    else if (!strcmp(atributos[4], "ever")) {
        p.historia_fumador = 3.0;
    }

    else if (!strcmp(atributos[4], "not current")) {
        p.historia_fumador = 4.0;
    }

    else if (!strcmp(atributos[4], "current")) {
        p.historia_fumador = 5.0;
    }

    else {
        p.historia_fumador = 2.0;
    }

    p.bmi = strtof(atributos[5], NULL);

    p.HbA1c = strtof(atributos[6], NULL);

    p.nivel_glucosa_sangre = strtof(atributos[7], NULL);

    p.diabetes = strtof(atributos[8], NULL);

    insertar(lista_pacientes, p);
}