# Dicionário

## Descrição

Este repositório contém um programa que simula um dicionário. Esse que fora desenvolvido para a disciplina de Algoritmos e Estrutura de Dados.

## Opções para o usuário

O usuário tem acesso a:

- Imprimir palavras já inseridas no dicionário.
- Inserir novas palavras via arquivo de texto.
- Remover palavras via arquivo de texto.
- Consultar palavras via prefixo.

## Implementação

- O código foi escrito em C.

- A estrutura de dados utilizada para o desenvolvimento do programa foi a RETRIEVAL TST (Ternary Search Tree - Trie).

- Essa estrutura permite com que as palavras sejam armazenadas dinamicamente em um sistema similar com uma árvore binária. Os campos `menor`e `maior` servem para buscar um caractere menor ou maior que o buscado seguindo os valores da tabela ASCII, o campo `igual` serve para localizar a palavra por completo ou seu prefixo.

## Como utilizar

### Sintaxe do arquivo de texto

A sintaxe do arquivo de texto é simples, apenas empilhe uma palavra seguida da aula separadas por quebras de linha, como no exemplo abaixo:

    limao
    cama
    onibus
    pedra
    poste
    trem

Para cada nova palavra adicionada, um valor a partir de 0 será atribuído ao final da cadeia de caracteres, por exemplo, a palavra `limao` terá seu valor `0` atribuído ao final da palavra.

### Compilação e Execução

É necessário compilar os arquivos de código fonte e executar o programa seguindo o código abaixo na pasta raiz:

    gcc *.c -o dicionario.exe
    .\dicionario.exe