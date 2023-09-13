#include <stdio.h>
#include <stdlib.h>

typedef struct lista Lista;

// função que cria uma lista vazia (NULL)
Lista *lst_cria(void);

// função que insere um elemento no início da lista
Lista *lst_insere(Lista *l, char *v);

// função que verifica se a lista está vazia
char lst_vazia(Lista *l);

// função que imprime os elementos da lista
void lst_imprime(Lista *l);

// função que busca um elemento na lista
Lista *lst_busca(char elemento, Lista *l);

// função que retira um elemento da lista
Lista *lst_retira(Lista *l, char *v);

// função que libera a memória alocada para a lista
void lst_libera(Lista *l);

// função que insere de forma ordenada um elemento na lista
Lista *lst_insere_ordenada(Lista *l, char v);

// Função que ler de uma arquivo e armazena na lista encadeada de inteiros
Lista *lst_ler_arquivo(char *nome_arquivo);
