#ifndef ARVORE_BUSCA_TERNARIA_TRIE_H_INCLUDED
#define ARVORE_BUSCA_TERNARIA_TRIE_H_INCLUDED

#define BUFFER_MAX 32

typedef struct noTST* TST_TRIE;

TST_TRIE* criar_trie();

int vazia(TST_TRIE);

int inserirTST(TST_TRIE*, char*, int);

void removerTST(TST_TRIE*, char*);

void imprimir_dicionarioTST(TST_TRIE*);

void buscarPrefixo(TST_TRIE*, char*);

int buscarTST(TST_TRIE*, char*);

#endif // ARVORE_BUSCA_TERNARIA_TRIE_H_INCLUDED
