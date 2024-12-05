#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cargarDatos.h"

static void leerEntrada(FILE *f, char *buf) {
    fscanf(f, "%[^\n]", buf);
    fgetc(f);
}

static void guardarStock(char *entrada, listaStock *lista_stocks) {
    t_stock s;
    char *token;
    char **atr;
    atr = (char **)malloc(MAX_BUF_SIZE * sizeof(char *));
    token = strtok(entrada, ",");
    int i = 0;
    token = strtok(NULL, ","); // El primer atributo (fecha) no nos interesa
    while (token != NULL) {
        if (strlen(token) > 0) {
            atr[i] = (char *)malloc((strlen(token) + 1) * sizeof(char)); // Espacio suficiente para el tamaño del token+1 
            strcpy(atr[i], token);
            i++;
        }
        token = strtok(NULL, ",");
    }
    
    s.apertura = strtof(atr[0], NULL);
    s.valor_max_dia = strtof(atr[1], NULL);
    s.valor_min_dia = strtof(atr[2], NULL);
    s.cierre = strtof(atr[3], NULL);
    s.volumen = strtod(atr[4], NULL);
    s.RSI_7 = strtof(atr[5], NULL);
    s.RSI_14 = strtof(atr[6], NULL);
    s.CCI_7 = strtof(atr[7], NULL);
    s.CCI_14 = strtof(atr[8], NULL);
    s.SMA_50 = strtof(atr[9], NULL);
    s.EMA_50 = strtof(atr[10], NULL);
    s.SMA_100 = strtof(atr[11], NULL);
    s.EMA_100 = strtof(atr[12], NULL);
    s.MACD = strtof(atr[13], NULL);
    s.bollinger = strtof(atr[14], NULL);
    s.TR = strtof(atr[15], NULL);
    s.ATR_7 = strtof(atr[16], NULL);
    s.ATR_14 = strtof(atr[17], NULL);
    s.variacion = atoi(atr[18]);
    if(!strcmp(atr[18], "bullish"))
        s.variacion = 1;
    if(!strcmp(atr[18], "bearish"))
        s.variacion = -1;
    if(!strcmp(atr[18], "neutral"))
        s.variacion = 0;
    insertar(lista_stocks, s);
}

void cargarEntradas(char *file, listaStock *lista) {
    FILE *f;
    char buffer[MAX_BUF_SIZE];
    if ((f = fopen(file, "r")) == NULL) {
        printf("No se ha podido abrir el archivo\n");
        exit(1);
    }
    leerEntrada(f, buffer); // Tratamiento inicial: saltar la cabecera con la lista de atributos
    while (!feof(f)) {
        leerEntrada(f, buffer);
        if (strlen(buffer) > 30) // Para evitar lecturas erroneas (cada entrada stock tiene al menos 30 caracteres) <-- ESTO HAY QUE REVISAR 
            guardarStock(buffer, lista);
            
    }
    fclose(f);
}