#ifndef _LER_ARQUIVO_H_INCLUDED
#define _LER_ARQUIVO_H_INCLUDED

#include "trie.h"

// Funcao para ler arquivo de texto
// Pre-condicao: nenhuma
// Pos-condicao: insere palavras em arvoreTST
// Entrada: arvoreTST, valor a ser atribuido a cada palavra inserida
void ler_arquivo_texto(TST_TRIE*, int*);

// Funcao para verificar condicao de uma palavra
// Pre-condicao: nenhuma
// Pos-condicao: insere determinada palavra se bem adequada
// Entrada: arvoreTST, palavra a ser inserida, valor a ser atribuido a palavra
void verificar_string(TST_TRIE*, char*, int*);

// Funcao para ler arquivo de stopwords
// Pre-condicao: nenhuma
// Pos-condicao: remove palavras do stopwords se inseridas em arvoreTST
// Entrada: arvoreTST
void ler_arquivo_stopwords(TST_TRIE*);

#endif // _LER_ARQUIVO_H_INCLUDED
