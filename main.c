#include <stdio.h>

#include "book.h"
#include "algorithms.h"
#include "data_structures.h"
#include "hash_table.h"
#include "tries.h"

void showMenu() {
    printf("===== Sistema de Gerenciamento de Biblioteca =====\n");
    printf("1. Cadastrar Livro\n");
    printf("2. Listar Livros\n");
    printf("3. Ordenar Livros (Bubble Sort)\n");
    printf("4. Pesquisar Livro (Pesquisa Linear)\n");
    printf("5. Empilhar Livro\n");
    printf("6. Desempilhar Livro\n");
    printf("7. Enfileirar Livro\n");
    printf("8. Desenfileirar Livro\n");
    printf("9. Inserir Livro na Tabela Hash\n");
    printf("10. Buscar Livro na Tabela Hash\n");
    printf("11. Inserir Livro na Trie\n");
    printf("12. Buscar Livro na Trie\n");
    printf("13. Sair\n");
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
                desempilharLivro();
                break;

            case 7:
                enfileirarLivro();
                break;

            case 8:
                desenfileirarLivro();
                break;

            case 9:
                printf("Encerrando sistema...\n");
                break;
            default:
                printf("Opção inválida, tente novamente.\n");
                switch (option) {
                    case 9:
                        inserirLivroHash("Livro Exemplo", "Autor Exemplo", 2022);
                        break;
                    case 10:
                        buscarLivroHash("Livro Exemplo");
                        break;
                    case 11:
                        inserirLivroTrie("livroexemplo");
                        break;
                    case 12:
                        if (buscarLivroTrie("livroexemplo")) {
                            printf("Livro encontrado na trie!\n");
                        } else {
                            printf("Livro não encontrado na trie.\n");
                        }
                        break;
                    case 13:
                        printf("Encerrando o sistema...\n");
                        break;
                    default:
                        printf("Opção inválida. Tente novamente.\n");
                }
                
        }
    } while (option != 6); 
    return 0; 
}
