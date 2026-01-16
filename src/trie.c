#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../include/trie.h"

// Estrutura para no TST
struct noTST{
    char ch;
    int valor;
    struct noTST* menor;
    struct noTST* igual;
    struct noTST* maior;
};

// Funcao para criar arvore trie
// Pre-condicao: nenhuma
// Pos-condicao: retorna ponteiro para noTST
TST_TRIE* criar_trie()
{
    TST_TRIE* h = malloc(sizeof(TST_TRIE));
    if(!h)
        erro();

    *h = NULL;

    return h;
}

// Funcao estatica auxiliar para liberar nos
// Pre-condicao: nenhuma
// Pos-condicao: nenhuma
static void liberar_recursivo(TST_TRIE h)
{
    if(vazia(h))
        return;

    liberar_recursivo(h->menor);
    liberar_recursivo(h->igual);
    liberar_recursivo(h->maior);

    free(h);
}

// Funcao para liberar arvore trie
// Pre-condicao: arvore criada
// Pos-condicao: destroi os nosTST
TST_TRIE* liberar(TST_TRIE* h)
{
    liberar_recursivo(*h);

    free(h);

    return NULL;
}

// Funcao para verificar se um noTST eh vazio
// Pre-condicao: nenhuma
// Pos-condicao: retorna 0 se vazia
BOOL vazia(TST_TRIE h)
{
    return (h == NULL);
}

// Funcao estatica auxiliar para inserir palavra
// Pre-condicao: nenhuma
// Pos-condicao: insere caractere por caractere na arvore
static TST_TRIE insere(TST_TRIE h, char* str, int valor)
{
    if(vazia(h)){
        h = malloc(sizeof(struct noTST));
        if(!h)
            erro();

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

// Funcao para inserir em arvoreTST
// Pre-condicao: arvore criada
// Pos-condicao: insere novas palavras
BOOL inserirTST(TST_TRIE* h, char* str, int valor)
{
    if(buscarTST(h, str))
        return FALSE;

    *h = insere(*h, str, valor);

    return TRUE;
}

// Funcao estatica auxiliar para remover palavra
// Pre-condicao: nenhuma
// Pos-condicao: remove caractere por caractere ate a raiz ou divisao
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

// Funcao para remover palavra em arvoreTST
// Pre-condicao: arvore criada
// Pos-condicao: retorna palavra removida
char* removerTST(TST_TRIE* h, char* str)
{
    if(!buscarTST(h, str))
        return NULL;

    char* str_removida = malloc(BUFFER_MAX * sizeof(char));
    if(!str_removida)
        erro();

    strcpy(str_removida, str);

    *h = remover(*h, str);

    return str_removida;
}

// Funcao estatica auxiliar para imprimir dicionario
// Pre-condicao: nenhuma
// Pos-condicao: nenhuma
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

// Funcao para imprimir palavras
// Pre-condicao: arvore criada
// Pos-condicao: nenhuma
void imprimir_dicionarioTST(TST_TRIE* h)
{
    if(vazia(*h))
        return;

    char *buffer = malloc(BUFFER_MAX * sizeof(char));
    if(!buffer)
        erro();

    printf("====================\n");
    imprimir_dicionario_aux(*h, buffer, 0);
    printf("====================\n");

    free(buffer);
}

// Funcao estatica auxiliar para buscar palavras por prefixo
// Pre-condicao: nenhuma
// Pos-condicao: nenhuma
static void buscarPrefixo_aux(TST_TRIE h, char* buffer, char* str, int n)
{
    if(vazia(h))
        return;

    buscarPrefixo_aux(h->menor, buffer, str, n);

    buffer[n] = h->ch;

    if(h->valor != -1){
        register int i;
        register int j;
        BOOL flag = TRUE;

        buffer[n+1] = 0;

        for(i = 0, j = 0; i < strlen(str) && j < strlen(buffer); i++, j++)
            if(buffer[j] != str[i])
                flag = FALSE;

        if(flag)
            printf("%s\n", buffer);
    }

    buscarPrefixo_aux(h->igual, buffer, str, n+1);
    buscarPrefixo_aux(h->maior, buffer, str, n);
}

// Funcao para buscar palavras com determinado prefixo
// Pre-condicao: arvore criada
// Pos-condicao: nenhuma
void buscarPrefixo(TST_TRIE* h, char* str)
{
    char* buffer = malloc(BUFFER_MAX * sizeof(char));
    if(!buffer)
        erro();

    buscarPrefixo_aux(*h, buffer, str, 0);

    free(buffer);
}

// Funcao estatica auxiliar para buscar palavra
// Pre-condicao: nenhuma
// Pos-condicao: ponteiro para inteiro recebe 1 se encontrada
static void buscarTST_aux(TST_TRIE h, char* str, char* buffer, int n, BOOL* res)
{
    if(vazia(h))
        return;

    buscarTST_aux(h->menor, str, buffer, n, res);
    buffer[n] = h->ch;

    if(h->valor != -1){
        buffer[n+1] = 0;

        if(!strcmp(buffer, str))
            *res = TRUE;
    }

    buscarTST_aux(h->igual, str, buffer, n+1, res);
    buscarTST_aux(h->maior, str, buffer, n, res);
}

// Funcao para buscar palavras em arvoreTST
// Pre-condicao: nenhuma
// Pos-condicao: retorna 1 se a palavra existir
BOOL buscarTST(TST_TRIE* h, char* str)
{
    BOOL res = FALSE;
    char* buffer = malloc(BUFFER_MAX * sizeof(char));
    if(!buffer)
        erro();

    buscarTST_aux(*h, str, buffer, 0, &res);

    free(buffer);

    return res;
}

// Funcao para exibir erro de alocacao
// Pre-condicao: memoria nao pode ser alocada
// Pos-condicao: encerra o programa
void erro()
{
    printf("Nao foi possivel alocar memoria\n");
    exit(1);
}
