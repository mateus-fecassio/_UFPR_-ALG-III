#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include "funcoes.h"
//-----------------------------------------------CRIAÇÃO / INSERÇÃO DE ÁRVORES-----------------------------------------------//
//função de criação e inicialização do novo nó da árvore A:
struct tNoA *cria_no_A (struct tNoB *nodoB){ //
	struct tNoA *novoA = (struct tNoA *)malloc(sizeof(struct tNoA));
	novoA->esquerda = NULL;
	novoA->direita = NULL;
	novoA->pai = NULL;
	novoA->chave = nodoB;

	return novoA;
}//TERMINADO

//função de criação e inicialização do novo nó da árvore B:
struct tNoB *cria_no_B (int num){
	struct tNoB *novoB = (struct tNoB *)malloc(sizeof(struct tNoB));
	novoB->esquerda = NULL;
	novoB->direita = NULL;
	novoB->chave = num;

	return novoB;
}//TERMINADO

//função que dada a entrada, cria a árvore B:
struct tNoB *insereNo_arvoreB (struct tNoB *nodoB, int inteiro){
	if (nodoB == NULL) //raiz
		return cria_no_B (inteiro);
	if (inteiro == nodoB->chave)
		return nodoB; //VER
	if (inteiro < nodoB->chave)
		nodoB->esquerda = insereNo_arvoreB(nodoB->esquerda, inteiro);
	else
		nodoB->direita = insereNo_arvoreB(nodoB->direita, inteiro);

	return nodoB; //RETORNA A RAIZ
}//TERMINADO

//função de inserção em uma árvore principal A:
struct tNoA *insereNo_arvoreA (struct tNoA *arvoreA, struct tNoB *nodoB, int valor){//valor é o indice de indexacao
	struct tNoA *atual, *pai, *nodoA;
	int indexacao_atual = 0;

	if (arvoreA == NULL)
		arvoreA = cria_no_A (nodoB);
	else{
		nodoA = cria_no_A (nodoB);//demais inserções
		atual = arvoreA;
		pai = NULL;

		while (atual != NULL){
			pai = atual;
			indexacao_atual = indexacao_arvore (atual->chave);
			
			if (valor < indexacao_atual) 
				atual = atual->esquerda;
			else if (valor > indexacao_atual)
				atual = atual->direita;
			else if (valor == indexacao_atual){ //NÃO SE INSERE SUB-ÁRVORES COM MESMO ÍNDICE DE INDEXAÇÃO
				atual = NULL;
				free (nodoA); //[TALVEZ] tirar, mas é importante não inserir e liberar esse espaço de memória
			}
		}
		if (nodoA != NULL){
			if 	(valor > (indexacao_arvore(pai->chave)))
				pai->direita = nodoA;
		 	else
				pai->esquerda = nodoA;
		
		nodoA->pai = pai;
		}
	}
	return arvoreA;//RETORNA A RAIZ (o ponteiro para a raiz)
}//TERMINADO



//---------------------------------------------------BUSCA DE SUB-ÁRVORES---------------------------------------------------//
//função de busca na árvore principal A
struct tNoA *busca_arvoreA (struct tNoA *nodoA, int valor){
	int indexacao_atual = 0;
	if (nodoA == NULL) //SE A ÁRVORE(dado aqui como nodoA) É NULA, NADA PODE SER FEITO!
		return NULL;
	else{
		indexacao_atual = indexacao_arvore (nodoA->chave);
		while (nodoA != NULL && valor != indexacao_atual){ 
			if (valor < indexacao_atual){
				imprimirB (nodoA->chave);
				printf (":%d\n",indexacao_atual);
				nodoA = nodoA->esquerda;
			}
			else if (valor > indexacao_atual){
				imprimirB (nodoA->chave);
				printf (":%d\n",indexacao_atual);
				nodoA = nodoA->direita;
			}
	
			if (nodoA != NULL){
				indexacao_atual = indexacao_arvore (nodoA->chave);
				if (valor == indexacao_atual){
					imprimirB (nodoA->chave);
					printf (":%d\n",indexacao_atual);
				}
			}
		}
		return nodoA;	
	}
}//TERMINADO	



