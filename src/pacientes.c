#include <stdio.h>
#include <stdlib.h>

#include "estruturas.h"
#include "menus.h"
#include "medicos.h"
#include "pacientes.h"
#include "agenda.h"

int indicePaciente=0;
struct Paciente pacientes[SIZE_PACIENTES];


void Ler_nome_Paciente(struct Paciente *pacientes){
    LimparBuffer();
    PularLinha();
    printf("\t\t\tInsira o nome do paciente: ");
    fgets(pacientes->nome_paciente.nome,SIZE_NOME,stdin);
}

void Ler_codigo_Paciente(struct Paciente *pacientes){
    PularLinha();
    printf("\t\t\tInsira o codigo do paciente: ");
    scanf("%d",&pacientes[indicePaciente].codigo_paciente.codigo);
}

void Ler_dataNascimento_Paciente(struct Paciente *pacientes){
    PularLinha();
    printf("\t\t\tInsira a data de nascimento separada\n\t\t\t por espaco (d/m/a): ");
    scanf("%d %d %d",&pacientes[indicePaciente].dataNascimento_paciente.dia,&pacientes[indicePaciente].dataNascimento_paciente.mes,&pacientes[indicePaciente].dataNascimento_paciente.ano);
}

void Ler_registroImperial_Paciente(struct Paciente *pacientes){
    PularLinha();
    printf("\t\t\tInsira o registro imperial do paciente: ");
    scanf("%d",&pacientes[indicePaciente].registroImperial_paciente.codigo);
}

void Ler_enderecoNumero_Paciente(struct Paciente *pacientes){
    PularLinha();
    printf("\t\t\tInsira o endereco do paciente");
    PularLinha();
    PularLinha();
    printf("\t\t\tNumero: ");
    scanf("%d",&pacientes[indicePaciente].endereco_paciente.numero);
}

void Ler_enderecoRua_Paciente(struct Paciente *pacientes){
    LimparBuffer();
    PularLinha();
    printf("\t\t\tRua: ");
    fgets(pacientes->endereco_paciente.rua,SIZE_ENDERECO,stdin);
}

void Ler_enderecoBairro_Paciente(struct Paciente *pacientes){
    LimparBuffer();
    PularLinha();
    printf("\t\t\tBairro: ");
    fgets(pacientes->endereco_paciente.bairro,SIZE_ENDERECO,stdin);
}

void Ler_enderecoCidade_Paciente(struct Paciente *pacientes){
    LimparBuffer();
    PularLinha();
    printf("\t\t\tCidade: ");
    fgets(pacientes->endereco_paciente.cidade,SIZE_ENDERECO,stdin);
}

void Ler_contatoTelefone_Paciente(struct Paciente *pacientes){
    PularLinha();
    printf("\t\t\tInsira o numero de telefone do paciente: ");
    scanf("%d",&pacientes[indicePaciente].contato_paciente.telefone);
}

void Ler_contatoEmail_Paciente(struct Paciente *pacientes){
    LimparBuffer();
    PularLinha();
    printf("\t\t\tInsira o email do paciente: ");
    fgets(pacientes->contato_paciente.email,SIZE_EMAIL,stdin);
}

