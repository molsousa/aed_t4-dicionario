#include <stdio.h>
#include <stdlib.h>
#include "include/trie.h"
#include "include/ler_arquivo.h"

void menu();

int main()
{
    menu();

    return 0;
}

void menu()
{
    TST_TRIE* h = criar_trie();
    char* str = malloc(BUFFER_MAX * sizeof(char));
    int opcao;

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

        switch(opcao){
            case 1:
                imprimir_dicionarioTST(h);
                system("sleep 5");
                break;
            case 2:
                ler_arquivo_texto(h);
                break;
            case 3:
                ler_arquivo_stopwords(h);
                break;
            case 4:
                {
                    printf("Insira o prefixo: ");
                    scanf("%[^\n]%*c", str);
                    buscarPrefixo(h, str);
                    system("sleep 5");
                }
                break;
            case 0:
                printf("Obrigado!!\n");
                break;
            default:
                printf("Opcao invalida, tente novamente!!");
                break;
        }
        system("clear");
    }while(opcao != 0);

    free(str);
    h = liberar(h);
}
