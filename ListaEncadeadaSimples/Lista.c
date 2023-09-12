/*
Listas encadeadas são estruturas de dados que permitem armazenar uma coleção
 de elementos de um mesmo tipo.

Neste arquivo, temos a implementação de uma lista encadeada simples de inteiros.
*/

#include "lista.h"//Cabeçalho da TAD que contém as funções

struct lista//struct que define os elementos da lista
{
	int info;//armazena os elementos da lista
	struct lista *prox;//ponteiro para apontar para o proximo elemento da lista
};

Lista *lst_cria(void)//cria a lista
{
	return NULL;
}

Lista *lst_insere(Lista *l, int v)
{
	Lista *novo = (Lista *)malloc(sizeof(Lista));//aloca dinamicamente o vetor
	if (novo == NULL)//verifica se é possivel realizar a alocção e se não for possivel aborta a execução
	{
		printf("[ERRO] memoria insuficiente!");
		exit(1);
	}
	novo->info = v;//Insere um novo elemento no inicio da lista usando a varoável v
	novo->prox = l;//aponta para o inicio da lista
	return novo;

	/* Ou para alterar diretamente

	void lst_insere(Lista** t, int v){
	Lista* novo = (Lista*) malloc(sizeof(Lista));
	novo->info = v;
	novo->prox = *t;
	*t = novo; */
}

int lst_vazia(Lista *l)//função que verifica se a lista está vazia caso l retorne NULL
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

Lista *lst_busca(int elemento, Lista *l)//função para buuscar um elemento da lista
{
	Lista *p;
	for (p = l; p != NULL; p = p->prox)//o for vai até o valor que NULL aponta que seria o primeiro valor que foi inseerido na lista
	{
		if (p->info == elemento)//condição para verificar que o item buscado é igual 
			return p;
	}

	return NULL;//A função retorna NULL se o elemento não for encontrado
}

Lista *lst_retira(Lista *l, int v)
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
	if (ant == NULL)
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
	while (p != NULL)
	{
		t = p->prox;
		free(p);
		p = t;
	}
}

Lista *lst_insere_ordenada(Lista *l, int v)
{
	Lista *novo;//novo nó a ser adicionado
	Lista *ant = NULL;//ponteiro que aponta para o endereço do elemento anterior
	Lista *p = l;//ponteiro usado para percorer a lista
	while (p != NULL && p->info < v)//enquanto p 
	{
		ant = p;
		p = p->prox;
	}
	novo = (Lista *)malloc(sizeof(Lista));
	novo->info = v;
	if (ant == NULL)
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
	if (arquivo == NULL)//
	{
		printf("Erro ao abrir o arquivo!\n");
		exit(1);
	}
	while (fscanf(arquivo, "%d", &valor) != EOF)//laço de repetição que lê os elementos da lista 
	{
		l = lst_insere(l, valor);
	}
	fclose(arquivo);//função que feicha o arquivo
	return l;
}
