#include <stdio.h>
#include <string.h>
#include "book.h"

#define TAMANHO_TABELA 10

typedef struct NoLivro {
    Livro livro;
    struct NoLivro *proximo;
} NoLivro;

NoLivro *tabelaHash[TAMANHO_TABELA];

// Função para calcular o hash de um título
int calcularHash(const char *titulo) {
    int hash = 0;
    for (int i = 0; titulo[i] != '\0'; i++) {
        hash += titulo[i];
    }
    return hash % TAMANHO_TABELA;
}

// Função para inicializar a tabela hash
void inicializarTabelaHash() {
    for (int i = 0; i < TAMANHO_TABELA; i++) {
        tabelaHash[i] = NULL;
    }
}

// Função para inserir um livro na tabela hash
void inserirLivroHash(const char *titulo, const char *autor, int ano) {
    int indice = calcularHash(titulo);
    NoLivro *novoNo = (NoLivro *)malloc(sizeof(NoLivro));
    strcpy(novoNo->livro.titulo, titulo);
    strcpy(novoNo->livro.autor, autor);
    novoNo->livro.ano = ano;
    novoNo->proximo = tabelaHash[indice];
    tabelaHash[indice] = novoNo;
    printf("Livro inserido na tabela hash com sucesso!\n");
}

// Função para buscar um livro na tabela hash
void buscarLivroHash(const char *titulo) {
    int indice = calcularHash(titulo);
    NoLivro *atual = tabelaHash[indice];
    while (atual != NULL) {
        if (strcmp(atual->livro.titulo, titulo) == 0) {
            printf("Livro encontrado:\n");
            printf("Título: %s\n", atual->livro.titulo);
            printf("Autor: %s\n", atual->livro.autor);
            printf("Ano: %d\n", atual->livro.ano);
            return;
        }
        atual = atual->proximo;
    }
    printf("Livro não encontrado na tabela hash.\n");
}
