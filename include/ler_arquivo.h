#ifndef _LER_ARQUIVO_H_INCLUDED
#define _LER_ARQUIVO_H_INCLUDED

#define NOME_MAX 32
#define ASCII_BASE 97

#include "trie.h"

void ler_arquivo_texto(TST_TRIE*);

void verificar_string(TST_TRIE*, char*, int*);

#endif // _LER_ARQUIVO_H_INCLUDED