void Cadastrar_Paciente(){
    int Op;

    LimparTela();
    Exibir_Cabecalho();
    printf("\n\t\t\tCADASTRAR PACIENTES\n");
    Exibir_Linha();

    if (indicePaciente < SIZE_PACIENTES){

        Ler_nome_Paciente(&pacientes[indicePaciente]);
        Ler_codigo_Paciente(&pacientes);
        Ler_dataNascimento_Paciente(&pacientes);
        Ler_registroImperial_Paciente(&pacientes);

        Ler_enderecoNumero_Paciente(&pacientes);
        Ler_enderecoRua_Paciente(&pacientes[indicePaciente]);
        Ler_enderecoBairro_Paciente(&pacientes[indicePaciente]);
        Ler_enderecoCidade_Paciente(&pacientes[indicePaciente]);

        Ler_contatoTelefone_Paciente(&pacientes);
        Ler_contatoEmail_Paciente(&pacientes[indicePaciente]);

//        printf("\nNome: %s ",pacientes[indicePaciente].nome_paciente.nome);
//        printf("\nCodigo: %d ",pacientes[indicePaciente].codigo_paciente.codigo);
//        printf("\nData de nascimento: %d/%d/%d",pacientes[indicePaciente].dataNascimento_paciente.dia,pacientes[indicePaciente].dataNascimento_paciente.mes,pacientes[indicePaciente].dataNascimento_paciente.ano);
//        printf("\nRI: %d ",pacientes[indicePaciente].registroImperial_paciente.codigo);
//        printf("Numero: %d ",pacientes[indicePaciente].endereco_paciente.numero);
//        printf("Rua: %s ",pacientes[indicePaciente].endereco_paciente.rua);
//        printf("Bairro: %s ",pacientes[indicePaciente].endereco_paciente.bairro);
//        printf("Cidade: %s ",pacientes[indicePaciente].endereco_paciente.cidade);
//        printf("Telefone: %d ",pacientes[indicePaciente].contato_paciente.telefone);
//        printf("Email: %s ",pacientes[indicePaciente].contato_paciente.email);

        indicePaciente++;
        Exibir_Mensagem_CadastroSucesso();
    } else {
        Exibir_Mensagem_ErroCadastrarMedicos();
    }

    PularLinha();
    Exibir_Linha();
    Exibir_BotaoVoltar();
    printf("\t\t\t\t\t");
    scanf("%d",&Op);

    if (Op == 0){
        SelecionarOp_MenuGerenciarPacientes();
    } else {
        Exibir_Mensagem_ErroOpcaoInvalida();
    }
}

void Alterar_Paciente(){
    int Op, alterarPaciente, Op_alteracao, Op_alteracaoSubmenu, i, f;

// Variaveis que irão armazenar as informações até serem enviadas ao vetor da estrutura
    char Novo_Nome[SIZE_NOME], Novo_Email[SIZE_EMAIL];
    int Novo_Dia_Nascimento, Novo_Mes_Nascimento, Novo_Ano_Nascimento;
    int Novo_Registro_Imperial, Novo_Endereco_Numero, Novo_Telefone;
    char Novo_Endereco_Rua[SIZE_ENDERECO], Novo_Endereco_Bairro[SIZE_ENDERECO], Novo_Endereco_Cidade[SIZE_ENDERECO];

    LimparTela();
    Exibir_Cabecalho();
    printf("\n\t\t\tALTERAR DADOS DE PACIENTES\n");
    Exibir_Linha();

    printf("\n\t\t\tInsira o RI(Registro Imperial) do paciente\n\t\t\t que deseja alterar\n");
    printf("\n\t\t\t\t\t");
    scanf("%d",&alterarPaciente);

    if (alterarPaciente != NULL){
        for(i=0;i<SIZE_PACIENTES;i++){
            if (alterarPaciente == pacientes[i].registroImperial_paciente.codigo){

                Exibir_SubmenuAlterarInformacoes();

                Exibir_SelecionarOpcao(&Op_alteracao);

                switch(Op_alteracao){
                    case 1:
                        LimparBuffer();
                        printf("\n\t\t\tInsira o novo nome do paciente: ");
                        fgets(Novo_Nome,SIZE_NOME,stdin);

                        for (f=0;f<SIZE_NOME;f++){
                            pacientes[i].nome_paciente.nome[f] = NULL;
                        }

                        strcpy(pacientes[i].nome_paciente.nome,Novo_Nome);

                        break;
                    case 2:
                        Exibir_SubmenuAlterarInformacoes_dataNascimento();

                        Exibir_SelecionarOpcao(&Op_alteracaoSubmenu);

                        switch(Op_alteracaoSubmenu){
                            case 1:
                                printf("\n\t\t\tInsira o novo dia: ");
                                scanf("%d",&Novo_Dia_Nascimento);

                                pacientes[i].dataNascimento_paciente.dia = Novo_Dia_Nascimento;
                                break;
                            case 2:
                                printf("\n\t\t\tInsira o novo mes: ");
                                scanf("%d",&Novo_Mes_Nascimento);
                                pacientes[i].dataNascimento_paciente.mes = Novo_Mes_Nascimento;
                                break;
                            case 3:
                                printf("\n\t\t\tInsira o novo ano: ");
                                scanf("%d",&Novo_Ano_Nascimento);
                                pacientes[i].dataNascimento_paciente.ano = Novo_Ano_Nascimento;
                                break;
                        }
                        break;
                    case 3:
                        printf("\n\t\t\tInsira o novo RI(Registro Imperial): ");
                        scanf("%d",&Novo_Registro_Imperial);

                        pacientes[i].registroImperial_paciente.codigo = Novo_Registro_Imperial;
                        break;
                    case 4:

                        Exibir_SubmenuAlterarInformacoes_endereco();

                        Exibir_SelecionarOpcao(&Op_alteracaoSubmenu);

                        switch(Op_alteracaoSubmenu){
                            case 1:
                                printf("\n\t\t\tInsira o novo numero: ");
                                scanf("%d",&Novo_Endereco_Numero);

                                pacientes[i].endereco_paciente.numero = Novo_Endereco_Numero;
                                break;
                            case 2:
                                LimparBuffer();
                                printf("\n\t\t\tInsira o novo nome da rua: ");
                                fgets(Novo_Endereco_Rua,SIZE_ENDERECO,stdin);

                                strcpy(pacientes[i].endereco_paciente.rua,Novo_Endereco_Rua);
                                break;
                            case 3:
                                LimparBuffer();
                                printf("\n\t\t\tInsira o novo nome do bairro: ");
                                fgets(Novo_Endereco_Bairro,SIZE_ENDERECO,stdin);

                                strcpy(pacientes[i].endereco_paciente.bairro,Novo_Endereco_Bairro);
                                break;
                            case 4:
                                LimparBuffer();
                                printf("\n\t\t\tInsira o novo nome da cidade: ");
                                fgets(Novo_Endereco_Cidade,SIZE_ENDERECO,stdin);

                                strcpy(pacientes[i].endereco_paciente.cidade,Novo_Endereco_Cidade);
                                break;
                            }
                        break;
                    case 5:

                        Exibir_SubmenuAlterarInformacoes_contato();

                        Exibir_SelecionarOpcao(&Op_alteracaoSubmenu);

                        switch (Op_alteracaoSubmenu){
                            case 1:
                                printf("\n\t\t\tInsira o novo numero de telefone: ");
                                scanf("%d",&Novo_Telefone);

                                pacientes[i].contato_paciente.telefone = Novo_Telefone;
                                break;
                            case 2:
                                LimparBuffer();

                                printf("\n\t\t\tInsira o novo email: ");
                                fgets(Novo_Email,SIZE_EMAIL,stdin);

                                strcpy(pacientes[i].contato_paciente.email,Novo_Email);
                                break;
                        }
                        break;
                }
            }
        }
    }

    PularLinha();
    Exibir_Linha();
    Exibir_BotaoVoltar();
    printf("\t\t\t\t\t");
    scanf("%d",&Op);

    if (Op == 0){
        SelecionarOp_MenuGerenciarPacientes();
    } else {
        Exibir_Mensagem_ErroOpcaoInvalida();
    }
}

