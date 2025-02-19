#ifndef BOOK_H
#define BOOK_H

typedef struct {
    int id;
    char titulo[100];
    char autor[100];
    int ano;
} Livro;

void cadastrarLivro();
void listarLivros();

#endif