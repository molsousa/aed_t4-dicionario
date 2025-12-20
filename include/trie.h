#ifndef ARVORE_BUSCA_TERNARIA_TRIE_H_INCLUDED
#define ARVORE_BUSCA_TERNARIA_TRIE_H_INCLUDED

typedef struct noTST* TST_TRIE;
typedef enum{true = 1, false = 0}boolean;

TST_TRIE* criar_trie();

boolean inserirTST(TST_TRIE*, char*, int);

void removerTST(TST_TRIE*, char*);

void imprimir_dicionarioTST(TST_TRIE*);

int buscarTST(TST_TRIE*, char*);

#endif // ARVORE_BUSCA_TERNARIA_TRIE_H_INCLUDED
