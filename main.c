#include<stdio.h>
#include<stdlib.h>
#include "livro.h"
#include "emprestimo.h"
#include "usuario.h"

int main()
{
    TModuloEmprestimo mod_emp;
    TModuloLivro mod_liv;
    TModuloUsuario mod_usu;

    TUsuario teste;

    IniciarVetorEmprestimo(&mod_emp);
    IniciarVetorLivro(&mod_liv);
    IniciarVetorUsuario(&mod_usu);

    LerUsuario(&teste);
    CadastrarUsuario(&mod_usu, teste);
    ImprimirUsuario(teste);
    ImprimirTodosUsuarios(mod_usu);
    PesquisaUsuario(mod_usu, teste);

    return 0;
}
