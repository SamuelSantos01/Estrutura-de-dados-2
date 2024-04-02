#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

int main() {
    Nodo* lista = NULL;
    int opcao = 0;

    while (opcao != 4) {
        printf("\nSelecione uma opcao:\n");
        printf("1. Inserir novo nodo\n");
        printf("2. Imprimir nodos nos dois sentidos\n");
        printf("3. Deletar o ultimo nodo\n");
        printf("4. Sair\n");
        printf("Opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1: {
                int idade;
                char nome[50];
                printf("\nDigite a idade do novo nodo: ");
                scanf("%d", &idade);
                printf("Digite o nome do novo nodo: ");
                scanf("%s", nome);
                inserirNodoAoFinal(&lista, criarNodo(idade, nome));
                break;
            }
            case 2: {
                printf("\nNodos para frente:\n");
                imprimirNodosParaFrente(lista);
                printf("\nNodos para tras:\n");
                imprimirNodosParaTras(lista);
                break;
            }
            case 3: {
                deletarUltimoNodo(&lista);
                printf("\nUltimo nodo deletado.\n");
                break;
            }
            case 4: {
                printf("\nSaindo do programa.\n");
                break;
            }
            default:
                printf("\nOpcao invalida. Por favor, tente novamente.\n");
        }
    }

    while (lista != NULL) {
        deletarUltimoNodo(&lista);
    }

    return 0;
}
