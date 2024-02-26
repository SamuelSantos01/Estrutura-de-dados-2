#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

typedef struct nodo {
    int valor;
    struct nodo *proximo;
} no;

void inserir_elemento(no **cabeca, int valor);
void deletar_elemento(no **cabeca, int valor);
no *criar_no(int valor);
void imprimir_nos(no *cabeca);

int main() {
    no *lista = NULL;
    int opcao, valor;

    setlocale(LC_ALL, "portuguese");
    printf("=== Operações com listas lineares ===\n");
    printf("1 - Inserir elemento\n");
    printf("2 - Deletar elemento\n");
    printf("3 - Imprimir elementos\n");
    printf("4 - Fechar programa\n");

    do {
        printf("\nEscolha uma operação: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                printf("Digite o valor a ser inserido: ");
                scanf("%d", &valor);
                inserir_elemento(&lista, valor);
                break;
            case 2:
                printf("Digite o valor a ser deletado: ");
                scanf("%d", &valor);
                deletar_elemento(&lista, valor);
                break;
            case 3:
                printf("Elementos na lista: ");
                imprimir_nos(lista);
                break;
            case 4:
                printf("Fechando o programa.\n");
                break;
            default:
                printf("Operação invalida. Tente novamente.\n");
        }
    } while (opcao != 4);

    
    while (lista != NULL) {
        no *temp = lista;
        lista = lista->proximo;
        free(temp);
    }

    return 0;
}

no *criar_no(int valor) {
    no *novo = (no *)malloc(sizeof(no));
    if (novo != NULL) {
        novo->valor = valor;
        novo->proximo = NULL;
    }
    return novo;
}

void inserir_elemento(no **cabeca, int valor) {
    no *novo = criar_no(valor);

    if (novo != NULL) {
        if (*cabeca == NULL) {
            *cabeca = novo;
        } else {
            no *atual = *cabeca;
            while (atual->proximo != NULL) {
                atual = atual->proximo;
            }
            atual->proximo = novo;
        }
    }
}

void deletar_elemento(no **cabeca, int valor) {
    if (*cabeca == NULL) {
        printf("Lista vazia\n");
        return;
    }

    no *atual = *cabeca;
    no *anterior = NULL;

    while (atual != NULL && atual->valor != valor) {
        anterior = atual;
        atual = atual->proximo;
    }

    if (atual == NULL) {
        printf("Elemento não encontrado na lista\n");
        return;
    }

    if (anterior == NULL) {
        *cabeca = atual->proximo;
    } else {
        anterior->proximo = atual->proximo;
    }

    free(atual);
}

void imprimir_nos(no *cabeca) {
    if (cabeca == NULL) {
        printf("Lista vazia\n");
        return;
    }

    while (cabeca != NULL) {
        printf("%d ", cabeca->valor);
        cabeca = cabeca->proximo;
    }
    printf("\n");
}
