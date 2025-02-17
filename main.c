#include <stdio.h>

#include "book.h"
#include "algorithms.h"
#include "data_structures.h"
#include "hash_table.h"
#include "tries.h"

void showMenu() {
    printf("===== Sistema de gerencimanto de Biblioteca =====\n");

    printf("1. Cadastrar Livro\n");
    printf("2. Listar Livros\n");
    printf("3. Ordenar Livros\n");  // Bubble sort
    printf("4. Pesquisar Livros\n"); // Pesquisa linear
    printf("5. Empilhar Livro\n");
    printf("6. Sair\n");
    printf("Escolha uma opção: ");
}

int main() {
    int option;

    do {
        showMenu();
        scanf("%d", &option);
        switch (option) {
            case 1:
                cadastrarLivro();
                break;

            case 2:
                listarLivro();
                break;

            case 3:
                ordenarLivrosBubbleSort();
                break;

            case 4:
                pesquisarLivro();
                break;

            case 5:
                empilharLivro();
                break;

            case 6:
                printf("Encerrando o sistema...\n");
                break;

            default:
                printf("Opção inválida, tente novamente.\n");
        }
    } while (option != 6); 
    return 0; 
}
