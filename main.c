#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <math.h>
#include "relatorio.c"
#include "gerenciamento.c"

//variavel de controle
int check = 1;
int i;
char operacao;
char teste = 'n';
//funçao main
int main(){
    // ↓↓↓ acho que só precisa no windows
// setlocale(LC_ALL, "Portuguese");

   while (check ==1)
   {
      check = LogIn();

   }

   while (teste != '9')
   {

      operacao = menu();
      teste = operacao;
      switch (operacao)
      {
      case '1':
      {

         operacao = menuCadastro();

         if (operacao == 1 || operacao == '1')
         {
            CadastroFuncionario();
         }

         else if (operacao == 2 || operacao == '2')
         {
            CadastroCliente();
         }
         else if (operacao == 3 || operacao == '3')
         {
            CadastroPerfil();
         }
         else if (operacao == 4 || operacao == '4')
         {
            CadastroProduto();
         }
         else if (operacao == 5 || operacao == '5')
         {
            CadastroPagamento();
         }

         else if (operacao == 6 || operacao == '6')
         {
            CadastroQuantidade();
         }

         else if (operacao == 9 || operacao == '9')
         {
            teste = 'n';
         }
         else
         {
            printf("erro\n");
         }
      };
      break;

      case '2':

         getchar();
         operacao = menuGerenciamento();
         if (operacao == 1 || operacao == '1')
         {

            ListarFuncionarios();
         }
         else if (operacao == 2 || operacao == '2')
         {
            ListarClientes();
         }
         else if (operacao == 3 || operacao == '3')
         {
            ListarPerfis();
         }
         else if (operacao == 4 || operacao == '4')
         {
            ListarEstoque();
         }

         break;
      case '3':
         operacao = menuRelatorios();
         if (operacao == '1' || operacao == 1)
         {
            relatorioGastos();
         }
         else if (operacao == '2' || operacao == 2)
         {
            relatorioVendas();
         }
         break;
      case '4':
         operacao = Vendas();
         break;
         case '9':{};break;

      case '5':
      operacao = Manual();
      break;

      case '6':
      operacao=Informacao();
      break;



      default:
         printf("!!ERROR!! Digite uma opção valida\n");
         break;
      }
   }
}