void Remover_Paciente(){
    int Op, removerPaciente,i,f;

    LimparTela();
    Exibir_Cabecalho();
    printf("\n\t\t\tREMOVER PACIENTES\n");
    Exibir_Linha();

    printf("\n\t\t\tInsira o RI(Registro Imperial) do paciente que deseja remover\n");
    printf("\t\t\t\t\t");
    scanf("%d",&removerPaciente);

    if (removerPaciente != NULL){
        for(i=0;i<SIZE_PACIENTES;i++){
            if (removerPaciente == pacientes[i].registroImperial_paciente.codigo){

                for (f=0;f<SIZE_NOME;f++){
                    pacientes[i].nome_paciente.nome[f] = NULL;
                }

                for(f=0;f<SIZE_ENDERECO;f++){
                    pacientes[i].endereco_paciente.rua[f] = NULL;
                    pacientes[i].endereco_paciente.bairro[f] = NULL;
                    pacientes[i].endereco_paciente.cidade[f] = NULL;
                }

                for(f=0;f<SIZE_EMAIL;f++){
                    pacientes[i].contato_paciente.email[f] = NULL;
                }

                pacientes[i].codigo_paciente.codigo = NULL;
                pacientes[i].dataNascimento_paciente.dia = NULL;
                pacientes[i].dataNascimento_paciente.mes = NULL;
                pacientes[i].dataNascimento_paciente.ano = NULL;
                pacientes[i].registroImperial_paciente.codigo = NULL;
                pacientes[i].endereco_paciente.numero = NULL;
                pacientes[i].contato_paciente.telefone = NULL;

                printf("\n\t\t\tPaciente excluido com sucesso!");
            }
        }
    }

    PularLinha();
    Exibir_Linha();
    Exibir_BotaoVoltar();
    printf("\t\t\t\t\t");
    scanf("%d",&Op);

    if (Op == 0){
        SelecionarOp_MenuGerenciarPacientes();
    } else {
        Exibir_Mensagem_ErroOpcaoInvalida();
    }
}

