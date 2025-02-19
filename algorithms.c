#include <stdio.h>
#include <string.h>
#include "book.h"

extern Livro biblioteca[];
extern int totalLivros;

void ordenarLivrosBubbleSort() {
    if (totalLivros == 0) {
        printf("Nenhum livro cadastrado para ordenar.\n");
        return;
    }

    for (int i = 0; i < totalLivros - 1; i++) {
        for (int j = 0; j < totalLivros - i - 1; j++) {
            if (strcmp(biblioteca[j].titulo, biblioteca[j + 1].titulo) > 0) {
                Livro temp = biblioteca[j];
                biblioteca[j] = biblioteca[j + 1];
                biblioteca[j + 1] = temp;
            }
        }
    }
    printf("Livros ordenados com sucesso!\n");
}

void pesquisarLivro() {
    if (totalLivros == 0) {
        printf("Nenhum livro cadastrado para pesquisar.\n");
        return;
    }

    char tituloPesquisa[100];
    printf("Digite o título do livro para pesquisar: ");
    scanf(" %[^\n]", tituloPesquisa);

    for (int i = 0; i < totalLivros; i++) {
        if (strcmp(biblioteca[i].titulo, tituloPesquisa) == 0) {
            printf("Livro encontrado!\n");
            printf("ID: %d\n", biblioteca[i].id);
            printf("Título: %s\n", biblioteca[i].titulo);
            printf("Autor: %s\n", biblioteca[i].autor);
            printf("Ano: %d\n", biblioteca[i].ano);
            return;
        }
    }
    printf("Livro não encontrado.\n");
}
