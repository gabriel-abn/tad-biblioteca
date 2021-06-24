#include<stdio.h>
#include<stdlib.h>
#include "livro.h"
#include "emprestimo.h"
#include "usuario.h"
#include "interface.h"

int main()
{
    TModuloEmprestimo mod_emp;
    TModuloLivro mod_liv;
    TModuloUsuario mod_usu;

    TUsuario usuario;
    TLivro livro;
    TEmprestimo emprestimo;

    int opcao = 0;

    IniciarVetorEmprestimo(&mod_emp);
    IniciarVetorLivro(&mod_liv);
    IniciarVetorUsuario(&mod_usu);

    do
    {
        system("cls");
        MSG_MENU();
        printf("\nDigite uma opcao: ");
        fflush(stdin);
        scanf("%d", &opcao);
        switch (opcao)
        {
        case 1:
            SubMenu_Modulo1(&mod_liv, livro);
            break;
        case 2:
            SubMenu_Modulo2(&mod_usu, usuario);
            break;
        case 3:
            SubMenu_Modulo3(&mod_emp, emprestimo);
            break;
        case 4:
            system("cls");
            printf("\n\n\t >>>>>>>>>> MSG: Saindo do programa <<<<<<<<<<");
            break;
        
        default:
            system("cls");
            printf("\n\n\t >>>>>>>>>> MSG: Saindo do programa <<<<<<<<<<");
            system("PAUSE");
            printf("\n\n\t >>>>>>>>>> MSG: Pressione uma tecla para continuar <<<<<<<<<<");
            break;
        }
    } while (opcao != 4);

    return 0;
}
