#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

// Definição de uma estrutura de dados para representar um nó da lista encadeada
typedef struct nodo {  
    int valor; // Armazena o valor do nó
    struct nodo *proximo; // Aponta para o próximo nó na lista
} no;

// Protótipos das funções
void inserir_elemento(no **cabeca, int valor);
void deletar_elemento(no **cabeca, int valor);
no *criar_no(int valor);
void imprimir_nos(no *cabeca);

int main() {
    // Inicialização da lista como vazia
    no *lista = NULL;
    int opcao, valor;

    // Configuração para usar acentos e caracteres especiais
    setlocale(LC_ALL, "portuguese");

    // Menu de operações
    printf("=== Operações com listas lineares ===\n");
    printf("1 - Inserir elemento\n");
    printf("2 - Deletar elemento\n");
    printf("3 - Imprimir elementos\n");
    printf("4 - Fechar programa\n");

    // Loop principal do programa
    do {
        printf("\nEscolha uma operação: ");
        scanf("%d", &opcao);

        // Switch para lidar com as diferentes operações
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
                printf("Operação inválida. Tente novamente.\n");
        }
    } while (opcao != 4);

    // Libera memória alocada para os nós da lista
    while (lista != NULL) {
        no *temp = lista;
        lista = lista->proximo;
        free(temp);
    }

    return 0;
}

// Função para criar um novo nó
no *criar_no(int valor) {
    no *novo = (no *)malloc(sizeof(no)); // Aloca memória para o novo nó
    if (novo != NULL) {
        novo->valor = valor; // Define o valor do nó
        novo->proximo = NULL; // Define o próximo como nulo, já que é o último nó
    }
    return novo; // Retorna o novo nó
}

// Função para inserir um elemento na lista
void inserir_elemento(no **cabeca, int valor) {
    no *novo = criar_no(valor); // Cria um novo nó com o valor passado

    if (novo != NULL) {
        if (*cabeca == NULL) {
            *cabeca = novo; // Se a lista estiver vazia, o novo nó é o primeiro da lista
        } else {
            no *atual = *cabeca;
            while (atual->proximo != NULL) {
                atual = atual->proximo; // Encontra o último nó da lista
            }
            atual->proximo = novo; // Insere o novo nó no final da lista
        }
    }
}

// Função para deletar um elemento da lista
void deletar_elemento(no **cabeca, int valor) {
    if (*cabeca == NULL) {
        printf("Lista vazia\n"); // Verifica se a lista está vazia
        return;
    }

    no *atual = *cabeca;
    no *anterior = NULL;

    // Encontra o nó a ser deletado
    while (atual != NULL && atual->valor != valor) {
        anterior = atual;
        atual = atual->proximo;
    }

    if (atual == NULL) {
        printf("Elemento não encontrado na lista\n"); // Se o nó não for encontrado
        return;
    }

    if (anterior == NULL) {
        *cabeca = atual->proximo; // Se o nó a ser deletado for o primeiro da lista
    } else {
        anterior->proximo = atual->proximo; // Se o nó a ser deletado não for o primeiro
    }

    free(atual); // Libera a memória do nó deletado
}

// Função para imprimir os elementos da lista
void imprimir_nos(no *cabeca) {
    if (cabeca == NULL) {
        printf("Lista vazia\n"); // Se a lista estiver vazia
        return;
    }

    while (cabeca != NULL) {
        printf("%d ", cabeca->valor); // Percorre a lista imprimindo os valores dos nós
        cabeca = cabeca->proximo;
    }
    printf("\n");
}
