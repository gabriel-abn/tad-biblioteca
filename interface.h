#ifndef INTERFACE_H_INCLUDED
#define INTERFACE_H_INCLUDED

#include<stdio.h>
#include<stdlib.h>
#include "livro.h"
#include "emprestimo.h"
#include "usuario.h"

void MSG_MENU();
void MSG_SUBMENU(int opcao);
void SubMenu_Modulo1(TModuloLivro *, TLivro );
void SubMenu_Modulo2(TModuloUsuario *, TUsuario );
void SubMenu_Modulo3(TModuloEmprestimo *, TEmprestimo );

#endif