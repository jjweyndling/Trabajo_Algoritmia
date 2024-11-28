all: main cargarDatos

main: main.c cargarDatos clasificar 
	gcc main.c -o main *.o -Wall

clasificar: clasificar.c maxMonticulo
	gcc -c clasificar.c listaStock.o maxMonticulo.o -Wall

cargarDatos: cargarDatos.c normalizar
	gcc -c cargarDatos.c normalizar.o -Wall

normalizar: normalizar.c listaStock
	gcc -c normalizar.c listaStock.o -Wall

listaStock: listaStock.c
	gcc -c listaStock.c -Wall

maxMonticulo: maxMonticulo.c
	gcc -c maxMonticulo.c -Wall
