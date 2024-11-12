#include "listaStock.h"
#include"cargarDatos.h"

void cargarStocks(char *file, listaStock *entradas) {
    FILE *f;
    char buffer[LECTURA_MAX];

    if ((f = fopen(file, "r")) == NULL) {
        printf("No se ha podido abrir el archivo\n");
        exit(1);
    }
    leePaciente(f, buffer); // Tratamiento inicial: saltar la cabecera con la lista de atributos
    while (!feof(f)) {
        leePaciente(f, buffer);
        if (strlen(buffer) > 30) { // Para evitar lecturas erroneas (cada entrada de paciente tiene al menos 30 caracteres)
        
            guardaPaciente(buffer, pacientes);
        }
    }
    fclose(f);
}

static void leerPaciente(FILE *f, char *buf) {
    fscanf(f, "%[^\n]", buf);
    fgetc(f);
}

static void guardarStock(const char *atr, listaStock *lista_stocks) {
    t_stock s;
    char **atr;
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
    atr = (char **)malloc(i * sizeof(char *));
    token = strtok((char *)atr, ",");
    i = 0;
    while (token != NULL) {
        if (strlen(token) > 0) {
            atr[i] = (char *)malloc((strlen(token) + 1) * sizeof(char));
            strcpy(atr[i], token);
            i++;
        }
        token = strtok(NULL, ",");
    }

    /*
        //Imprime los datos recogidos, para asegurarse de que son correctos
        for (int i = 0; i < 9; i ++)
        {
            printf ("%s\n", atr[i]);
        }

        printf ("\n");
    */

    s.apertura = atr[0];
    s.valor_max_dia = strtof(atr[1], NULL);
    s.valor_min_dia = strtof(atr[2], NULL);
    s.cierre = strtol(atr[3], NULL);
    s.volumen = strtof(atr[4], NULL);
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
    if(!strcmp(atr[18], "bullish")) {
        s.variacion = 1;
    } 
    if(!strcmp(atr[18], "bearish")) {
        s.variacion = -1;
    }
    if(!strcmp(atr[18], "neutral")) {
        s.variacion = 0;
    }
    insertar(lista_stocks, s);
}

void insertar(listaStock *s, t_stock nuevoStock) {
    celdaStock *nueva;

    nueva = (celdaStock *)malloc(sizeof(celdaStock))
    nueva->s = (t_stock *)malloc(sizeof(t_stock))
    memcpy(nueva->s, &nuevoStock, sizeof(t_stock));
    if (esNulaLista(*s)) {
        nueva->sig = NULL;
        s->ini = nueva;
        s->fin = nueva;
        return;
    }
    s->fin->sig = nueva;
    nueva->sig = NULL;
    s->fin = nueva;
}

void imprimirLista(listaStock lista){
    celdaStock *aux = lista.ini;
    while(aux != NULL){
        printf("Apertura: %f\n", aux->s->apertura);
        printf("Valor maximo del dia: %f\n", aux->s->valor_max_dia);
        printf("Valor minimo del dia: %f\n", aux->s->valor_min_dia);
        printf("Cierre: %f\n", aux->s->cierre);
        printf("Volumen: %ld\n", aux->s->volumen);
        printf("RSI 7: %f\n", aux->s->RSI_7);
        printf("RSI 14: %f\n", aux->s->RSI_14);
        printf("CCI 7: %f\n", aux->s->CCI_7);
        printf("CCI 14: %f\n", aux->s->CCI_14);
        printf("SMA 50: %f\n", aux->s->SMA_50);
        printf("EMA 50: %f\n", aux->s->EMA_50);
        printf("SMA 100: %f\n", aux->s->SMA_100);
        printf("EMA 100: %f\n", aux->s->EMA_100);
        printf("MACD: %f\n", aux->s->MACD);
        printf("Bollinger: %f\n", aux->s->bollinger);
        printf("TR: %f\n", aux->s->TR);
        printf("ATR 7: %f\n", aux->s->ATR_7);
        printf("ATR 14: %f\n", aux->s->ATR_14);
        printf("Variacion: %f\n", aux->s->variacion);
        aux = aux->sig;
    }