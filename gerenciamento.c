#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

//criando os structs
struct Perfis
{
    char Senha[15];
    char Usuario[20];
};
struct CadastroFuncionarios
{
  int ID;
  char Nome[40];
  char CPF[20];
  char Endereco[40];
  double Salario;
};
struct CadastroClientes
{
  int ID;
  char Nome[40];
  char CPF[20];
  char Endereco[40];
};
struct Produtos
{
  int ID;
  char Nome[20];
  int Unidades;
  double PrecoCompra;
};

//variavel de controle
char op;
//menu de gerenciamento
char menuGerenciamento()
{
  system("clear");
  char op;
  printf("Digite 1 para listar todos os funcionários\n");
  printf("Digite 2 para listar todos os clientes\n");
  printf("Digite 3 para listar todos os usuários\n");
  printf("Digite 4 para listar todos os items do estoque\n");
  printf("Digite 9 para sair\n");
  scanf(" %c", &op);
  return op;
};
//funçao para listar todos funcionarios
char ListarFuncionarios()
{

  system("clear");
  struct CadastroFuncionarios func;
  FILE *gast;
  gast = fopen("Funcionarios.txt", "r+b");

  if (gast == NULL)
  {
    printf("Erro ao abrir o arquivo.\n");
    exit(1);
  }
  else
  {

    fseek(gast, 0, SEEK_END);
    if (ftell(gast) == 0)
    {
      printf("Nenhum funcionário cadastrado\n");
    }
    else
    {
      rewind(gast);

      while (!feof(gast))
      {

        fread(&func, sizeof(struct CadastroFuncionarios), 1, gast);
        if (!feof(gast))
        {
          printf("ID: %d  NOME: %s  cpf: %s  ENDEREÇO: %s SALÁRIO: %.2lf\n", func.ID, func.Nome, func.CPF, func.Endereco, func.Salario);
        }
      }
    }
  }

  fclose(gast);
}
//funçao para listar todos os clientes
char ListarClientes()
{

  system("clear");
  struct CadastroClientes cli;
  FILE *gast;
  gast = fopen("Clientes.txt", "r+b");

  if (gast == NULL)
  {
    printf("Erro ao abrir o arquivo.\n");
    exit(1);
  }
  else
  {
    fseek(gast, 0, SEEK_END);
    if (ftell(gast) == 0)
    {
      printf("Nenhum cliente cadastrado\n");
    }
    else
    {
      rewind(gast);

      while (!feof(gast))
      {
        fread(&cli, sizeof(struct CadastroClientes), 1, gast);
        if (!feof(gast))
        {
          printf("ID: %d  NOME: %s  CPF: %s  ENDEREÇO: %s \n", cli.ID, cli.Nome, cli.CPF, cli.Endereco);
        }
      }
    }
  }
  fclose(gast);
}
//funçao para listar todos os perfis
char ListarPerfis()
{

  system("clear");
  struct Perfil pf;
  FILE *gast;
  gast = fopen("Perfis.txt", "r+b");

  if (gast == NULL)
  {
    printf("Erro ao abrir o arquivo.\n");
    exit(1);
  }
  else
  {
    fseek(gast, 0, SEEK_END);
    if (ftell(gast) == 0)
    {
      printf("NENHUM PERFIL CADASTRADO\n");
    }
    else
    {
      rewind(gast);

      while (!feof(gast))
      {
        fread(&pf, sizeof(struct Perfis), 1, gast);
        if (!feof(gast))
        {
          printf("USUÁRIO: %s\n" , pf.Usuario);
        }
      }
    }
  }
  fclose(gast);
}
//funçao para listar todos os items no estoque
char ListarEstoque()
{
  system("clear");
  struct Produtos pr;
  FILE *gast;
  gast = fopen("Produtos.txt", "r+b");

  if (gast == NULL)
  {
    printf("Erro ao abrir o arquivo.\n");
    exit(1);
  }
  else
  {

    fseek(gast, 0, SEEK_END);
    if (ftell(gast) == 0)
    {
      printf("Nenhum produto cadastrado\n");
    }
    else
    {
      rewind(gast);

      while (!feof(gast))
      {
        fread(&pr, sizeof(struct Produtos), 1, gast);
        if (!feof(gast))
        {
          printf("ID: %d  NOME: %s  QUANTIDADE: %d  PREÇO DE COMPRA: %.2lf \n", pr.ID, pr.Nome, pr.Unidades, pr.PrecoCompra);
        }
      }
    }
  }
  fclose(gast);
  fflush(stdin);
  fflush(stdout);
}
//menu principal
char menu()
{

  printf("Menu principal\n");
  printf("Digite 1 para area de cadastros\n");
  printf("Digite 2 para area de gerenciamento\n");
  printf("Digite 3 para area de relatórios\n");
  printf("Digite 4 para area de vendas\n");
  printf("Digite 5 para acessar dicas de uso\n");
  printf("Digite 6 para informações\n");
  printf("Digite 9 para sair\n");

  scanf(" %c", &op);
  return op;
};
