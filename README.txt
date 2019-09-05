TRABALHO DE ALGORITMOS E ESTRUTURA DE DADOS |||

		 					
Autores: Anna Caroline Bozzi (GRR20173532)			Data: 21/11/2019
    	 Mateus Felipe de C. Ferreira (GRR20176123)

IMPORTANTE: o teste de execução deve ser utilizado direcionando o arquivo ".in" ou ".txt" contendo uma quebra de linha ao final da última operação a ser executada.


A IMPLEMENTAÇÃO DA(S) ÁRVORE(S) BINÁRIA(S):

A leitura consiste em salvar a ação em uma variável, usada de parâmetro para as tomadas de decisões. As entradas de parênteses aninhados são salvas também, em um vetor, que é passado para uma função que tem como objetivo retornar apenas os inteiros, para que seja realizada a inserção, busca ou remoção. O controle do laço da leitura é um while que recebe false quando chega ao fim do 'arquivo', ou quando, no terminal é dado um enter seguido de outro. Assim que a ação é reconhecida passamos para a sequencia de switch - case, que faz a chamada das funções de acordo com  a ação.

A INSERÇÃO utiliza as funções cria_no_A,cria_no_B, insereNo_arvoreB, indexacao_arvore, insereNo_arvoreA, imprimirA:
	-cria_no_A e cria_no_B são função utilizadas na alocação de um nó a ser inserido em suas respectivas árvores, apontando inicialmente tudo para NULL;
	-insereNo_arvoreB recebe como parâmetro um nó B (inicialmente NULL) e os inteiros para criar a árvore B. O seu retorno é a raiz da sub-árvore B;
	-indexacao_arvore é a indexação (soma de todos os valores da árvore B) usada para inserir corretamente essa sub-árvore na árvore principal A;
	-insereNo_arvoreA que rececbe como parâmetro a arvore A a raiz da sub árvore a ser inserida, e a indexação usada para percorrer e saber onde fazer a inserção correta da sub arvore;
	-imprimirA recebe a árvore A, onde ela faz o percurso e imprime de acordo com a ação solicitada;

A BUSCA utiliza as funções indexacao_vetor, busca_arvoreA, imprimirB:
	-indexacao_vetor recebe um vetor de inteiros para ser calculado o valor de indexação que se quer achar nas subárvores;
	-busca_arvoreA recebe a árvore A (raiz) e o valor da indexação da sub-árvore a ser buscada. Ela retorna o nó encontrado ou NULL, neste último caso, imprimindo uma mensagem de erro no main.c:39

A REMOÇÃO utiliza as funções indexacao_vetor, exclusao, imprimirA:
	-indexacao_vetor recebe um vetor de inteiros para ser calculado o valor de indexação que se quer excluir em alguma sub-árvore;	
	-no main.c:46, (int)verifica recebe o valor retornado pela função exclusao, que recebe como parâmetros a arvoreA (raiz) e o valor a ser buscado nas sub-árvores. Essa função de exclusão percorrerá a árvore principal A até encontrar esse valor e utilizará de outras funções para a remoção correta da sub-árvore, como:
a)remove_atual, que ajustará os nós para uma remoção adequada; b)remove_no, que desaloca os nós removidos e chama a função c)destroi, que desaloca todos os nós da sub-árvore B apontada pelo nó a ser removido da árvore principal A.