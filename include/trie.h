#ifndef ARVORE_BUSCA_TERNARIA_TRIE_H_INCLUDED
#define ARVORE_BUSCA_TERNARIA_TRIE_H_INCLUDED

#define BUFFER_MAX 32

// Definicao de tipo para noTST
typedef struct noTST* TST_TRIE;

// Funcao para criar arvore trie
// Pre-condicao: nenhuma
// Pos-condicao: retorna ponteiro para noTST
TST_TRIE* criar_trie();

// Funcao para liberar arvore trie
// Pre-condicao: arvore criada
// Pos-condicao: destroi os nosTST
TST_TRIE* liberar(TST_TRIE*);

// Funcao para verificar se um noTST eh vazio
// Pre-condicao: nenhuma
// Pos-condicao: retorna 0 se vazia
int vazia(TST_TRIE);

// Funcao para inserir em arvoreTST
// Pre-condicao: arvore criada
// Pos-condicao: insere novas palavras
int inserirTST(TST_TRIE*, char*, int);

// Funcao para remover palavra em arvoreTST
// Pre-condicao: arvore criada
// Pos-condicao: retorna palavra removida
char* removerTST(TST_TRIE*, char*);

// Funcao para imprimir palavras
// Pre-condicao: arvore criada
// Pos-condicao: nenhuma
void imprimir_dicionarioTST(TST_TRIE*);

// Funcao para buscar palavras com determinado prefixo
// Pre-condicao: arvore criada
// Pos-condicao: nenhuma
void buscarPrefixo(TST_TRIE*, char*);

// Funcao para buscar palavras em arvoreTST
// Pre-condicao: nenhuma
// Pos-condicao: retorna 1 se a palavra existir
int buscarTST(TST_TRIE*, char*);

#endif // ARVORE_BUSCA_TERNARIA_TRIE_H_INCLUDED
