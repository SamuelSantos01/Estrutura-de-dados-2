#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

typedef struct Nodo {
    int valor;
    struct Nodo *proximo;
} Nodo;

Nodo* criar_camada(int valor) {
    Nodo* novoNodo = (Nodo*)malloc(sizeof(Nodo));
    if (novoNodo) {
        novoNodo->valor = valor;
        novoNodo->proximo = NULL;
    }
    return novoNodo;
}

void verificar_se_vazia(Nodo *pilha) {
    if (pilha == NULL) {
        printf("A pilha está vazia.\n");
    } else {
        printf("A pilha não está vazia.\n");
    }
}

void push(Nodo** pilha, int valor) {
    Nodo* novaCamada = criar_camada(valor);
    if (novaCamada) {
        if (*pilha == NULL) {
            *pilha = novaCamada;
        } else {
            Nodo* aux = *pilha;
            while (aux->proximo != NULL) {
               aux = aux->proximo;
            }
            aux->proximo = novaCamada;
        }
        printf("Elemento %d inserido na pilha.\n", valor);
    } else {
        printf("Erro ao criar nodo. Memória insuficiente.\n");
    }
}

void imprimir_pilha(Nodo *pilha) {
    if (pilha == NULL) {
        printf("Pilha vazia.\n");
    } else {
        printf("Conteúdo da pilha (da base ao topo):\n");
        while (pilha != NULL) {
            printf("%d\n", pilha->valor);
            pilha = pilha->proximo;
        }
    }
}

void pop(Nodo **pilha) {
    if (*pilha == NULL) {
        printf("ERRO: Pilha vazia. Não é possível remover.\n");
    } else {
        Nodo *atual = *pilha;
        Nodo *anterior = NULL;

        while (atual->proximo != NULL) {
            anterior = atual;
            atual = atual->proximo;
        }

        if (anterior == NULL) {
            *pilha = NULL;
        } else {
            anterior->proximo = NULL;
        }

        printf("Elemento %d removido da pilha.\n", atual->valor);
        free(atual);
    }
}

int main() {
    setlocale(LC_ALL, "Portuguese");

    Nodo* pilha = NULL;
    int opcao, valor;

    do {
        printf("\n--- MENU ---\n");
        printf("1. Inserir elemento na pilha (push)\n");
        printf("2. Remover elemento da pilha (pop)\n");
        printf("3. Verificar se a pilha está vazia\n");
        printf("4. Imprimir pilha\n");
        printf("0. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                printf("Digite o valor a ser inserido na pilha: ");
                scanf("%d", &valor);
                push(&pilha, valor);
                break;
            case 2:
                pop(&pilha);
                break;
            case 3:
                verificar_se_vazia(pilha);
                break;
            case 4:
                imprimir_pilha(pilha);
                break;
            case 0:
                printf("Encerrando o programa.\n");
                break;
            default:
                printf("Opção inválida. Tente novamente.\n");
        }
    } while (opcao != 0);

    return 0;
}
