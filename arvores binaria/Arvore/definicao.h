#ifndef DEFINICAO_H
#define DEFINICAO_H


struct No{
    int chave;
    struct No *esquerdo;
    struct No *direito;
};

typedef struct No Nodo;

Nodo* criarNo(int chave);
void percorrer(Nodo* raiz);
void adicionarNumero(Nodo**raiz, int valor);

#endif