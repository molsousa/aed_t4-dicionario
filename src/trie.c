#include <stdio.h>
#include <stdlib.h>
#include "../include/trie.h"

struct noTST{
    char ch;
    int valor;
    struct noTST* menor;
    struct noTST* igual;
    struct noTST* maior;
};
