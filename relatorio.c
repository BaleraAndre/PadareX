#include <stdio.h>
#include <stdlib.h>
#include "cadastro.c"
#include <locale.h>

//menu de relatorios
char menuRelatorios()
{
   system("clear");
   char op;
   printf("Digite 1 para um relatório de gastos\n");
   printf("Digite 2 para um relatório de vendas\n");
   printf("Digite 9 para sair\n");
   scanf(" %c", &op);
   return op;
};
//funçao para listar todos os gastos
char relatorioGastos()
{
   system("clear");
   struct Gasto gastos;
   FILE *gast;
   gast = fopen("Gastos.txt", "r+b");

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
         printf("Nenhum gasto ate o momento\n");
      }
      else
      {
         rewind(gast);

         while (!feof(gast))
         {
            fread(&gastos, sizeof(struct Gasto), 1, gast);
            if (!feof(gast))
            {
               printf("NOME: %s  VALOR: %.2lf\n", gastos.Nome, gastos.Valor);
            }
         }
      }
      fclose(gast);
      printf("\n");
   }
};
//funçao para listar todas as vendas
char relatorioVendas()
{
   system("clear");
   struct Venda Venda;
   FILE *Vend;
   Vend = fopen("Vendas.txt", "r+b");

   if (Vend == NULL)
   {
      printf("Erro ao abrir o arquivo.\n");
      exit(1);
   }
   else
   {
      fseek(Vend, 0, SEEK_END);
      if (ftell(Vend) == 0)
      {
         printf("Nenhuma venda realizada\n");
      }
      else
      {
         rewind(Vend);
         while (!feof(Vend))
         {
            fread(&Venda, sizeof(struct Venda), 1, Vend);
            if (!feof(Vend))
            {
               printf("NOME: %s  VALOR: %.2lf  UNIDADES: %d\n", Venda.Nome, Venda.preco, Venda.unidades);
            }
         }
      }
      fclose(Vend);
      printf("\n");
   }
}
// funçao informaçoes
char Informacao(){

   system("clear");
   printf("INFORMAÇÕES SOBRE O PROGRAMA\n\n");
   printf("DESCRIÇÃO:\n");
   printf("Programa para gerenciamento das funcionalidades de uma padaria\n\n");
   printf("FUNCIONALIDADES:\n");
   printf("Gerenciamento de Funcionários, clientes ,Controle de estoque\n");
   printf("capaz de gerar ralatórios de vendas e de gastos\n");
   printf("com controle de acesso por usuário/senha\n\n\n");
   printf("VERSÃO 1.0.0\n\n");
   printf("SUPORTE PADAREX:\n");
   printf("ENTRE EM CONTATO NO NUMERO: 1298888-8888\n\n\n");

   printf("Digite qualquer tecla para voltar\n");
   getchar();
   getchar();
   system("clear");





}
