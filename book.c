#include <stdio.h>
#include <string.h>
#include "book.h"

#define MAX_LIVROS 100

Livro biblioteca[MAX_LIVROS];
int totalLivros = 0;

void cadastrarLivro() {
    if (totalLivros >= MAX_LIVROS) {
        printf("Capacidade máxima da biblioteca atingida. \n");
        return;
    }

    Livro novoLivro;
    novoLivro.id = totalLivros + 1;
    printf("Título: ");
    scanf(" %[^\n]", novoLivro.titulo);
    printf("Autor: ");
    scanf(" %[^\n]", novoLivro.autor);
    printf("Ano de publicação: ");
    scanf("%d", &novoLivro.ano);

    biblioteca[totalLivros] = novoLivro;
    totalLivros++;
    printf("Livro cadastrado com sucesso!\n");
}

void listarLivros() {
    if (totalLivros == 0) {
        printf("Nenhum livro cadastrado.\n");
        return;
    }

    for (int i  = 0; i < totalLivros; i++) {
        printf("ID: %d\n", biblioteca[i].id);
        print("Título: %s\n", biblioteca[i].titulo);
        print("Autor: %s\n", biblioteca[i].autor);
        print("Ano: %s\n", biblioteca[i].ano);
    }
}