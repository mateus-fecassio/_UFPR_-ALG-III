TRABALHO DE ALGORITMOS E ESTRUTURA DE DADOS |||

		 					
Autores: Anna Caroline Bozzi (GRR20173532)			Data: 21/11/2019
    	 Mateus Felipe de C. Ferreira (GRR20176123)

IMPORTANTE: o teste de execu��o deve ser utilizado direcionando o arquivo ".in" ou ".txt" contendo uma quebra de linha ao final da �ltima opera��o a ser executada.


A IMPLEMENTA��O DA(S) �RVORE(S) BIN�RIA(S):

A leitura consiste em salvar a a��o em uma vari�vel, usada de par�metro para as tomadas de decis�es. As entradas de par�nteses aninhados s�o salvas tamb�m, em um vetor, que � passado para uma fun��o que tem como objetivo retornar apenas os inteiros, para que seja realizada a inser��o, busca ou remo��o. O controle do la�o da leitura � um while que recebe false quando chega ao fim do 'arquivo', ou quando, no terminal � dado um enter seguido de outro. Assim que a a��o � reconhecida passamos para a sequencia de switch - case, que faz a chamada das fun��es de acordo com  a a��o.

A INSER��O utiliza as fun��es cria_no_A,cria_no_B, insereNo_arvoreB, indexacao_arvore, insereNo_arvoreA, imprimirA:
	-cria_no_A e cria_no_B s�o fun��o utilizadas na aloca��o de um n� a ser inserido em suas respectivas �rvores, apontando inicialmente tudo para NULL;
	-insereNo_arvoreB recebe como par�metro um n� B (inicialmente NULL) e os inteiros para criar a �rvore B. O seu retorno � a raiz da sub-�rvore B;
	-indexacao_arvore � a indexa��o (soma de todos os valores da �rvore B) usada para inserir corretamente essa sub-�rvore na �rvore principal A;
	-insereNo_arvoreA que rececbe como par�metro a arvore A a raiz da sub �rvore a ser inserida, e a indexa��o usada para percorrer e saber onde fazer a inser��o correta da sub arvore;
	-imprimirA recebe a �rvore A, onde ela faz o percurso e imprime de acordo com a a��o solicitada;

A BUSCA utiliza as fun��es indexacao_vetor, busca_arvoreA, imprimirB:
	-indexacao_vetor recebe um vetor de inteiros para ser calculado o valor de indexa��o que se quer achar nas sub�rvores;
	-busca_arvoreA recebe a �rvore A (raiz) e o valor da indexa��o da sub-�rvore a ser buscada. Ela retorna o n� encontrado ou NULL, neste �ltimo caso, imprimindo uma mensagem de erro no main.c:39

A REMO��O utiliza as fun��es indexacao_vetor, exclusao, imprimirA:
	-indexacao_vetor recebe um vetor de inteiros para ser calculado o valor de indexa��o que se quer excluir em alguma sub-�rvore;	
	-no main.c:46, (int)verifica recebe o valor retornado pela fun��o exclusao, que recebe como par�metros a arvoreA (raiz) e o valor a ser buscado nas sub-�rvores. Essa fun��o de exclus�o percorrer� a �rvore principal A at� encontrar esse valor e utilizar� de outras fun��es para a remo��o correta da sub-�rvore, como:
a)remove_atual, que ajustar� os n�s para uma remo��o adequada; b)remove_no, que desaloca os n�s removidos e chama a fun��o c)destroi, que desaloca todos os n�s da sub-�rvore B apontada pelo n� a ser removido da �rvore principal A.