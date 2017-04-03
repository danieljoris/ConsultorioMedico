#include <stdio.h>
#include <stdlib.h>

#include "estruturas.h"
#include "menus.h"
#include "medicos.h"
#include "pacientes.h"
#include "agenda.h"

//------------------- Funções para exibição de menus, limpeza de buffer e tela -------------------//

void Exibir_Linha(){ // Exibir linha
    printf("\t\t\t============================");
}

void PularLinha(){ // Pular linha
    printf("\n");
}

void Exibir_BotaoVoltar(){ // Exibir texto de voltar
    printf("\n\n\t\t\t\tDigite 0 para voltar\n");
}

void Exibir_Cabecalho(){ // Exibir cabeçalho do programa
    Exibir_Linha();
    printf("\n\t\t\tSistema de Consultorio Medico\n");
    Exibir_Linha();
    PularLinha();
    PularLinha();
    PularLinha();
}

void LimparTela(){ // Limpeza da tela
    system("clear");
}

void Exibir_SelecionarOpcao(int *Opcao){ // Exibir texto para selecionar uma opção no menu
    printf("\n\n\t\t\tSelecione qual o tipo de operacao deseja realizar");
    printf("\n\n\t\t\t\t\t");
    scanf("%d",Opcao);
}

void LimparBuffer(){ // Limpeza do buffer do teclado
    int ch;
    do{
        ch = fgetc(stdin);
    } while(ch != EOF && ch != '\n');
}

void Exibir_Mensagem_ErroCadastrarMedicos(){ // Exibir mensagem de erro ao cadastrar a quantidade máxima de médicos
    printf("\n\t\t\tNao e possivel cadastrar mais medicos!");
}

void Exibir_Mensagem_CadastroSucesso(){ // Exibir mensagem de cadastro realizado com sucesso
    PularLinha();
    Exibir_Linha();
    printf("\n\t\t\tCadastro realizado com sucesso!");
}

void Exibir_Mensagem_ErroOpcaoInvalida(){ // Exibir mensagem de opção inválida
    PularLinha();
    printf("\t\t\tOPCAO INVALIDA! Por favor, selecione uma opcao valida!");
}

void Exibir_MenuConsultarProntuarios(){ // Exibir menu para consultar prontuários
    LimparTela();
    Exibir_Cabecalho();
    printf("\n\t\t\tCONSULTAR PRONTUARIOS\n");
    Exibir_Linha();
    printf("\n\t\t\t1- Ver Prontuarios\n");
    Exibir_Linha();
    Exibir_BotaoVoltar();
}

void Exibir_MenuGerenciarMedicos(){ // Exibir menu para gerenciar médicos
    LimparTela();
    Exibir_Cabecalho();
    printf("\n\t\t\tGERENCIAR MEDICOS\n");
    Exibir_Linha();
    printf("\n\t\t\t1- Adicionar Medicos");
    printf("\n\t\t\t2- Remover Medicos");
    printf("\n\t\t\t3- Consultar Medicos Cadastrados\n");
    Exibir_Linha();
    Exibir_BotaoVoltar();
}

void Exibir_MenuGerenciarPacientes(){ // Exibir menu para gerenciar pacientes
    LimparTela();
    Exibir_Cabecalho();
    printf("\n\t\t\tGERENCIAR PACIENTES\n");
    Exibir_Linha();
    printf("\n\t\t\t1- Cadastrar Pacientes");
    printf("\n\t\t\t2- Alterar Cadastro de Pacientes");
    printf("\n\t\t\t3- Remover Cadastro de Pacientes");
    printf("\n\t\t\t4- Pesquisar Pacientes Cadastrados");
    printf("\n\t\t\t5- Consultar Pacientes Cadastrados\n");
    Exibir_Linha();
    Exibir_BotaoVoltar();
}

void Exibir_MenuConsultarAgendamentoSemanal(){ // Exibir menu para consultar agendamentos semanais
    LimparTela();
    Exibir_Cabecalho();
    printf("\n\t\t\tCONSULTAS AGENDADAS NA SEMANA\n");
    Exibir_Linha();
    printf("\n\t\t\tAQUI CONSULTAS AGENDADAS\n");
    Exibir_Linha();
    Exibir_BotaoVoltar();
}

void Exibir_MenuGerenciarAgendamentos(){ // Exibir menu para gerenciar agendamentos
    LimparTela();
    Exibir_Cabecalho();
    printf("\n\t\t\tGERENCIAR AGENDAMENTOS\n");
    Exibir_Linha();
    printf("\n\t\t\t1- Ver Agendamentos");
    printf("\n\t\t\t2- Adicionar Agendamento");
    printf("\n\t\t\t3- Remover Agendamento\n");
    Exibir_Linha();
    Exibir_BotaoVoltar();
}

void Exibir_MenuPrincipal(){ // Exibir menu principal
    LimparTela();
    Exibir_Cabecalho();
    printf("\n\t\t\t1- Gerenciar Medicos");
    printf("\n\t\t\t2- Gerenciar Pacientes");
    printf("\n\t\t\t3- Gerenciar Agendamentos");
    printf("\n\t\t\t4- Consultar Prontuarios");
    printf("\n\t\t\t5- Ver Consultas Agendadas na Semana");
}

