#ifndef LISTA_H
#define LISTA_H


typedef struct nodo {
    int idade;
    char nome[50];
    struct nodo *prox;
} Nodo;


Nodo* criarNodo(int idade, char nome[]);
void inserirNodoAoFinal(Nodo** lista, Nodo* novoNodo);
void deletarUltimoNodo(Nodo** lista);
void imprimirNodos(Nodo* lista);

#endif 
 