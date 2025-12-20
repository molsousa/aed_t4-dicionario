#include "include/trie.h"

int main()
{
    TST_TRIE* h = criar_trie();

    inserirTST(h, "marcos", 5);
    inserirTST(h, "maracuja", 12);
    inserirTST(h, "mestre", 43);
    inserirTST(h, "mitre", 23);
    inserirTST(h, "adelio", 9);
    inserirTST(h, "ademir", 15);
    inserirTST(h, "consoante", 18);

    imprimir_dicionarioTST(h);

    return 0;
}
