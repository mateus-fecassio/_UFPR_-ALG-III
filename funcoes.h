#ifndef FUNCOES_H
#define FUNCOES_H

#define INCLUSAO 'i'
#define BUSCA 'b'
#define REMOCAO 'r'
//DEFINIÇÃO DE ESTRUTURAS UTILIZADAS:
struct tNoA{ //struct da árvore PRINCIPAL A
	struct tNoA *esquerda;
	struct tNoA *direita;
	struct tNoA *pai;
	struct tNoB *chave; //a chave é do tipo árvore B
};

struct tNoB{ //struct da árvore SECUNDÁRIA B
	int chave;
	struct tNoB *esquerda;
	struct tNoB *direita;
	//struct tNoB *pai; não vai precisar
};


//CRIAÇÃO / INSERÇÃO DE ÁRVORES:
struct tNoA *cria_no_A (struct tNoB *nodoB);
struct tNoB *cria_no_B (int num);
struct tNoB *insereNo_arvoreB (struct tNoB *nodoB, int inteiro);
struct tNoA *insereNo_arvoreA (struct tNoA *arvoreA, struct tNoB *nodoB, int valor);



//BUSCA DE SUB-ÁRVORES:
struct tNoA *busca_arvoreA (struct tNoA *nodoA, int valor);



//REMOÇÃO DE ELEMENTOS
int exclusao (struct tNoA *raiz, int valor);
struct tNoA *remove_atual (struct tNoA *atual);
void remove_no (struct tNoA *nodoA);
int arvore_vazia (struct tNoB *nodoB);
void destroi(struct tNoB *nodoB);



//IMPRESSÃO DE ÁRVORES:
void imprimirB (struct tNoB *raiz);
void imprimirA (struct tNoA *arvoreA);



//OUTRAS FUNÇÕES:
int *retornaInteiros (char *input);
int indexacao_arvore (struct tNoB *nodoB);
int indexacao_vetor (int *inteiros);

#endif
