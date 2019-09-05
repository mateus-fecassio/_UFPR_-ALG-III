all: inicial main clean

inicial:
	@echo "iniciando"

main: main.o funcoes.o
	gcc main.o funcoes.o -o busca -Wall
funcoes.o: funcoes.c funcoes.h
	gcc -c funcoes.c -Wall
main.o:	main.c funcoes.h
	gcc -c main.c -Wall
clean:
	@echo "finalizando"
	@rm -rf *.o

