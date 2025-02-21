#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAMANHO_ALFABETO 26

// Estrutura do nó da Trie
typedef struct NoTrie {
    struct NoTrie *filhos[TAMANHO_ALFABETO];
    int fimDePalavra;
} NoTrie;

NoTrie *raiz; // Ponteiro global para a raiz da Trie

// Função para inicializar a Trie
void inicializarTrie() {
    raiz = (NoTrie *)malloc(sizeof(NoTrie));
    if (raiz == NULL) {
        printf("Erro ao alocar memória para a raiz da Trie.\n");
        exit(1);
    }
    for (int i = 0; i < TAMANHO_ALFABETO; i++) {
        raiz->filhos[i] = NULL;
    }
    raiz->fimDePalavra = 0;
}

// Função para inserir um título na Trie
void inserirLivroTrie(const char *titulo) {
    NoTrie *atual = raiz;
    for (int i = 0; titulo[i] != '\0'; i++) {
        if (titulo[i] < 'a' || titulo[i] > 'z') {
            continue; // Ignora caracteres inválidos (pode ser adaptado)
        }
        int indice = titulo[i] - 'a';

        if (atual->filhos[indice] == NULL) {
            atual->filhos[indice] = (NoTrie *)malloc(sizeof(NoTrie));
            if (atual->filhos[indice] == NULL) {
                printf("Erro ao alocar memória para um novo nó.\n");
                exit(1);
            }
            for (int j = 0; j < TAMANHO_ALFABETO; j++) {
                atual->filhos[indice]->filhos[j] = NULL;
            }
            atual->filhos[indice]->fimDePalavra = 0;
        }
        atual = atual->filhos[indice];
    }
    atual->fimDePalavra = 1;
}

// Função para buscar um título na Trie
int buscarLivroTrie(const char *titulo) {
    NoTrie *atual = raiz;
    for (int i = 0; titulo[i] != '\0'; i++) {
        if (titulo[i] < 'a' || titulo[i] > 'z') {
            continue; // Ignora caracteres inválidos (pode ser adaptado)
        }
        int indice = titulo[i] - 'a';

        if (atual->filhos[indice] == NULL) {
            return 0; // Não encontrado
        }
        atual = atual->filhos[indice];
    }
    return atual->fimDePalavra;
}
