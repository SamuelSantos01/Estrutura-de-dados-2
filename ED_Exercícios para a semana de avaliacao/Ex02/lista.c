#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lista.h"

Nodo* criarNodo(int idade, char nome[]) {
    Nodo* novoNodo = (Nodo*)malloc(sizeof(Nodo));
    if (novoNodo != NULL) {
        novoNodo->idade = idade;
        strcpy(novoNodo->nome, nome);
        novoNodo->prox = NULL;
    }
    return novoNodo;
}


void inserirNodoAoFinal(Nodo** lista, Nodo* novoNodo) {
    if (*lista == NULL) {
        *lista = novoNodo;
        novoNodo->prox = novoNodo; 
    } else {
        Nodo* temp = *lista;
        while (temp->prox != *lista) {
            temp = temp->prox;
        }
        temp->prox = novoNodo;
        novoNodo->prox = *lista;
    }
}


void deletarUltimoNodo(Nodo** lista) {
    if (*lista == NULL) {
        printf("Lista vazia. Nada a deletar.\n");
        return;
    }
    Nodo *ultimo = *lista, *penultimo = NULL;
    while (ultimo->prox != *lista) {
        penultimo = ultimo;
        ultimo = ultimo->prox;
    }
    if (penultimo != NULL) {
        penultimo->prox = *lista;
    } else {
        *lista = NULL;
    }
    free(ultimo);
}


void imprimirNodos(Nodo* lista) {
    if (lista == NULL) {
        printf("Lista vazia.\n");
        return;
    }
    Nodo* temp = lista;
    do {
        printf("Nome: %s, Idade: %d\n", temp->nome, temp->idade);
        temp = temp->prox;
    } while (temp != lista);
}
