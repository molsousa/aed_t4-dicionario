#ifndef _LER_ARQUIVO_H_INCLUDED
#define _LER_ARQUIVO_H_INCLUDED

#define NOME_MAX 32
#define ASCII_BASE 97

#include "trie.h"

// Funcao para ler arquivo de texto
// Pre-condicao: nenhuma
// Pos-condicao: insere palavras em arvoreTST
void ler_arquivo_texto(TST_TRIE*);

// Funcao para verificar condicao de uma palavra
// Pre-condicao: nenhuma
// Pos-condicao: insere determinada palavra se bem adequada
void verificar_string(TST_TRIE*, char*, int*);

// Funcao para ler arquivo de stopwords
// Pre-condicao: nenhuma
// Pos-condicao: remove palavras do stopwords se inseridas em arvoreTST
void ler_arquivo_stopwords(TST_TRIE*);

#endif // _LER_ARQUIVO_H_INCLUDED
