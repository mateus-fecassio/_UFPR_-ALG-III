#include <stdio.h>
#include <stdlib.h>
#include "funcoes.h"

int main(){
	char input[100];
	char acao;
	int *inteiros;
	int contador, valor = 0, verifica = 0;
	struct tNoB *nodoB = NULL; //aponta para as várias árvores B secundárias que irão ser formadas
	struct tNoA *arvoreA = NULL; //aponta para a árvore principal A
	struct tNoA *nodoA = NULL;
	
	while ((acao = getchar()) != '\n'){
		scanf("%s", input);
		getchar();
		inteiros = retornaInteiros(input); //retorna um vetor com a primeira posição sendo o tamanho e o restante, os inteiros a serem inseridos
		
		if (acao != 'i' && acao != 'b' && acao != 'r')
			printf("COMANDO INVÁLIDO! DIGITE OUTRA OPERAÇÃO:\n");


		switch (acao){
			case INCLUSAO:
				for (contador = 1; contador <= inteiros[0]; contador++) //inserção dos números contidos no vetor em uma sub-árvore B
					nodoB = insereNo_arvoreB (nodoB, inteiros[contador]);

				valor = indexacao_arvore (nodoB);
				arvoreA = insereNo_arvoreA (arvoreA, nodoB, valor);
				nodoB = NULL;
				imprimirA (arvoreA);
				break;
			

			case BUSCA: 
				valor = indexacao_vetor (inteiros);// valor guarda o índice de indexação do vetor de busca
				nodoA = busca_arvoreA (arvoreA, valor);
				if (nodoA == NULL)
					printf("\nESSA SUBÁRVORE NÃO PÔDE SER ENCONTRADA!\n");
				nodoA = NULL;
				break;
			

			case REMOCAO:
				valor = indexacao_vetor (inteiros);
				verifica = exclusao (arvoreA, valor);
				if (verifica ==  1)
					imprimirA (arvoreA);
				else
					printf("NÃO FOI POSSÍVEL EXCLUIR POIS ESSA SUB-ÁRVORE NÃO EXISTE!\n");
				break;
		}//END SWITCH
		printf("\n\n\n");	
	}//END WHILE
}//END MAIN