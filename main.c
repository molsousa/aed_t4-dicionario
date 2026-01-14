#include "include/trie.h"
#include "include/ler_arquivo.h"

int main()
{
    TST_TRIE* h = criar_trie();

    ler_arquivo_texto(h);

    ler_arquivo_stopwords(h);

    imprimir_dicionarioTST(h);

    h = liberar(h);

    return 0;
}
