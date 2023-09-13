/*
Listas encadeadas são estruturas de dados que permitem armazenar uma coleção
 de elementos de um mesmo tipo.

Neste arquivo, temos a implementação de uma lista encadeada simples de inteiros.
*/

#include "lista.h"//Cabeçalho da TAD que contém as funções

struct lista//struct que define os elementos da lista
{
	char *info;//armazena os elementos da lista
	struct lista *prox;//ponteiro para apontar para o proximo elemento da lista
};

Lista *lst_cria(void)//cria a lista
{
	return NULL;//Inicioaliza a lista com NULL(vazia)
}

Lista *lst_insere(Lista *l, char *v)
{
	Lista *novo = (Lista *)malloc(sizeof(Lista));//aloca dinamicamente o vetor
	if (novo == NULL)//verifica se a alocação foi bem sucedida;seela não foi o programa aborta
	{
		printf("[ERRO] memoria insuficiente!");
		exit(1);
	}
	novo->info = v;//Insere um novo elemento no inicio da lista usando o valor de v
	novo->prox = l;//aponta um novo elemento para o inicio da lista
	return novo;//Retorna novo como o início da lista

	/* Ou para alterar diretamente

	void lst_insere(Lista** t, int v){
	Lista* novo = (Lista*) malloc(sizeof(Lista));
	novo->info = v;
	novo->prox = *t;
	*t = novo; */
}

char lst_vazia(Lista *l)//função que verifica se a lista está vazia caso l retorne NULL
{
	return (l == NULL);
}

void lst_imprime(Lista *l)//função para imprimir os elementos da lista
{
	Lista *p;
	for (p = l; p != NULL; p = p->prox)//o for vai até o valor que NULL aponta que seria o primeiro valor que foi inseerido na lista
	{
		printf("\tInfo = %d \n", p->info);
	}
}

Lista *lst_busca(char elemento, Lista *l)//função para buuscar um elemento da lista
{
	Lista *p;
	for (p = l; p != NULL; p = p->prox)//o for vai até o valor que NULL aponta que seria o primeiro valor que foi inseerido na lista
	{
		if (p->info == elemento)//condição para verificar que o item buscado é igual 
			return p;//se o item for igual ele retorna o endereço
	}

	return NULL;//A função retorna NULL se o elemento não for encontrado
}

Lista *lst_retira(Lista *l, char *v)
{
	Lista *ant = NULL; /* ponteiro para elemento anterior */
	Lista *p = l;	   /* ponteiro para percorrer a lista*/
	/* procura elemento na lista, guardando anterior */
	while (p->info != v)
	{
		if (p == NULL)
			return l; /* nao achou: retorna lista original */
		ant = p;
		p = p->prox;
		/* verifica se achou elemento */
	}
	/* retira elemento */
	if (p == NULL)
		/* retira elemento do inicio */
		l = p->prox;
	else
		/* retira elemento do meio da lista */
		ant->prox = p->prox;
	free(p);
	return l;
}

void lst_libera(Lista *l)//função usada para liberar a memoria que foi alocada
{
	Lista *p = l;//ponteiro que aponta para o inicio da lista
	Lista *t;
	while (p != NULL)//o loop começa do inicio da lista e vai ate o ponteiro(P) encontre NULL
	{
		t = p->prox;//t é usado para armazenar o endereço do próximo elemento da lista
		free(p);//liberea a memoria alocada
		p = t;//p é atualizado com o endereço que t armazena(próximo elemnto da lista)
	}
}

Lista *lst_insere_ordenada(Lista *l, char v)
{
	Lista *novo;//novo nó a ser adicionado
	Lista *ant = NULL;//ponteiro que aponta para o endereço do elemento anterior
	Lista *p = l;//ponteiro usado para percorer a lista
	while (p != NULL && p->info < v)//O loop continua enquanto o valor do nó atual for menor que o valor do novo elemento
	{
		//realiza a troca para ordenar a lista
		ant = p;
		p = p->prox;
	}
	novo = (Lista *)malloc(sizeof(Lista));//aloca dianmicamente os elementos da lista
	novo->info = v;//atribui v ao campo info da lista
	if (ant == NULL)//verifica se o valor anterior é igial a NULL, se for o novo elemento é adicionado ao inicio da lista e se não for ele so é adicionado após o nó apontador por ant
	{
		novo->prox = l;
		l = novo;
	}
	else
	{
		novo->prox = ant->prox;
		ant->prox = novo;
	}
	return l;
}

Lista *lst_ler_arquivo(char *nome_arquivo)
{
	FILE *arquivo;
	int valor;
	Lista *l = lst_cria();
	arquivo = fopen(nome_arquivo, "r");//abre um arquivo no modo de leitura
	if (arquivo == NULL)//verifica se foi possivel abrir o arquivo com sucesso 
	{
		printf("Erro ao abrir o arquivo!\n");//caso não tenha conseguido abrir o aquivo uma mensagem de erro é axibida na tela e a execução é abortada
		exit(1);
	}
	while (fscanf(arquivo, "%d", &valor) != EOF)//laço de repetição que lê os elementos da lista usanado a função fscanf e só para quando encontrar o final do arquivo
	{
		l = lst_insere(l, valor);//Insere os elementos lidos no arquivo usando a função lst_insere
	}
	fclose(arquivo);//função que fecha o arquivo
	return l;//retorna um ponteiro para lista criada
}
