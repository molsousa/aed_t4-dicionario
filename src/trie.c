#include <stdio.h>
#include <stdlib.h>
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

boolean vazia(TST_TRIE h)
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

static boolean buscaValor(TST_TRIE h, int valor)
{
    if(vazia(h))
        return false;

    if(h->valor == valor)
        return true;

    buscaValor(h->menor, valor);
    buscaValor(h->igual, valor);
    buscaValor(h->maior, valor);

    return false;
}

boolean inserirTST(TST_TRIE* h, char* str, int valor)
{
    if(buscaValor(*h, valor))
        return false;

    *h = insere(*h, str, valor);

    return true;
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

        if(h->igual == NULL && h->valor == -1){
            free(h);
            return NULL;
        }
    }

    return h;
}

void removerTST(TST_TRIE* h, char* str)
{
    *h = remover(*h, str);
}

void imprimir_dicionarioTST(TST_TRIE* h)
{
    if(vazia(*h))
        return;

    imprimir_dicionarioTST(&(*h)->menor);

    if((*h)->valor != -1)
        printf("%d\n", (*h)->valor);

    imprimir_dicionarioTST(&(*h)->igual);
    imprimir_dicionarioTST(&(*h)->maior);
}
