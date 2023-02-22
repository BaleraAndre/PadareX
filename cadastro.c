#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

//variavel de controle
int i;
char op;
char a = 'n';

//criando os struct
struct Venda
{
    int unidades;
    char Nome[20];
    double preco;
};
struct CadastroCliente
{
    int ID;
    char Nome[40];
    char CPF[20];
    char Endereco[40];
};
struct CadastroFuncionario
{
    int ID;
    char Nome[40];
    char CPF[20];
    char Endereco[40];
    double Salario;
};
struct Perfil
{
    char Senha[15];
    char Usuario[20];
};
struct Produto
{
    int ID;
    char Nome[20];
    int Unidades;
    double PrecoCompra;
};
struct Gasto
{
    char Nome[40];
    double Valor;
};

//menu de cadastro
char menuCadastro()
{
    system("clear");
    printf("MENU DE CADASTRO\n");
    printf("Digite 1 para cadastros de funcionários\n");
    printf("Digite 2 para área de cadastro de clientes\n");
    printf("Digite 3 para área de cadastro de perfil\n");
    printf("Digite 4 para área de cadastro de produtos\n");
    printf("Digite 5 para cadastrar um pagamento\n");
    printf("Digite 6 para repor estoque\n");
    printf("Digite 9 para sair\n");

    char op;

    scanf(" %c", &op);

    return op;
};
//area de cadastro de funcionario
char CadastroFuncionario()
{

    system("clear");
    struct CadastroFuncionario f;
    struct Gasto g;

    printf("Entre com o ID para o funcionário:");
    scanf("%d", &f.ID);
    printf("\nEntre com o nome do funcionário:");
    gets(f.Nome);
    gets(f.Nome);
    printf("\nEntre com o CPF do funcionário:");
    gets(f.CPF);
    printf("\nEntre com o endereço do funcionário:");
    gets(f.Endereco);
    printf("\nEntre com o salário do funcionário:");
    scanf("%lf", &f.Salario);
    strcpy(g.Nome, f.Nome);
    g.Valor = f.Salario;

    printf("Confira as informações:\n");
    printf("ID: %d , NOME: %s , CPF: %s , ENDEREÇO: %s , SALÁRIO: %.2lf \n", f.ID, f.Nome, f.CPF, f.Endereco, f.Salario);
    printf("As informações estao corretas? [S/N]:");
    scanf("%c", &a);
    scanf("%c", &a);

    FILE *fp, *gastos;
    fp = fopen("Funcionarios.txt", "a+b");
    gastos = fopen("Gastos.txt", "a+b");
    if (!fp && !gastos)
    {
        printf("Erro na abertura do arquivo\n");
        exit(0);
    }

    else
    {
        fwrite(&f, sizeof(struct CadastroFuncionario), 1, fp);
        fwrite(&g, sizeof(struct Gasto), 1, gastos);
    }
    fclose(fp);
    fclose(gastos);
    return a = 'n';
};
//area de cadastro de cliente
char CadastroCliente()
{
    system("clear");

    struct CadastroCliente c;

    printf("Entre com o ID para o cliente:");
    scanf("%d", &c.ID);
    printf("\nEntre com o nome do cliente:");
    gets(c.Nome);
    gets(c.Nome);
    printf("\nEntre com o CPF do cliente:");
    gets(c.CPF);
    printf("\nEntre com o endereço do cliente:");
    gets(c.Endereco);
    printf("Confira as informações:\n");
    printf("ID: %d , NOME: %s , CPF: %s , ENDEREÇO: %s \n", c.ID, c.Nome, c.CPF, c.Endereco);
    printf("As informações estão corretas? [S/N]:");
    scanf("%c", &a);
    scanf("%c", &a);

    FILE *fp;
    fp = fopen("Clientes.txt", "a+b");
    if (!fp)
    {
        printf("Erro na abertura do arquivo\n");
        exit(0);
    }

    else
    {
        fwrite(&c, sizeof(struct CadastroCliente), 1, fp);
    }
    fclose(fp);
    return a = 'n';
}
//area de cadastro de perfil
char CadastroPerfil()
{
    system("clear");

    struct Perfil per;

    printf("Entre com o usuário para login:\n");
    gets(per.Usuario);
    gets(per.Usuario);
    printf("Entre com a senha para o login:\n");
    gets(per.Senha);
    printf("Confira as informações:\n");
    printf("USUÁRIO: %s , SENHA: %s\n", per.Usuario, per.Senha);
    printf("As informações estão corretas? [S/N]:");
    scanf("%c", &a);
    scanf("%c", &a);

    FILE *fp;
    fp = fopen("Perfis.txt", "a+b");
    if (!fp)
    {
        printf("Erro na abertura do arquivo\n");
        exit(0);
    }

    else
    {
        fwrite(&per, sizeof(struct Perfil), 1, fp);
    }
    fclose(fp);
    return a = 'n';
}
//area para pagamento de funcionario
char CadastroPagamento()
{

    a = 'n';
    struct Gasto pag;
    while (a == 'n')
    {
        printf("Digite o nome do funcionário a ser pago:\n");
        gets(pag.Nome);
        gets(pag.Nome);
        printf("Digite o valor:\n");
        scanf("%lf", &pag.Valor);
        struct CadastroFuncionario func;
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
                printf("Nenhum funcionario cadastrado\n");
            }
            else
            {
                rewind(gast);

                while (!feof(gast))
                {

                    fread(&func, sizeof(struct CadastroFuncionario), 1, gast);
                }
                if (strcmp(pag.Nome, func.Nome) == 0)
                {
                    FILE *gastos;

                    gastos = fopen("Gastos.txt", "a+b");
                    if (!gastos)
                    {
                        printf("Erro na abertura do arquivo\n");
                        exit(0);
                    }

                    else
                    {

                        fwrite(&pag, sizeof(struct Gasto), 1, gastos);
                    }
                    printf("PAGAMENTO REALIZADO\n");
                    fclose(gastos);
                    return a = 'a';
                }
                else
                {
                    printf("Funcionário nao localizado ou nao cadastrado\n");
                    return a = 'n';
                }
            }
        }
        fclose(gast);
    }
}
//area para adicionar unidades em produtos ja cadastrados
char CadastroQuantidade()
{
    system("clear");
    struct Produto prd;
    struct Gasto gAst;
    a = 'n';
    struct Produto produ;

    printf("Digite o nome do produto:\n");
    gets(prd.Nome);
    gets(prd.Nome);
    printf("Digite a quantidade:\n");
    scanf("%d", &prd.Unidades);
    printf("Digite o preço de compra:\n");
    scanf("%lf", &prd.PrecoCompra);

    strcpy(gAst.Nome, prd.Nome);
    gAst.Valor = prd.PrecoCompra * prd.Unidades;
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
        int sizeStream = ftell(gast);
        if (ftell(gast) == 0)
        {
            printf("NENHUM PRODUTO CADASTRADO\n");
        }
        else
        {
            fseek(gast, 0, SEEK_SET);
            int finded = 0;
            int curr = 0;
            while (curr <= sizeStream)
            {
                curr = ftell(gast);

                if (curr + sizeof(struct Produto) > sizeStream)
                    break;

                fread(&produ, sizeof(struct Produto), 1, gast);

                if (strcmp(prd.Nome, produ.Nome) == 0)
                {

                    produ.Unidades = produ.Unidades + prd.Unidades;

                    FILE *gastos;

                    gastos = fopen("Gastos.txt", "a+b");

                    if (!gastos)
                    {
                        printf("Erro na abertura do arquivo\n");
                        exit(0);
                    }

                    else
                    {

                        fwrite(&gAst, sizeof(struct Gasto), 1, gastos);
                    }

                    printf("PRODUTO ALTERADO\n");
                    fflush(gastos);
                    fclose(gastos);
                    finded = 1;
                }

                fseek(gast, curr, SEEK_SET);
                fwrite(&produ, sizeof(struct Produto), 1, gast);
                curr += sizeof(struct Produto);
                fseek(gast, curr, SEEK_SET);
            }

            fflush(gast);
            fclose(gast);

            if (finded != 1)
            {
                printf("PRODUTO NÃO LOCALIZADO OU NÃO REGISTRADO\n");
            }

            return 'n';
        }
    }
}
//area para cadastrar um novo produto
char CadastroProduto()
{
    system("clear");
    struct Produto p;
    struct Gasto g;

    do
    {

        printf("Entre com o ID para o produto:");
        scanf("%d", &p.ID);
        printf("\nEntre com o nome do produto:");
        gets(p.Nome);
        gets(p.Nome);
        printf("\nEntre com a quantidade:");
        scanf("%d", &p.Unidades);
        printf("\nEntre com o preço de compra:");
        scanf("%lf", &p.PrecoCompra);
        strcpy(g.Nome, p.Nome);
        g.Valor = p.Unidades * p.PrecoCompra;
        printf("Confira as informações:\n");
        printf("ID: %d , NOME: %s  , UNIDADES: %d , VALOR: %.2lf \n", p.ID, p.Nome, p.Unidades, p.PrecoCompra);
        printf("As informações estão corretas? [S/N]:");
        scanf("%c", &a);
        scanf("%c", &a);

    } while (a == 'n' || a == 'N');

    FILE *fp, *gastos;
    fp = fopen("Produtos.txt", "a+b");
    gastos = fopen("Gastos.txt", "a+b");
    if (!fp && !gastos)
    {
        printf("Erro na abertura do arquivo\n");
        exit(0);
    }

    else
    {
        fwrite(&p, sizeof(struct Produto), 1, fp);
        fwrite(&g, sizeof(struct Gasto), 1, gastos);
    }
    fclose(fp);
    fclose(gastos);
}
//funçao de vendas
char Vendas()
{
    system("clear");
    struct Produto prd;
    struct Venda gAst;
    a = 'n';
    struct Produto produ;

    printf("Digite o nome do produto:\n");
    gets(prd.Nome);
    gets(prd.Nome);
    printf("Digite a quantidade:\n");
    scanf("%d", &prd.Unidades);
    printf("Digite o preço de venda:\n");
    scanf("%lf", &prd.PrecoCompra);

    strcpy(gAst.Nome, prd.Nome);
    gAst.preco = prd.PrecoCompra;
    gAst.unidades = prd.Unidades;
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
        int sizeStream = ftell(gast);
        if (ftell(gast) == 0)
        {
            printf("NENHUM PRODUTO CADASTRADO\n");
        }
        else
        {
            fseek(gast, 0, SEEK_SET);
            int finded = 0;
            int curr = 0;
            while (curr <= sizeStream)
            {
                curr = ftell(gast);

                if (curr + sizeof(struct Produto) > sizeStream)
                    break;

                fread(&produ, sizeof(struct Produto), 1, gast);

                // gast = fopen("Produtos.txt", "w+b");
                if (strcmp(prd.Nome, produ.Nome) == 0)
                {
                    if (prd.Unidades > produ.Unidades)
                    {
                        printf("QUANTIDADE INSUFICIENTE EM ESTOQUE!\n ");
                        return 'n';
                    }
                    produ.Unidades = produ.Unidades - prd.Unidades;

                    FILE *gastos;

                    gastos = fopen("Vendas.txt", "a+b");

                    if (!gastos)
                    {
                        printf("Erro na abertura do arquivo\n");
                        exit(0);
                    }

                    else
                    {

                        fwrite(&gAst, sizeof(struct Venda), 1, gastos);
                    }

                    printf("VENDA REALIZADA\n");
                    fflush(gastos);
                    fclose(gastos);
                    finded = 1;
                }

                fseek(gast, curr, SEEK_SET);
                fwrite(&produ, sizeof(struct Produto), 1, gast);
                curr += sizeof(struct Produto);
                fseek(gast, curr, SEEK_SET);
            }

            fflush(gast);
            fclose(gast);

            if (finded != 1)
            {
                printf("PRODUTO NÃO LOCALIZADO OU NÃO REGISTRADO\n");
            }
        }
    }
    char ve;
    printf("Mais uma venda? [s/n]\n");
    scanf("%c", &ve);
    scanf("%c", &ve);
    if (ve == 's' || ve == 'S')
    {
        while (ve == 's' || ve == 'S')
        {
            printf("Digite o nome do produto:\n");
            gets(prd.Nome);
            gets(prd.Nome);
            printf("Digite a quantidade:\n");
            scanf("%d", &prd.Unidades);
            printf("Digite o preço de venda:\n");
            scanf("%lf", &prd.PrecoCompra);

            strcpy(gAst.Nome, prd.Nome);
            gAst.preco = prd.PrecoCompra;
            gAst.unidades = prd.Unidades;
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
                int sizeStream = ftell(gast);
                if (ftell(gast) == 0)
                {
                    printf("NENHUM PRODUTO CADASTRADO\n");
                }
                else
                {
                    fseek(gast, 0, SEEK_SET);
                    int finded = 0;
                    int curr = 0;
                    while (curr <= sizeStream)
                    {
                        curr = ftell(gast);

                        if (curr + sizeof(struct Produto) > sizeStream)
                            break;

                        fread(&produ, sizeof(struct Produto), 1, gast);

                        // gast = fopen("Produtos.txt", "w+b");
                        if (strcmp(prd.Nome, produ.Nome) == 0)
                        {
                            if (prd.Unidades > produ.Unidades)
                            {
                                printf("QUANTIDADE INSUFICIENTE EM ESTOQUE!\n ");
                                return 'n';
                            }
                            produ.Unidades = produ.Unidades - prd.Unidades;

                            FILE *gastos;

                            gastos = fopen("Vendas.txt", "a+b");

                            if (!gastos)
                            {
                                printf("Erro na abertura do arquivo\n");
                                exit(0);
                            }

                            else
                            {

                                fwrite(&gAst, sizeof(struct Venda), 1, gastos);
                            }

                            printf("VENDA REALIZADA\n");
                            fflush(gastos);
                            fclose(gastos);
                            finded = 1;
                        }

                        fseek(gast, curr, SEEK_SET);
                        fwrite(&produ, sizeof(struct Produto), 1, gast);
                        curr += sizeof(struct Produto);
                        fseek(gast, curr, SEEK_SET);
                    }

                    fflush(gast);
                    fclose(gast);

                    if (finded != 1)
                    {
                        printf("PRODUTO NÃO LOCALIZADO OU NÃO REGISTRADO\n");
                    }
                }
            }

            printf("Mais uma venda? [s/n]\n");
            scanf("%c", &ve);
            scanf("%c", &ve);
        }
    }
    else
    {
        return 'n';
    }
}
//funçao de login
int LogIn()
{
    int ck = 0;
    char usu[20];
    char sen[20];
    while (ck != 2)
    {

        printf("Digite o usuário:");
        gets(usu);
        printf("\nDigite a senha:");
        gets(sen);
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
            int logado = 0;
            while (!feof(gast))
            {
                fread(&pf, sizeof(struct Perfil), 1, gast);

                if (strcmp(usu, pf.Usuario) == 0 && strcmp(sen, pf.Senha) == 0)
                {
                    printf("LOGADO\n");
                    printf("INICIALIZANDO");

                    printf(".");
                    sleep(2);
                    printf(".");
                    sleep(2);
                    printf(".\n");
                    printf("COMUNICANDO SE COM OS SATÉLITES...\n");
                    sleep(2);
                    printf("BEM VINDO AO PADAREX\n");
                    sleep(1);

                    logado = 1;
                    ck = 2;
                    break;
                }

            }

            if(logado == 0)
            {
                printf("USUÁRIO OU SENHA INVALIDO\n");
            }
        }

        fclose(gast);
    }
    sleep(2);
    system("clear");
    return 2;
}
//funçao manual
char Manual(){
    system("clear");

    printf("DICAS:\n");
    printf("1- Ao cadastrar um novo usuario guarde a senha pois\n");
    printf("ela ficará invisível ao listar usuários\n\n");
    printf("2- Confira as informações antes de concluir algum cadastro\n\n");
    printf("3- IDs servem de auxílio para localização de objetos\n");
    printf("atente-se para não cadastrar IDs repetidos\n\n");
    printf("4- Use uma sequência numérica nos IDs\n\n");
    printf("5- Cadastre o produto antes da venda, se a venda já foi efetuada\n");
    printf("adicione unidades negativas para abater do estoque\n\n");
    printf("6- Não acesse o arquivo que contêm os dados do sistema pois\n");
    printf("qualquer edição irá danificar as informações contidas ali\n\n");
    printf("\n\nAperte qualquer tecla para voltar\n");
    getchar();
    getchar();
    system("clear");
}
