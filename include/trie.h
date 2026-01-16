#ifndef ARVORE_BUSCA_TERNARIA_TRIE_H_INCLUDED
#define ARVORE_BUSCA_TERNARIA_TRIE_H_INCLUDED

#define BUFFER_MAX 32

// Definicao de tipo para noTST
typedef struct noTST* TST_TRIE;
// Definicao de tipo booleano
typedef enum{FALSE = 0, TRUE = 1}BOOL;

// Funcao para criar arvore trie
// Pre-condicao: nenhuma
// Pos-condicao: retorna ponteiro para noTST
// Entrada: nenhuma
TST_TRIE* criar_trie();

// Funcao para liberar arvore trie
// Pre-condicao: arvore criada
// Pos-condicao: destroi os nosTST
// Entrada: arvoreTST
TST_TRIE* liberar(TST_TRIE*);

// Funcao para verificar se um noTST eh vazio
// Pre-condicao: nenhuma
// Pos-condicao: retorna 0 se vazia
// Entrada: noTST
BOOL vazia(TST_TRIE);

// Funcao para inserir em arvoreTST
// Pre-condicao: arvore criada
// Pos-condicao: insere novas palavras
// Entrada: arvoreTST, palavra a ser inserida, valor a ser atribuido a palavra
BOOL inserirTST(TST_TRIE*, char*, int);

// Funcao para remover palavra em arvoreTST
// Pre-condicao: arvore criada
// Pos-condicao: retorna palavra removida
// Entrada: arvoreTST, palavra a ser removida
char* removerTST(TST_TRIE*, char*);

// Funcao para imprimir palavras
// Pre-condicao: arvore criada
// Pos-condicao: nenhuma
// Entrada: arvoreTST
void imprimir_dicionarioTST(TST_TRIE*);

// Funcao para buscar palavras com determinado prefixo
// Pre-condicao: arvore criada
// Pos-condicao: nenhuma
// Entrada: arvoreTST, prefixo a ser buscado
void buscarPrefixo(TST_TRIE*, char*);

// Funcao para buscar palavras em arvoreTST
// Pre-condicao: nenhuma
// Pos-condicao: retorna 1 se a palavra existir
// Entrada: arvoreTST, palavra a ser buscada
BOOL buscarTST(TST_TRIE*, char*);

// Funcao para exibir erro de alocacao
// Pre-condicao: memoria nao pode ser alocada
// Pos-condicao: encerra o programa
// Entrada: nenhuma
void erro();

#endif // ARVORE_BUSCA_TERNARIA_TRIE_H_INCLUDED
