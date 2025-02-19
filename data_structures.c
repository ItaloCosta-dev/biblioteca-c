#include <stdio.h>
#include <string.h>
#include "book.h"

#define MAX_STACK 100
#define MAX_QUEUE 100

// Estrutura para a pilha
Livro pilha[MAX_STACK];
int topo = -1;

// Estrutura para a fila
Livro fila[MAX_QUEUE];
int frente = 0;
int tras = 0;

// Função para empilhar um livro
void empilharLivro() {
    if (topo >= MAX_STACK - 1) {
        printf("Pilha cheia. Não é possível empilhar mais livros.\n");
        return;
    }

    Livro novoLivro;
    printf("Digite o título do livro para empilhar: ");
    scanf(" %[^\n]", novoLivro.titulo);
    printf("Digite o autor do livro: ");
    scanf(" %[^\n]", novoLivro.autor);
    printf("Digite o ano de publicação: ");
    scanf("%d", &novoLivro.ano);

    pilha[++topo] = novoLivro;
    printf("Livro empilhado com sucesso!\n");
}

//Função para desempilhar um livro
void desempilharLivro() {
    if (topo == -1) {
        printf("Pilha vazia. Nenhum livro para desempilhar.\n");
        return;
    }

    Livro livroRemovido = pilha[topo--];
    printf("Livro desempilhado:\n");
    printf("Título: %s\n", livroRemovido.titulo);
    printf("Autor: %s\n", livroRemovido.autor);
    printf("Ano: %d\n", livroRemovido.ano);
}

//Função para enfileiar um livro
void enfileirarLivro() {
    if ((tras + 1) % MAX_QUEUE == frente) {
        print("Fila cheia. Não é possível adicionar mais livros.\n");
        return;
    }

    Livro novoLivro;
    printf("Digite o título do livro para enfileirar: ");
    scanf("%[^\n]", novoLivro.titulo);
    printf("Digite o autor do livro: ");
    scanf("%[^\n]",novoLivro.autor);
    printf("Digite o ano de publicação: ");
    scanf("%d", &novoLivro.ano);

    fila[tras] = novoLivro;
    tras = (tras + 1) % MAX_QUEUE;
    printf("Livro enfileirado com sucesso!\n");
}

// Função para desenfileirar um livro
void desenfileirarLivro() {
    if (frente == tras) {
        printf("Fila vazia. Nenhum livro para desenfileirar.\n");
        return;
    }

    Livro livroRemovido = fila[frente];
    frente = (frente + 1) % MAX_QUEUE;
    printf("Livro desenfileirado:\n");
    printf("Título: %s\n", livroRemovido.titulo);
    printf("Autor: %s\n", livroRemovido.autor);
    printf("Ano: %d\n", livroRemovido.ano);
}
