#include <stdio.h>
#include <stdlib.h>
#include <string.h> // Para strcspn()

// ----- Constantes globais -------
#define MAX_TERRITORIOS 5
#define TAM_STRING 30

// ---------- Definição da estrutura (struct) ---------
struct Territorio {
    char nome[TAM_STRING];
    char cor[10];
    int tropas;
};

// ---- Função para limpar o buffer de entrada ----
void limparBufferEntrada() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

// ---- Função principal (main) ----
int main() {
    struct Territorio lista[MAX_TERRITORIOS];
    int total = 0;
    int opcao;

    // ---- Laço principal do menu ----
    do {
        printf("===================================\n");
        printf("        SISTEMA DE TERRITORIOS\n");
        printf("===================================\n");
        printf("1 - Cadastrar novo territorio\n");
        printf("2 - Listar todos os territorios\n");
        printf("0 - Sair\n");
        printf("-----------------------------------\n");
        printf("Escolha uma opcao: ");

        scanf("%d", &opcao);
        limparBufferEntrada();

        switch(opcao) {
            case 1: // Cadastro do território
                printf("---- Cadastro de novo territorio -----\n\n");

                if (total < MAX_TERRITORIOS) {
                    printf("Digite o nome do territorio: ");
                    fgets(lista[total].nome, TAM_STRING, stdin);
                    lista[total].nome[strcspn(lista[total].nome, "\n")] = '\0';

                    printf("Digite a cor do exercito: ");
                    fgets(lista[total].cor, 10, stdin);
                    lista[total].cor[strcspn(lista[total].cor, "\n")] = '\0';

                    printf("Digite a quantidade de tropas: ");
                    scanf("%d", &lista[total].tropas);
                    limparBufferEntrada();

                    total++;
                    printf("Territorio cadastrado com sucesso!\n");
                } else {
                    printf("Limite maximo de territorios atingido.\n");
                }

                printf("\nPressione Enter para continuar...");
                getchar();
                break;

            case 2: // Listagem
                printf("---- Lista de territorios cadastrados ----\n\n");

                if (total == 0) {
                    printf("Nenhum territorio cadastrado ainda.\n");
                } else {
                    for (int i = 0; i < total; i++) {
                        printf("---------------------\n");
                        printf("TERRITORIO %d\n", i + 1);
                        printf("Nome: %s\n", lista[i].nome);
                        printf("Cor do exercito: %s\n", lista[i].cor);
                        printf("Tropas: %d\n", lista[i].tropas);
                    }
                    printf("----------------------------------\n");
                }

                printf("\nPressione Enter para continuar...");
                getchar();
                break;

            case 0:
                printf("\nSaindo do sistema...\n");
                break;

            default:
                printf("\nOpcao invalida! Tente novamente.\n");
                printf("\nPressione Enter para continuar...\n");
                getchar();
                break;
        }

    } while (opcao != 0);

    return 0;
}