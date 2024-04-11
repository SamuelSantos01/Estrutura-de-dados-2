#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define tamanho 10

typedef struct {
    int vet[tamanho];
    int first;
    int last;
} Nodo;

void removerElemento(Nodo *nodo);
void adicionarElemento(Nodo *nodo, int valor);
void inicializar(Nodo *nodo);
bool verificarVazia(Nodo *nodo);
bool verificarCheia(Nodo *nodo);
void verificarStatusFila(Nodo *nodo);
void listarElementos(Nodo *nodo);

int main() {
    Nodo fila;
    inicializar(&fila);

    int opcao;
    int elemento;

    do {
        printf("\nMenu de Operações:\n");
        printf("1. Adicionar elemento na fila\n");
        printf("2. Remover elemento da fila\n");
        printf("3. Verificar se a fila está vazia\n");
        printf("4. Verificar se a fila está cheia\n");
        printf("5. Listar elementos da fila\n");
        printf("6. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                if (verificarCheia(&fila)) {
                    printf("Fila cheia. Não é possível adicionar mais elementos.\n");
                } else {
                    printf("Digite o elemento a ser adicionado: ");
                    scanf("%d", &elemento);
                    adicionarElemento(&fila, elemento);
                    printf("Elemento %d adicionado na fila.\n", elemento);
                }
                break;
            case 2:
                if (verificarVazia(&fila)) {
                    printf("Fila vazia. Não há elementos para remover.\n");
                } else {
                    removerElemento(&fila);
                }
                break;
            case 3:
                verificarStatusFila(&fila);
                break;
            case 4:
                if (verificarCheia(&fila)) {
                    printf("Fila está cheia.\n");
                } else {
                    printf("Fila não está cheia.\n");
                }
                break;
            case 5:
                listarElementos(&fila);
                break;
            case 6:
                printf("Saindo do programa...\n");
                break;
            default:
                printf("Opção inválida. Por favor, escolha uma opção válida.\n");
        }
    } while (opcao != 6);

    return 0;
}

void removerElemento(Nodo *nodo) {
    printf("Elemento removido é o %d\n", nodo->vet[nodo->first]);
    nodo->first++;
}

void adicionarElemento(Nodo *nodo, int valor) {
    nodo->vet[nodo->last] = valor;
    nodo->last = (nodo->last + 1) % tamanho;
}

void inicializar(Nodo *nodo) {
    nodo->first = 0;
    nodo->last = 0;
}

bool verificarVazia(Nodo *nodo) {
    return (nodo->first == nodo->last);
}

bool verificarCheia(Nodo *nodo) {
    return ((nodo->last + 1) % tamanho == nodo->first);
}

void verificarStatusFila(Nodo *nodo) {
    if (verificarVazia(nodo)) {
        printf("A fila está vazia.\n");
    } else if (verificarCheia(nodo)) {
        printf("A fila está cheia.\n");
    } else {
        printf("A fila não está vazia e não está cheia.\n");
    }
}

void listarElementos(Nodo *nodo) {
    if (verificarVazia(nodo)) {
        printf("A fila está vazia. Não há elementos para listar.\n");
    } else {
        printf("Elementos na fila:\n");
        int i = nodo->first;  
        while (i != nodo->last) {  
            printf("%d ", nodo->vet[i]);  
            i = (i + 1) % tamanho;  
        }
        printf("\n");
    }
}

