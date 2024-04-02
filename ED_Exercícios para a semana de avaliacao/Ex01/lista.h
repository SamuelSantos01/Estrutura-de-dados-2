#ifndef LISTA_H
#define LISTA_H

typedef struct no {
    int idade;
    char nome[50];
    struct no *prox, *ant;
} Nodo;

Nodo* criarNodo(int idade, const char* nome);
void inserirNodoAoFinal(Nodo** lista, Nodo* novoNodo);
void deletarUltimoNodo(Nodo** lista);
void imprimirNodosParaFrente(Nodo* lista);
void imprimirNodosParaTras(Nodo* lista);

#endif