//--------------------------------------------------REMOÇÃO DE ELEMENTOS---------------------------------------------------//
int exclusao (struct tNoA *raiz, int valor){
	if (raiz == NULL)
		return 0;
	struct tNoA *ant = NULL;
	struct tNoA *atual = raiz;

	while (atual != NULL){
		if (valor == indexacao_arvore (atual->chave)){
			if (atual == raiz)
				raiz = remove_atual(atual);
			else{
				if (ant->direita == atual)
					ant->direita = remove_atual(atual);
				else
					ant->esquerda = remove_atual(atual);
			}
			return 1;
		}
		ant = atual;
		if (valor > indexacao_arvore (atual->chave))
			atual = atual->direita;
		else
			atual = atual->esquerda;
	}
	return 0;
}//TERMINADO

struct tNoA *remove_atual (struct tNoA *atual){
	struct tNoA *no1, *no2;
	
	if (atual->esquerda == NULL){
		no2 = atual->direita;
		remove_no (atual);
		return no2;
	}

	no1 = atual;
	no2 = atual->esquerda;
	
	while (no2->direita != NULL){
		no1 = no2;
		no2 = no2->direita;
	}

	if (no1 != atual){
		no1->direita = no2->esquerda;
		no2->esquerda = atual->esquerda;
	}
	no2->direita = atual->direita;
	remove_no (atual);
	return no2;
}//TERMINADO

void remove_no (struct tNoA *nodoA){
	nodoA->esquerda = NULL;
	nodoA->direita = NULL;
	nodoA->pai = NULL;
	destroi(nodoA->chave); //destruir a árvore B apontada pelo nó da árvore A
	free (nodoA);
}//TERMINADO

int arvore_vazia (struct tNoB *nodoB){
	return nodoB == NULL; //1 se nulo, 0 se não nulo
}//TERMINADO

void destroi(struct tNoB *nodoB){
	if (!arvore_vazia(nodoB)){
		destroi(nodoB->esquerda);
		destroi(nodoB->direita);
		nodoB->esquerda = NULL;
		nodoB->direita = NULL;
		free(nodoB);
	}
}//TERMINADO



//--------------------------------------------------IMPRESSÃO DE ÁRVORES---------------------------------------------------//
//função de impressão da ávore secundária B
void imprimirB (struct tNoB *raiz){
	if (raiz == NULL)
		return;
	printf("(%d", raiz->chave);
	if (raiz->esquerda != NULL){
		imprimirB(raiz->esquerda);
	}else if (raiz->direita != NULL){
		printf("()");
	}
	if (raiz->direita != NULL){
		imprimirB(raiz->direita);
	}else if (raiz->esquerda != NULL){
		printf("()");
	}
	printf(")");
}//TERMINADO

//função de impressão da ávore principal A
void imprimirA (struct tNoA *arvoreA){

  if (arvoreA == NULL)
		return;
	printf ("[");
	imprimirB (arvoreA->chave);
	printf (":%d\n", indexacao_arvore(arvoreA->chave));
	if(arvoreA->esquerda != NULL){
		imprimirA (arvoreA->esquerda);
	} else if (arvoreA->direita != NULL){
		printf("[\n]\n");
	}
	if (arvoreA->direita != NULL){
		imprimirA (arvoreA->direita);
	} else if (arvoreA->esquerda != NULL){
		printf("[\n]\n");
	}
	printf("]\n");
}//TERMINADO



//----------------------------------------------------OUTRAS FUNÇÕES-----------------------------------------------------//
//função que retorna os inteiros que serão inseridos nas árvores:
int *retornaInteiros (char *input){
	static int inteiros[100];
	int i = 1;
	int val;

	while (*input)
	{ // Enquanto tem caracteres
		if (isdigit(*input))
		{ //isdigit acha inteiros
		  //achou um número
			val = strtol(input, &input, 10); //pega o número      STRTOL converte string em inteiro, o 10 é a base decimal
			inteiros[i] = val;               //adiciona no vetor de int
			i++;
		}
		else
		{
			//senão passa para o próximo char.
			input++;
		}
	}
	inteiros[0] = i - 1; // ta guardando o tamanho do vetor
	return inteiros;
}//TERMINADO

//cálculo do índice de indexação de uma árvore secundária B:
int indexacao_arvore (struct tNoB *nodoB){
	if (nodoB != NULL)
		return indexacao_arvore(nodoB->esquerda) + indexacao_arvore(nodoB->direita) + nodoB->chave;
	else
		return 0;
}//TERMINADO


//cálculo do índice de indexação de um vetor:
int indexacao_vetor (int *inteiros){
	int soma = 0;

	for (int contador = 1; contador <= inteiros[0]; contador ++)
		soma = soma + inteiros[contador];

	return soma;
}//TERMINADO
