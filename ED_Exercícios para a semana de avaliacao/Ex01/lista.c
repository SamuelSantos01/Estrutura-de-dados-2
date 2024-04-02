#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lista.h"

Nodo* criarNodo(int idade, const char* nome) {
    Nodo* novoNodo = (Nodo*)malloc(sizeof(Nodo));
    if (novoNodo != NULL) {
        novoNodo->idade = idade;
        strcpy(novoNodo->nome, nome);
        novoNodo->prox = NULL;
        novoNodo->ant = NULL;
    }
    return novoNodo;
}

void inserirNodoAoFinal(Nodo** lista, Nodo* novoNodo) {
    if (*lista == NULL) {
        *lista = novoNodo;
    } else {
        Nodo* temp = *lista;
        while (temp->prox != NULL) {
            temp = temp->prox;
        }
        temp->prox = novoNodo;
        novoNodo->ant = temp;
    }
}

void deletarUltimoNodo(Nodo** lista) {
    if (*lista == NULL) {
        return;
    }
    Nodo* temp = *lista;
    while (temp->prox != NULL) {
        temp = temp->prox;
    }
    if (temp->ant != NULL) {
        temp->ant->prox = NULL;
    } else {
        *lista = NULL;
    }
    free(temp);
}

void imprimirNodosParaFrente(Nodo* lista) {
    Nodo* temp = lista;
    while (temp != NULL) {
        printf("Nome: %s, Idade: %d\n", temp->nome, temp->idade);
        temp = temp->prox;
    }
}

void imprimirNodosParaTras(Nodo* lista) {
    Nodo* temp = lista;
    while (temp->prox != NULL) {
        temp = temp->prox;
    }
    while (temp != NULL) {
        printf("Nome: %s, Idade: %d\n", temp->nome, temp->idade);
        temp = temp->ant;
    }
}
