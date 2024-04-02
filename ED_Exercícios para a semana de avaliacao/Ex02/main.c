#include <stdio.h>
#include "lista.h"

int main() {
    Nodo* lista = NULL;
    int opcao = 0;

    while (opcao != 5) {
        printf("\nSelecione uma opcao:\n");
        printf("1. Inserir novo nodo\n");
        printf("2. Imprimir nodos\n");
        printf("3. Deletar o ultimo nodo\n");
        printf("4. Limpar a lista\n");
        printf("5. Sair\n");
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
                printf("\nNodos na lista:\n");
                imprimirNodos(lista);
                break;
            }
            case 3: {
                deletarUltimoNodo(&lista);
                printf("\nUltimo nodo deletado.\n");
                break;
            }
            case 4: {
                while (lista != NULL) {
                    deletarUltimoNodo(&lista);
                }
                printf("\nLista limpa.\n");
                break;
            }
            case 5: {
                printf("\nSaindo do programa.\n");
                break;
            }
            default:
                printf("\nOpcao invalida. Por favor, tente novamente.\n");
        }
    }

    return 0;
}
