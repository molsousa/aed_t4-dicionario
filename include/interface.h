#ifndef _INTERFACE_H_INCLUDED
#define _INTERFACE_H_INCLUDED

// Menu para usuario
// Pre-condicao: nenhuma
// Pos-condicao: nenhuma
void menu();

// Funcao para pausar por 3seg no linux
// Pre-condicao: nenhuma
// Pos-condicao: se windows, usa o pause
void pause3();

// Funcao para pausar por 5seg no linux
// Pre-condicao: nenhuma
// Pos-condicao: se windows, usa o pause
void pause5();

// Funcao para limpar terminal
// Pre-condicao: nenhuma
// Pos-condicao: nenhuma
void cls();

#endif // _INTERFACE_H_INCLUDED
