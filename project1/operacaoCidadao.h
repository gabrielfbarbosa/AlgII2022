int operacoesCidadao() {
    int opcaoCidadao, codigoPesquisa, qtdCidadao, find, i, j, exist, opcaoAtualizar;
    reg_dadoCidadao dadosCidadao[500];
    void menuCidadao(void);
    int erroSelecaoCidadao(int);

    qtdCidadao = 0;
    menuCidadao();
    scanf("%d", &opcaoCidadao);

    while (opcaoCidadao != 0)  {
        opcaoCidadao = erroSelecaoCidadao(opcaoCidadao);

        /*OPÇÃO 1 CADASTRAR --------------------------------------------------------------------------------------------------------------------------*/
        if (opcaoCidadao == 1){
            qtdCidadao++;

            printf("\n******************************************************************\n");
            printf(" -> OPÇÃO 1: CADASTRAR.\n PREENCHA OS DADOS DO CIDADÃO:");

            if (qtdCidadao <= 500) {
                exist = 0; /*Para pesquisar codigo e evitar repetir*/
                for (i = (qtdCidadao - 1); i < qtdCidadao; i++)  {
                    printf("\n\t Codigo do Cidadão: ");
                    scanf("%d", &dadosCidadao[i].codigo);

                    if (qtdCidadao > 1)  { /*Caso seja o primero cadastro, não faz comparação*/
                        for (j = 0; j < qtdCidadao - 1; j++)    { /*Passa por todos para ver se ja existe*/
                            
                            if (dadosCidadao[j].codigo == dadosCidadao[i].codigo) {
                                exist = 1;
                            }
                        }
                    }

                    if (exist == 0)  {
                        printf("\t Nome do Cidadão: ");
                        scanf("%s", dadosCidadao[i].nome);

                        printf("\t Idade do Cidadão: ");
                        scanf("%d", &dadosCidadao[i].idade);

                        printf("\t Estado onde reside o Cidadão: ");
                        scanf("%s", dadosCidadao[i].estado);

                        printf("\n[ CIDADÃO CADASTRADO COM SUCESSO!! ]\n");
                    } else {
                        printf("\n\t[ ERRO: Codigo do cidadão já cadastrado ]\n");
                        qtdCidadao--; /*Elimina o campo do codigo igual*/
                    }
                }
            } else {
                printf("\n[ ERRO: Quantidade maxima de usuarios cadasstrada. ]\n");
            }
            printf("\n******************************************************************\n");
        }

        /*OPÇÃO 2 PESQUISAR POR CÓDIGO --------------------------------------------------------------------------------------*/
        if (opcaoCidadao == 2) {
            printf("\n******************************************************************\n");
            printf(" -> OPÇÃO 2: PESQUISAR POR CÓDIGO\n");
            printf("* Insira o codigo do cidadão que deseja pesquisar: ");
            scanf("%d", &codigoPesquisa);
            find = 0; /*Inciando variavel considerando não encontrar nada*/

            for (i = 0; i < qtdCidadao; i++)  {
                if (codigoPesquisa == dadosCidadao[i].codigo)  {
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

            if (find != 1) {
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

            for (i = 0; i < qtdCidadao; i++) {
                if (codigoPesquisa == dadosCidadao[i].codigo) { /*Encontra aposição que esta a escolha*/

                    for (i = i; i < qtdCidadao; i++) { /*exclui trazendo os cadastros da frente para a posição vaga*/
                        dadosCidadao[i].codigo = dadosCidadao[i + 1].codigo;

                        strcpy(dadosCidadao[i].nome, dadosCidadao[i + 1].nome);

                        dadosCidadao[i].idade = dadosCidadao[i + 1].idade;

                        strcpy(dadosCidadao[i].estado, dadosCidadao[i + 1].estado);
                    }
                    qtdCidadao--;
                    find = 1; /*adicionando 1 caso encontrar*/
                }
            }

            if (find == 1) {
                printf("\n\t[ DADOS DO CIDADÃO EXCLUIDOS COM SUCESSO!! ]\n");
            }

            if (find != 1) {
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
    return qtdCidadao;
}