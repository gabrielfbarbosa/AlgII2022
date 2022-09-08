#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    int codigo;
    int senha;
    char nome[30];
    int idade;
    char estado[3];
} reg_dadoCidadao;

void menuInicial()
{
    printf("\t----------------------------");
    printf("\n\t     *** MENU PRINCIPAL ***");
    printf("\n\t 1 CIDADÃO");
    printf("\n\t 2 GERAR SENHA");
    printf("\n\t 3 ATENDIMENTO AO CIDADÃO");
    printf("\n\t S SAIR");
    printf("\n\t----------------------------\n");

    printf("* Escolha uma das opções acima: ");
}


void menuCidadao()
{
    printf("\t----------------------------");
    printf("\n\t    *** MENU CIDADÃO *** ");
    printf("\n\t 1 CADASTRAR");
    printf("\n\t 2 PESQUISAR POR CÓDIGO");
    printf("\n\t 3 ATUALIZAR CADASTRO");
    printf("\n\t 4 EXCLUIR CADASTRO");
    printf("\n\t 0 VOLTAR");
    printf("\n\t----------------------------\n");

    printf("* Escolha uma das opções acima: ");
}


int erroSelecaoCidadao(int opcao)
{
    while (opcao < 0 || opcao > 4)
    {
        printf("\n\t[ ERRO: OPÇÃO INVALIDA!! ]\n\n");
        printf("*Tente novamente: ");
        scanf("%d", &opcao);
    }
    return opcao;
}


void gerarSenha(reg_dadoCidadao dadosCidadao[], int senhaNv, int position)
{
    int i;

    for (i = senhaNv - 1; i < senhaNv; i++)
    {
        dadosCidadao[position].senha = i;
    }
}

/*
char erroSelecaoInicial(char *opcao)
{
    while (strcmp(*opcao, "1") && strcmp(*opcao, "2") && strcmp(*opcao, "3") && strcmp(*opcao, "S"))
    {
        printf("\n\t[ ERRO: OPÇÃO INVALIDA!! ]\n\n");
        printf("*Tente novamente: ");
        scanf("%s", *opcao);
    }
    return *opcao;
}
*/


void enfileiraIdoso(int *i, int *f, reg_dadoCidadao Fila[100], int codigo, int senha, char nome[30], int idade, char estado[3])
{
    if (*f != *i || *f == -1) {
        if (*f == -1) {
            *i = 0;
            *f = 0;
        }
        Fila[*f].codigo = codigo;
        Fila[*f].senha = senha;
        strcpy(Fila[*f].nome, nome);
        Fila[*f].idade = idade;
        strcpy(Fila[*f].estado, estado);

        *f = (*f + 1) % 100;
    }
    else
    {
        printf("\n------------------------------\nFila cheia!\n------------------------------\n");
    }    
}


int desenfileira_Idoso(int *i, int *f, reg_dadoCidadao F[100])
{
    int r = F->senha ;
    if (*i != -1) {
        r = F[*i].senha;
        *i = (*i + 1) % 100;
        if (*i == *f) {
            *i = -1;
            *f = -1;
        }
    }
    else
        printf("Fila vazia!\n");
    return r;
}


