#include "include/trie.h"
#include "include/ler_arquivo.h"

int main()
{
    TST_TRIE* h = criar_trie();

    ler_arquivo_texto(h);

    //imprimir_dicionarioTST(h);

    buscarPrefixo(h, "a");

    return 0;
}
