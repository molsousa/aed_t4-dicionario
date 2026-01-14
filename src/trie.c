#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/trie.h"

struct noTST{
    char ch;
    int valor;
    struct noTST* menor;
    struct noTST* igual;
    struct noTST* maior;
};

TST_TRIE* criar_trie()
{
    TST_TRIE* h = malloc(sizeof(TST_TRIE));

    *h = NULL;

    return h;
}

static void liberar_recursivo(TST_TRIE h)
{
    if(vazia(h))
        return;

    liberar_recursivo(h->menor);
    liberar_recursivo(h->igual);
    liberar_recursivo(h->maior);

    free(h);
}

TST_TRIE* liberar(TST_TRIE* h)
{
    liberar_recursivo(*h);

    free(h);

    return NULL;
}

int vazia(TST_TRIE h)
{
    return (h == NULL);
}

static TST_TRIE insere(TST_TRIE h, char* str, int valor)
{
    if(vazia(h)){
        h = malloc(sizeof(struct noTST));
        h->ch = *str;
        h->maior = h->menor = h->igual = NULL;
        h->valor = -1;

        if(*(str+1) != 0)
            h->igual = insere(h->igual, str+1, valor);

        else
            h->valor = valor;
    }

    else
        if(*str == h->ch)
            h->igual = insere(h->igual, str+1, valor);

        else if(*str > h->ch)
            h->maior = insere(h->maior, str, valor);

        else
            h->menor = insere(h->menor, str, valor);

    return h;
}

int inserirTST(TST_TRIE* h, char* str, int valor)
{
    if(buscarTST(h, str))
        return 0;

    *h = insere(*h, str, valor);

    return 1;
}

static TST_TRIE remover(TST_TRIE h, char* str)
{
    if(vazia(h))
        return h;

    if(*str < h->ch)
        h->menor = remover(h->menor, str);

    else if(*str > h->ch)
        h->maior = remover(h->maior, str);

    else{
        if(*(str+1) == 0){
            if(h->valor != -1){
                h->valor = -1;
                free(h);
                return NULL;
            }
        }
        else
            h->igual = remover(h->igual, str+1);
    }

    return h;
}

char* removerTST(TST_TRIE* h, char* str)
{
    if(!buscarTST(h, str))
        return NULL;

    char* str_removida = malloc(BUFFER_MAX * sizeof(char));
    strcpy(str_removida, str);

    *h = remover(*h, str);

    return str_removida;
}

static void imprimir_dicionario_aux(TST_TRIE h, char* buffer, int n)
{
    if(vazia(h))
        return;

    imprimir_dicionario_aux(h->menor, buffer, n);

    buffer[n] = h->ch;

    if(h->valor != -1){
        buffer[n+1] = 0;
        printf("%-15s|%4d\n", buffer, h->valor);
    }

    imprimir_dicionario_aux(h->igual, buffer, n+1);
    imprimir_dicionario_aux(h->maior, buffer, n);
}

void imprimir_dicionarioTST(TST_TRIE* h)
{
    if(vazia(*h))
        return;

    char *buffer = malloc(BUFFER_MAX * sizeof(char));

    printf("====================\n");
    imprimir_dicionario_aux(*h, buffer, 0);
    printf("====================\n");

    free(buffer);
}

static void buscarPrefixo_aux(TST_TRIE h, char* buffer, char* str, int n)
{
    if(vazia(h))
        return;

    buscarPrefixo_aux(h->menor, buffer, str, n);

    buffer[n] = h->ch;

    if(h->valor != -1){
        register int i;
        register int j;
        int flag = 1;

        buffer[n+1] = 0;

        for(i = 0, j = 0; i < strlen(str) && j < strlen(buffer); i++, j++){
            if(buffer[j] != str[i])
                flag = 0;
        }

        if(flag)
            printf("%s\n", buffer);
    }

    buscarPrefixo_aux(h->igual, buffer, str, n+1);
    buscarPrefixo_aux(h->maior, buffer, str, n);
}

void buscarPrefixo(TST_TRIE* h, char* str)
{
    char* buffer = malloc(BUFFER_MAX * sizeof(char));

    buscarPrefixo_aux(*h, buffer, str, 0);

    free(buffer);
}

static void buscarTST_aux(TST_TRIE h, char* str, char* buffer, int n, int* res)
{
    if(vazia(h))
        return;

    buscarTST_aux(h->menor, str, buffer, n, res);
    buffer[n] = h->ch;

    if(h->valor != -1){
        buffer[n+1] = 0;

        if(!strcmp(buffer, str))
            *res = 1;
    }

    buscarTST_aux(h->igual, str, buffer, n+1, res);
    buscarTST_aux(h->maior, str, buffer, n, res);
}

// Funcao para buscar palavras em arvoreTST
// Pre-condicao: nenhuma
// Pos-condicao: retorna 1 se a palavra existir
int buscarTST(TST_TRIE* h, char* str)
{
    int res = 0;
    char* buffer = malloc(BUFFER_MAX * sizeof(char));

    buscarTST_aux(*h, str, buffer, 0, &res);

    return res;
}
