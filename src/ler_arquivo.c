#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/ler_arquivo.h"

// Funcao para ler arquivo de texto
// Pre-condicao: nenhuma
// Pos-condicao: insere palavras em arvoreTST
void ler_arquivo_texto(TST_TRIE* h, int* valor)
{
    char arquivo[NOME_MAX];
    char str[NOME_MAX];

    printf("Insira o nome do arquivo de texto: ");
    scanf("%[^\n]%*c", arquivo);

    FILE* fr = fopen(arquivo, "r");

    while(fgets(str, NOME_MAX, fr)){
        strtok(str, "\n");

        verificar_string(h, str, valor);
    }

    fclose(fr);
}

// Funcao para verificar condicao de uma palavra
// Pre-condicao: nenhuma
// Pos-condicao: insere determinada palavra se bem adequada
void verificar_string(TST_TRIE* h, char* str, int* valor)
{
    register int i;
    int flag = 1;

    for(i = 0; i < strlen(str); i++){
        if(str[i] < 65)
            flag = 0;

        if(str[i] > 90)
            if(str[i] < 97 || str[i] > 122)
                flag = 0;
    }

    if(flag)
        if(inserirTST(h, str, *valor))
            ++*valor;
}

// Funcao para ler arquivo de stopwords
// Pre-condicao: nenhuma
// Pos-condicao: remove palavras do stopwords se inseridas em arvoreTST
void ler_arquivo_stopwords(TST_TRIE* h)
{
    char arquivo[NOME_MAX] = "stopwords.txt";
    char str[NOME_MAX];

    printf("Insira o nome do arquivo de texto: ");
    scanf("%[^\n]%*c", arquivo);

    FILE* fr = fopen(arquivo, "r");

    while(fgets(str, NOME_MAX, fr)){
        strtok(str, "\n");

        char* str_removida = removerTST(h, str);
        printf("Palavra removida: %s\n", str_removida);
        free(str_removida);
    }

    fclose(fr);
}
