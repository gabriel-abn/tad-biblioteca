typedef struct data{
    int dia;
    int mes;
    int ano;
}TData;

typedef struct livro{
    char ISBN[20];
    char titulo[100];
    char editora[100];
    char local[100];
    TData data_pub;
    char prim_autor[100];
    char seg_autor[100];
    int quantidade;
    int quant_emprestados;
}TLivro;

typedef struct biblioteca{
    TLivro vetor[100];
    int indice; 
}TBiblioteca;

void IniciarVetor(TBiblioteca *);
int Cadastrar(TBiblioteca *, TLivro );
void Imprimir(TLivro );