int main(void)
{
    int opcaoCidadao, codigoPesquisa, qtdCidadao, find, i, j, exist, opcaoAtualizar;
    int codigoGerarSenha, position, opcaoAtendimento, senhaIdoso, senhaNovo, qtdIdoso, qtdNovo, controleSenha;
    int  iFila, fFila ; /*numMesa*/
     reg_dadoCidadao dadosCidadao[500], filaIdoso[500], filaNovo[500];
    char opcaoInicial[1], servidoPublico[30];
    int operacoesCidadao(void);
    int erroSelecaoCidadao(int);
    /*char erroSelecaoInicial(char);*/

    qtdCidadao = 0; /*Controle de Quantidade de cadastros*/
    senhaIdoso = 0; /*Para gerar senha a partir de 0, 1, 2...conforme posição na fila*/
    senhaNovo = 0; /*Para gerar senha a partir de 0, 1, 2...conforme posição na fila*/
    qtdIdoso = 0; /*quantidade de senhas para maiores de 65*/ 
    qtdNovo = 0; /*quantidade de senhas para menores de 65*/
    controleSenha = 0; /* Contola quantidade de senha de no maximo 100 por dia*/
    iFila = -1; /* Indica inicio da Fila*/
    fFila = -1; /* Indica final da Fila*/

    menuInicial();
    scanf("%s", opcaoInicial);

    /*Caso valor errado das opções*/
    while (strcmp(opcaoInicial, "1") && strcmp(opcaoInicial, "2") && strcmp(opcaoInicial, "3") && strcmp(opcaoInicial, "S"))
    {
        printf("\n\t[ ERRO: OPÇÃO INVALIDA!! ]\n\n");
        printf("*Tente novamente: ");
        scanf("%s", opcaoInicial);
    }

    while (strcmp(opcaoInicial, "1") || strcmp(opcaoInicial, "2") || strcmp(opcaoInicial, "3") || strcmp(opcaoInicial, "S"))
    {
        /* ---------------------- OPÇÃO 1 CIDADÃO -------------------------------------------- */
        if (!strcmp(opcaoInicial, "1"))
        {
            printf("\n******************************************************************\n");
            printf(" -> OPÇÃO 1: CIDADÃO\n");

            menuCidadao();
            scanf("%d", &opcaoCidadao);
            opcaoCidadao = erroSelecaoCidadao(opcaoCidadao);

            while (opcaoCidadao != 0)
            {

                /*OPÇÃO 1 CADASTRAR --------------------------------------------------------------------------------------------------------------------------*/
                if (opcaoCidadao == 1)
                {
                    qtdCidadao++;

                    printf("\n******************************************************************\n");
                    printf(" -> OPÇÃO 1: CADASTRAR.\n PREENCHA OS DADOS DO CIDADÃO:");

                    if (qtdCidadao <= 500)
                    {
                        exist = 0; /*Para pesquisar codigo e evitar repetir*/
                        for (i = (qtdCidadao - 1); i < qtdCidadao; i++)
                        {
                            printf("\n\t Codigo do Cidadão: ");
                            scanf("%d", &dadosCidadao[i].codigo);

                            if (qtdCidadao > 1)
                            { /*Caso seja o primero cadastro, não faz comparação*/
                                for (j = 0; j < qtdCidadao - 1; j++)
                                { /*Passa por todos para ver se ja existe*/

                                    if (dadosCidadao[j].codigo == dadosCidadao[i].codigo)
                                    {
                                        exist = 1;
                                    }
                                }
                            }

                            if (exist == 0)
                            {
                                printf("\t Nome do Cidadão: ");
                                scanf("%s", dadosCidadao[i].nome);

                                printf("\t Idade do Cidadão: ");
                                scanf("%d", &dadosCidadao[i].idade);

                                printf("\t Estado onde reside o Cidadão: ");
                                scanf("%s", dadosCidadao[i].estado);

                                dadosCidadao[i].senha = -1;

                                printf("\n[ CIDADÃO CADASTRADO COM SUCESSO!! ]\n");
                            }
                            else
                            {
                                printf("\n\t[ ERRO: Codigo do cidadão já cadastrado ]\n");
                                qtdCidadao--; /*Elimina o campo do codigo igual*/
                            }
                        }
                    }
                    else
                    {
                        printf("\n[ ERRO: QUANTIDADE MÁXIMA DE USUÁRIOS CADASTRADA. ]\n");
                    }
                    printf("\n******************************************************************\n");
                }

                /*OPÇÃO 2 PESQUISAR POR CÓDIGO --------------------------------------------------------------------------------------*/
                if (opcaoCidadao == 2)
                {
                    printf("\n******************************************************************\n");
                    printf(" -> OPÇÃO 2: PESQUISAR POR CÓDIGO\n");
                    printf("* Insira o codigo do cidadão que deseja pesquisar: ");
                    scanf("%d", &codigoPesquisa);
                    find = 0; /*Inciando variavel considerando não encontrar nada*/

                    for (i = 0; i < qtdCidadao; i++)
                    {
                        if (codigoPesquisa == dadosCidadao[i].codigo)
                        {
                            printf("\n\t----------------------------\n");
                            printf("\t  *** Dados do Cidadão *** \n");
                            printf("\t Codigo: ");
                            printf("%d\n", dadosCidadao[i].codigo);
                            printf("\t Nome: ");
                            printf("%s\n", dadosCidadao[i].nome);
                            printf("\t Idade: ");
                            printf("%d\n", dadosCidadao[i].idade);
                            printf("\t Estado: ");
                            printf("%s", dadosCidadao[i].estado);
                            printf("\n\t----------------------------\n");
                            i = qtdCidadao;
                            find = 1; /*adicionando 1 caso encontrar*/
                        }
                    }

                    if (find != 1)
                    {
                        printf("\n\t----------------------------\n");
                        printf("\t Código não cadastrado.");
                        printf("\n\t----------------------------\n");
                    }

                    printf("\n******************************************************************\n");
                }

                /*OPÇÃO 3 ATUALIZAR CADASTRO--------------------------------------------------------------------------------------*/
                if (opcaoCidadao == 3)
                {
                    printf("\n******************************************************************\n");

                    printf(" -> OPÇÃO 3: ATUALIZAR CADASTRO\n");
                    printf("* Insira o codigo do cidadão que deseja atualizar: ");
                    scanf("%d", &codigoPesquisa);
                    find = 0; /*Inciando variavel considerando não encontrar nada*/

                    for (i = 0; i < qtdCidadao; i++)
                    {
                        if (codigoPesquisa == dadosCidadao[i].codigo)
                        {
                            printf("\n\t----------------------------\n");
                            printf("\t  *** O QUE DEJA ATUALIZAR ? *** \n");
                            printf("\t 1 Nome");
                            printf("\n\t 2 Idade");
                            printf("\n\t 3 Estado");
                            printf("\n\t 4 Todos");
                            printf("\n\t----------------------------\n");
                            printf("* Escolha uma das opções acima: ");
                            scanf("%d", &opcaoAtualizar);

                            if (opcaoAtualizar == 1)
                            {
                                printf("\t Nome do Cidadão: ");
                                scanf("%s", dadosCidadao[i].nome);
                                printf("\n[ NOME DO CIDADÃO ATUALIZADO COM SUCESSO!! ]\n");
                            }

                            if (opcaoAtualizar == 2)
                            {
                                printf("\t Idade do Cidadão: ");
                                scanf("%d", &dadosCidadao[i].idade);
                                printf("\n[ IDADE DO CIDADÃO ATUALIZADO COM SUCESSO!! ]\n");
                            }

                            if (opcaoAtualizar == 3)
                            {
                                printf("\t Estado onde reside o Cidadão: ");
                                scanf("%s", dadosCidadao[i].estado);
                                printf("\n[ ESTADO DO CIDADÃO ATUALIZADO COM SUCESSO!! ]\n");
                            }

                            if (opcaoAtualizar == 4)
                            {
                                printf("\t Nome do Cidadão: ");
                                scanf("%s", dadosCidadao[i].nome);

                                printf("\t Idade do Cidadão: ");
                                scanf("%d", &dadosCidadao[i].idade);

                                printf("\t Estado onde reside o Cidadão: ");
                                scanf("%s", dadosCidadao[i].estado);

                                printf("\n\t[ DADOS DO CIDADÃO ATUALIZADOS COM SUCESSO!! ]\n");
                            }

                            i = qtdCidadao;
                            find = 1; /*adicionando 1 caso encontrar*/
                        }
                    }
                    if (find != 1)
                    {
                        printf("\n\t----------------------------\n");
                        printf("\t Código não cadastrado.");
                        printf("\n\t----------------------------\n");
                    }
                    printf("\n******************************************************************\n");
                }

                /*OPÇÃO 4 EXCLUIR CADASTRO--------------------------------------------------------------------------------------*/
                if (opcaoCidadao == 4)
                {
                    printf("\n******************************************************************\n");

                    printf(" -> OPÇÃO 4: EXCLUIR CADASTRO\n");
                    printf("* Insira o codigo do cidadão que deseja excluir: ");
                    scanf("%d", &codigoPesquisa);
                    find = 0; /*Inciando variavel considerando não encontrar nada*/

                    for (i = 0; i < qtdCidadao; i++)
                    {
                        if (codigoPesquisa == dadosCidadao[i].codigo)
                        { /*Encontra aposição que esta a escolha*/

                            for (i = i; i < qtdCidadao; i++)
                            { /*exclui trazendo os cadastros da frente para a posição vaga*/
                                dadosCidadao[i].codigo = dadosCidadao[i + 1].codigo;

                                strcpy(dadosCidadao[i].nome, dadosCidadao[i + 1].nome);

                                dadosCidadao[i].idade = dadosCidadao[i + 1].idade;

                                strcpy(dadosCidadao[i].estado, dadosCidadao[i + 1].estado);
                            }
                            qtdCidadao--;
                            find = 1; /*adicionando 1 caso encontrar*/
                        }
                    }

                    if (find == 1)
                    {
                        printf("\n\t[ DADOS DO CIDADÃO EXCLUIDOS COM SUCESSO!! ]\n");
                    }

                    if (find != 1)
                    {
                        printf("\n\t----------------------------\n");
                        printf("\t Código não cadastrado.");
                        printf("\n\t----------------------------\n");
                    }
                    printf("\n******************************************************************\n");
                }

                menuCidadao();
                scanf("%d", &opcaoCidadao);
                opcaoCidadao = erroSelecaoCidadao(opcaoCidadao);
            }

            printf("\n******************************************************************\n");
        }

        /* ---------------------- GERAR SENHA -------------------------------------------- */
        if (!strcmp(opcaoInicial, "2"))
        {
            printf("\n******************************************************************\n");
            controleSenha++;

            printf("* OPÇÃO 2: GERAR SENHA \n");

            if ((controleSenha) <= 100) /*Maxima diaria de atendimentos*/
            {

                printf("* Insira o codigo do cidadão que deseja uma senha: ");
                scanf("%d", &codigoGerarSenha);

                for (i = 0; i < qtdCidadao; i++) /*Procura se tem codigo cadastrado*/
                {
                    if (codigoGerarSenha == dadosCidadao[i].codigo)
                    {             /*Encontra aposição que esta a escolha*/
                        find = 1; /*Recebe 1 caso encontrar*/
                        position = i;
                    }
                }

                if (find != 1) /*Caso não encontrar o codigo*/
                {
                    printf("\n\t----------------------------\n");
                    printf("\t Código não cadastrado.");
                    printf("\n\t----------------------------\n");
                }

                if (find == 1) /* Caso encontrar o codigo */
                {
                    /* Opções de atendimnto */
                    printf("\n\t----------------------------\n"); 
                    printf("\t  *** SELECIONE O TIPO DE ATENDIMENTO *** \n");
                    printf("\t 1 DOCUMENTOS");
                    printf("\n\t 2 TRANSPORTES");
                    printf("\n\t 3 MORADIA.");
                    printf("\n\t----------------------------\n");
                    printf("* Escolha uma das opções acima: ");
                    scanf("%d", &opcaoAtendimento);

                    /*Caso entrar com valores diferentes do disponivel*/
                    while (opcaoAtendimento != 1 && opcaoAtendimento != 2 && opcaoAtendimento != 3)
                    {
                        printf("\n\t[ ERRO: OPÇÃO INVALIDA!! ]\n\n");
                        printf("* Tente novamente: ");
                        scanf("%d", &opcaoAtendimento);
                    }

                    switch (opcaoAtendimento)
                    {
                    case 1:
                        printf("\n\t OPÇÃO 1: DOCUMENTOS\n");
                        break;
                    case 2:
                        printf("\n\t OPÇÃO 1: TRANSPORTES\n");
                        break;
                    case 3:
                        printf("\n\t OPÇÃO 1: MORADIA\n");
                        break;
                    }

                    if (dadosCidadao[position].idade >= 65) /* Caso Maior de 65*/
                    {
                        senhaIdoso++; /*Controle de quantidade de senhas*/
                        qtdIdoso++;  /* Tamanho do vetor */
                        gerarSenha(dadosCidadao, senhaIdoso, position);

                        enfileiraIdoso(&iFila, &fFila, filaIdoso,
                            dadosCidadao[position].codigo,
                            dadosCidadao[position].senha,
                            dadosCidadao[position].nome,
                            dadosCidadao[position].idade,
                            dadosCidadao[position].estado
                        );

                        /*
                        filaIdoso[senhaIdoso - 1].codigo = dadosCidadao[position].codigo;

                        filaIdoso[senhaIdoso - 1].senha = dadosCidadao[position].senha;

                        strcpy(filaIdoso[senhaIdoso - 1].nome, dadosCidadao[position].nome);

                        filaIdoso[senhaIdoso - 1].idade = dadosCidadao[position].idade;

                        strcpy(filaIdoso[senhaIdoso - 1].estado, dadosCidadao[position].estado);
                        */
                        
                    }
                    else
                    {
                        senhaNovo++;
                        qtdNovo++;

                        gerarSenha(dadosCidadao, senhaNovo, position);

                        filaNovo[senhaNovo - 1].codigo = dadosCidadao[position].codigo;

                        filaNovo[senhaNovo - 1].senha = dadosCidadao[position].senha;

                        strcpy(filaNovo[senhaNovo - 1].nome, dadosCidadao[position].nome);

                        filaNovo[senhaNovo - 1].idade = dadosCidadao[position].idade;

                        strcpy(filaNovo[senhaNovo - 1].estado, dadosCidadao[position].estado);
                    }

                    find = 0;
                }
            }
            else /*Caso atingitr maxima diaria*/
            {
                printf("\n[ ERRO: QUANTIDADE MÁXIMA DE ATENDIMENTOS DIÁRIA ATINGIDA. ]\n ** Volte amanhã!\n");
            }

            printf("\n ----*** Qtd Idoso: %d *** ----\n", qtdIdoso);

            if (qtdIdoso > 0)
            {
                printf("\n\t----------------------------\n");
                printf("\t  *** FILA IDOSOS *** \n\n");

                for (i = 0; i < qtdIdoso; i++)
                {
                    printf("\t Codigo: ");
                    printf("%d\n", filaIdoso[i].codigo);
                    printf("\t Senha: ");
                    printf("%d\n", filaIdoso[i].senha);
                    printf("\t Nome: ");
                    printf("%s\n", filaIdoso[i].nome);
                    printf("\t Idade: ");
                    printf("%d\n", filaIdoso[i].idade);
                    printf("\t Estado: ");
                    printf("%s", filaIdoso[i].estado);
                    printf("\n\t----------------------------\n");
                }
            }

            if (qtdNovo > 0)
            {
                printf("\n\t----------------------------\n");
                printf("\t  *** FILA NOVOS *** \n\n");

                for (i = 0; i < qtdNovo; i++)
                {
                    printf("\t Codigo: ");
                    printf("%d\n", filaNovo[i].codigo);
                    printf("\t Senha: ");
                    printf("%d\n", filaNovo[i].senha);
                    printf("\t Nome: ");
                    printf("%s\n", filaNovo[i].nome);
                    printf("\t Idade: ");
                    printf("%d\n", filaNovo[i].idade);
                    printf("\t Estado: ");
                    printf("%s", filaNovo[i].estado);
                    printf("\n\t----------------------------\n");
                }
            }

            if (qtdCidadao > 0)
            {
                printf("\n\t----------------------------\n");
                printf("\t  *** TODOS Dados do Cidadão *** \n\n");

                for (i = 0; i < qtdCidadao; i++)
                {
                    printf("\t Codigo: ");
                    printf("%d\n", dadosCidadao[i].codigo);
                    printf("\t Senha: ");
                    printf("%d\n", dadosCidadao[i].senha);
                    printf("\t Nome: ");
                    printf("%s\n", dadosCidadao[i].nome);
                    printf("\t Idade: ");
                    printf("%d\n", dadosCidadao[i].idade);
                    printf("\t Estado: ");
                    printf("%s", dadosCidadao[i].estado);
                    printf("\n\t----------------------------\n");
                }
            }

            printf("\n******************************************************************\n");
        }

        /* ---------------------- ATENDIMENTO AO CIDADÃO --------------------------------- */
        if (!strcmp(opcaoInicial, "3"))
        {
            printf("\n******************************************************************\n");
            printf("* OPÇÃO 3: ATENDIMENTO AO CIDADÃO");

            /*
            printf("Insira o nome do Servidor público: ");
            scanf("%s", servidoPublico);

            printf("Insira o numero da mesa: ");
            scanf("%s", numMesa);
            */

           printf("\n******************************************************************\n");
        }

        /* ----------------------  SAIR --------------------------------------------------- */
        if (!strcmp(opcaoInicial, "S"))
        {
            printf("\n******************************************************************\n");

            printf("* OPÇÃO S: SAIR\n");

            if (controleSenha > 0)
            {
                controleSenha--;

                aux = desenfileira_Idoso(iFila, fFila, filaIdoso)


                printf("------------------\n Chamando as filas \n------------------");

                printf("\n******************************************************************\n");

        
            } else {
                printf("------------------\n Filas vazias \n------------------");
                printf("\n******************************************************************\n");
                return 0;
            }

        }

        menuInicial();
        scanf("%s", opcaoInicial);
        while (strcmp(opcaoInicial, "1") && strcmp(opcaoInicial, "2") && strcmp(opcaoInicial, "3") && strcmp(opcaoInicial, "S"))
        {
            printf("\n\t[ ERRO: OPÇÃO INVALIDA!! ]\n\n");
            printf("*Tente novamente: ");
            scanf("%s", opcaoInicial);
        }
    }

    return 0;
}
