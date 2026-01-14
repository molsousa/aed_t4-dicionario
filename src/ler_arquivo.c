#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/ler_arquivo.h"

void ler_arquivo_texto(TST_TRIE* h)
{
    char arquivo[NOME_MAX] = "teste.txt";
    char str[NOME_MAX];
    int i = 0;

    /*
    printf("Insira o nome do arquivo de texto: ");
    scanf("%[^\n]%*c", arquivo);
    */

    FILE* fr = fopen(arquivo, "r");

    while(fgets(str, NOME_MAX, fr)){
        strtok(str, "\n");

        verificar_string(h, str, &i);
    }

    fclose(fr);
}

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

    if(flag){
        inserirTST(h, str, *valor);
        ++*valor;
    }
}

void ler_arquivo_stopwords(TST_TRIE* h)
{
    char arquivo[NOME_MAX] = "stopwords.txt";
    char str[NOME_MAX];

    /*
    printf("Insira o nome do arquivo de texto: ");
    scanf("%[^\n]%*c", arquivo);
    */

    FILE* fr = fopen(arquivo, "r");

    while(fgets(str, NOME_MAX, fr)){
        strtok(str, "\n");

        removerTST(h, str);
    }

    fclose(fr);
}
