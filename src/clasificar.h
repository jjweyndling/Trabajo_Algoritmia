#ifndef CLASIFICAR_H
#define CLASIFICAR_H

#include "maxMonticulo.h"

#define PESO_APERTURA 1
#define PESO_VALORMAX 1
#define PESO_VALORMIN 1
#define PESO_CIERRE 1
#define PESO_VOLUMEN 1
#define PESO_RSI7 1
#define PESO_RSI14 1
#define PESO_CCI7 1
#define PESO_CCI14 1
#define PESO_SMA50 1
#define PESO_EMA50 1
#define PESO_SMA100 1
#define PESO_EMA100 1
#define PESO_MACD 1
#define PESO_BOLLINGER 1
#define PESO_TR 1
#define PESO_ATR7 1
#define PESO_ATR14 1


void seleccionarKNN(listaStock, tipoMaxMonticulo *, t_stock);
int predecirClase(tipoMaxMonticulo);

#endif
