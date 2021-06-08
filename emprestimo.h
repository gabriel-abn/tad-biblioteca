typedef struct data{
    int dia;
    int mes;
    int ano;
}TData;

typedef struct TipoEmprestimo
{
    char CPF[15];
    char ISBN[20];
    TData data_emprestimo;
    TData data_entrega;
    TData data_devolucao;
}TEmprestimo;