void Exibir_SubmenuAlterarInformacoes (){
    PularLinha();
    printf("\t\t\tQual informacao deseja alterar?");
    printf("\n\t\t\t1- Nome");
    printf("\n\t\t\t2- Data de Nascimento");
    printf("\n\t\t\t3- Registro Imperial");
    printf("\n\t\t\t4- Endereco do Paciente");
    printf("\n\t\t\t5- Informacoes de Contato do Paciente");
}

void Exibir_SubmenuAlterarInformacoes_dataNascimento(){
    PularLinha();
    printf("\t\t\tEscolha qual informacao deseja alterar");
    printf("\n\t\t\t1- Dia");
    printf("\n\t\t\t2- Mes");
    printf("\n\t\t\t3- Ano");
}

void Exibir_SubmenuAlterarInformacoes_endereco(){
    PularLinha();
    printf("\t\t\tEscolha qual informacao deseja alterar");
    printf("\n\t\t\t1- Numero");
    printf("\n\t\t\t2- Rua");
    printf("\n\t\t\t3- Bairro");
    printf("\n\t\t\t4- Cidade");
}

void Exibir_SubmenuAlterarInformacoes_contato(){
    PularLinha();
    printf("\t\t\tEscolha qual informacao deseja alterar");
    printf("\n\t\t\t1- Telefone");
    printf("\n\t\t\t2- Email");
}

//------------------- FUÇÕES PARA SELECIONAR OPÇÕES NO MENU PRINCIPAL -------------------//
void SelecionarOp_MenuPrincipal(){
    int Opcao;

    Exibir_MenuPrincipal();

    Exibir_SelecionarOpcao(&Opcao);

    switch (Opcao){
        case 1:
            SelecionarOp_MenuGerenciarMedicos();
            break;
        case 2:
            SelecionarOp_MenuGerenciarPacientes();
            break;
        case 3:
            SelecionarOp_MenuGerenciarAgendamentos();
            break;
        case 4:
//            funcSelecionarOp_MenuConsultarProntuarios();
            break;
        case 5:
//            funcSelecionarOp_MenuConsultasAgendadasSemana();
            break;
        default:
            SelecionarOp_MenuPrincipal();
            break;
    }
}

//------------------- FUNÇÕES PARA SELECIONAR OPÇÕES NO SUBMENU GERENCIAR MEDICOS -------------------//
void SelecionarOp_MenuGerenciarMedicos(){
    int Opcao;

    Exibir_MenuGerenciarMedicos();

    Exibir_SelecionarOpcao(&Opcao);

    switch (Opcao){
        case 1:
            Cadastrar_Medico();
            break;
        case 2:
            Remover_Medico();
            break;
        case 3:
            Consultar_MedicosCadastrados();
            break;
        case 0:
            SelecionarOp_MenuPrincipal();
            break;
        default:
            SelecionarOp_MenuPrincipal();
            break;
    }
}

//------------------- FUNÇÕES PARA SELECIONAR OPÇÕES NO SUBMENU GERENCIAR PACIENTES -------------------//
void SelecionarOp_MenuGerenciarPacientes(){
    int Opcao;

    Exibir_MenuGerenciarPacientes();

    Exibir_SelecionarOpcao(&Opcao);

    switch (Opcao){
        case 1:
            Cadastrar_Paciente();
            break;
        case 2:
            Alterar_Paciente();
            break;
        case 3:
            Remover_Paciente();
            break;
        case 4:
            Pesquisar_Paciente();
            break;
        case 5:
            Consultar_PacientesCadastrados();
            break;
        case 0:
            SelecionarOp_MenuPrincipal();
            break;
        default:
            SelecionarOp_MenuPrincipal();
            break;
    }
}

//------------------- FUNÇÕES PARA SELECIONAR OPÇÕES NO SUBMENU GERENCIAR AGENDAMENTOS -------------------//
void SelecionarOp_MenuGerenciarAgendamentos(){
    int Opcao;

    Exibir_MenuGerenciarAgendamentos();

    Exibir_SelecionarOpcao(&Opcao);

    switch (Opcao){
        case 1:
            Consultar_Agendamentos();
            break;
        case 2:
            Adicionar_Agendamento();
            break;
        case 3:
            Remover_Agendamento();
            break;
        case 0:
            SelecionarOp_MenuPrincipal();
            break;
        default:
            SelecionarOp_MenuPrincipal();
            break;
    }
}

////------------------- FUNÇÕES PARA SELECIONAR OPÇÕES NO SUBMENU CONSULTAR PRONTUARIOS -------------------//
//void funcSelecionarOp_MenuConsultarProntuarios(){
//    int Opcao;
//
//    funcExibir_MenuConsultarProntuarios();
//
//    funcExibir_SelecionarOpcao(&Opcao);
//
//    switch (Opcao){
//        case 1:
//            printf("TESTE");
//            break;
//        case 0:
////            funcIniciarPrograma();
//            break;
//        default:
////            funcIniciarPrograma();
//            break;
//    }
//}
//
////------------------- FUNÇÕES PARA SELECIONAR OPÇÕES NO SUBMENU CONSULTAS AGENDADAS NA SEMANA -------------------//
//void funcSelecionarOp_MenuConsultasAgendadasSemana(){
//    int Opcao;
//
//    funcExibir_MenuConsultarAgendamentoSemanal();
//
//    funcExibir_SelecionarOpcao(&Opcao);
//
//    switch (Opcao){
//        case 1:
//            printf("TESTE");
//            break;
//        case 0:
////            funcIniciarPrograma();
//            break;
//        default:
////            funcIniciarPrograma();
//            break;
//    }
//}
