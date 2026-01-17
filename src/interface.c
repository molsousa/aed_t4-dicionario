#include <stdio.h>
#include <stdlib.h>

#include "../include/trie.h"
#include "../include/ler_arquivo.h"
#include "../include/interface.h"

// Menu para usuario
// Pre-condicao: nenhuma
// Pos-condicao: nenhuma
void menu()
{
    TST_TRIE* h = criar_trie();
    char* str = malloc(BUFFER_MAX * sizeof(char));
    int opcao;
    int valor = 0;

    do{
        printf(">>==DICIONARIO=ARVORE=DE=BUSCA=TRIE==<<\n");
        printf("|| 1 - Imprimir dicionario           ||\n");
        printf("|| 2 - Carregar arquivo de palavras  ||\n");
        printf("|| 3 - Carregar arquivo de stopwords ||\n");
        printf("|| 4 - Consultar prefixo             ||\n");
        printf("|| 0 - Sair                          ||\n");
        printf(">>===================================<<\n");
        printf("Escolha uma opcao: ");

        scanf("%d%*c", &opcao);
        cls();

        switch(opcao){
            case 1:
                imprimir_dicionarioTST(h);
                pause5();
                break;

            case 2:
                ler_arquivo_texto(h, &valor);
                break;

            case 3:
                ler_arquivo_stopwords(h);
                pause5();
                break;

            case 4:
                {
                    printf("Insira o prefixo: ");
                    scanf("%[^\n]%*c", str);
                    buscarPrefixo(h, str);
                    pause5();
                }
                break;

            case 0:
                printf("Obrigado!!\n");
                pause3();
                break;

            default:
                printf("Opcao invalida, tente novamente!!");
                pause3();
                cls();
                break;
        }
        cls();
    }while(opcao != 0);

    free(str);
    h = liberar(h);
}

// Funcao para pausar por 3seg no linux
// Pre-condicao: nenhuma
// Pos-condicao: se windows, usa o pause
void pause3()
{
    #ifdef _WIN32
    system("pause");
    #elif __linux__
    system("sleep 1");
    #endif
}

// Funcao para pausar por 5seg no linux
// Pre-condicao: nenhuma
// Pos-condicao: se windows, usa o pause
void pause5()
{
    #ifdef _WIN32
    system("pause");
    #elif __linux__
    system("sleep 5");
    #endif
}

// Funcao para limpar terminal
// Pre-condicao: nenhuma
// Pos-condicao: nenhuma
void cls()
{
    #ifdef _WIN32
    system("cls");
    #elif __linux__
    system("clear");
    #endif
}