void Pesquisar_Paciente(){ // Função responsável pela pesquisa de pacientes
    int Op, i, pesquisarPaciente;

    LimparTela();
    Exibir_Cabecalho();
    printf("\n\t\t\tPESQUISAR PACIENTES\n");
    Exibir_Linha();

    printf("\n\t\t\tInsira o RI(Registro Imperial) do paciente\n");
    printf("\t\t\t\t\t");
    scanf("%d",&pesquisarPaciente);

    for(i=0;i<SIZE_PACIENTES;i++){ // Percorrer o vetor de pacientes
        if(pacientes[i].registroImperial_paciente.codigo == pesquisarPaciente){ // Conferir se o Registro Imperial é igual ao conteúdo da variável pesquisarPaciente
            LimparTela();
            Exibir_Cabecalho();
            printf("\n\t\t\tPESQUISAR PACIENTES\n");
            Exibir_Linha();

            PularLinha();
            PularLinha();
            printf("\n\t\t\tINFORMACOES BASICAS");
            PularLinha();
            Exibir_Linha();
            printf("\n\t\t\tNome: %s ",pacientes[i].nome_paciente.nome);
            printf("\n\t\t\tCodigo: %d ",pacientes[i].codigo_paciente.codigo);
            printf("\n\t\t\tData de nascimento: %d/%d/%d",pacientes[i].dataNascimento_paciente.dia,pacientes[i].dataNascimento_paciente.mes,pacientes[i].dataNascimento_paciente.ano);
            printf("\n\t\t\tRI: %d ",pacientes[i].registroImperial_paciente.codigo);

            PularLinha();
            PularLinha();
            printf("\n\t\t\tENDERECO");
            PularLinha();
            Exibir_Linha();
            printf("\n\t\t\tNumero: %d ",pacientes[i].endereco_paciente.numero);
            printf("\n\t\t\tRua: %s ",pacientes[i].endereco_paciente.rua);
            printf("\n\t\t\tBairro: %s ",pacientes[i].endereco_paciente.bairro);
            printf("\n\t\t\tCidade: %s ",pacientes[i].endereco_paciente.cidade);

            PularLinha();
            PularLinha();
            printf("\n\t\t\tINFORMACOES PARA CONTATO");
            PularLinha();
            Exibir_Linha();
            printf("\n\t\t\tTelefone: %d ",pacientes[i].contato_paciente.telefone);
            printf("\n\t\t\tEmail: %s ",pacientes[i].contato_paciente.email);
        }
    }

    PularLinha();
    Exibir_Linha();
    Exibir_BotaoVoltar();
    printf("\t\t\t\t\t");
    scanf("%d",&Op);

    if (Op == 0){
        SelecionarOp_MenuGerenciarPacientes();
    } else {
        Exibir_Mensagem_ErroOpcaoInvalida();
    }
}

void Consultar_PacientesCadastrados(){
    int Op, i;

    LimparTela();
    Exibir_Cabecalho();
    printf("\n\t\t\tPACIENTES CADASTRADOS NO SISTEMA\n");
    Exibir_Linha();

    for(i=0;i<SIZE_PACIENTES;i++){ // Percorrer o vetor de pacientes
        if((pacientes[i].codigo_paciente.codigo != NULL) && (pacientes[i].nome_paciente.nome != NULL)){ // Conferir se o vetor na posição i não se encontra vazio
            printf("\n\t\t\tCodigo\t\tPaciente\n");
            printf("\t\t\t%d \t\t%s\n",pacientes[i].codigo_paciente.codigo,pacientes[i].nome_paciente.nome);
        }
    }

    PularLinha();
    Exibir_Linha();
    Exibir_BotaoVoltar();
    printf("\t\t\t\t\t");
    scanf("%d",&Op);

    if (Op == 0){
        SelecionarOp_MenuGerenciarPacientes();
    } else {
        Exibir_Mensagem_ErroOpcaoInvalida();
    }
}
