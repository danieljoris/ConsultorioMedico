#include <stdio.h>
#include <stdlib.h>

#include "estruturas.h"
#include "menus.h"
#include "medicos.h"
#include "pacientes.h"
#include "agenda.h"


void Consultar_Agendamentos(){
    int Op;

    LimparTela();
    Exibir_Cabecalho();
    printf("\n\t\t\tAGENDAMENTOS REALIZADOS\n");
    Exibir_Linha();

    PularLinha();
    Exibir_Linha();
    Exibir_BotaoVoltar();
    printf("\t\t\t\t\t");
    scanf("%d",&Op);

    if (Op == 0){
        SelecionarOp_MenuGerenciarAgendamentos();
    } else {
        Exibir_Mensagem_ErroOpcaoInvalida();
    }
}

void Adicionar_Agendamento(){
    int Op, ri_Paciente, dia_Agendamento, crm_Medico,horario_Agendamento, i, j,k,u;

    LimparTela();
    Exibir_Cabecalho();
    printf("\n\t\t\tADICIONAR AGENDAMENTOS\n");
    Exibir_Linha();

    PularLinha();
    printf("\t\t\tInsira o RI do paciente: ");
    scanf("%d",&ri_Paciente);

    PularLinha();
    printf("\t\t\tInsira o dia da semana que o paciente deseja agendar: ");
    scanf("%d",&dia_Agendamento);

    PularLinha();
    printf("\t\t\tInsira o horario que o paciente deseja agendar: ");
    scanf("%d",&horario_Agendamento);

    PularLinha();
    printf("\t\t\tInsira o CRM do medico que ira atender o paciente: ");
    scanf("%d",&crm_Medico);

//    for(i=0;i<SIZE_PACIENTES;i++){
//        if (pacientes[i].registroImperial_paciente.codigo == ri_Paciente){
//            for(j=0;j<SIZE_MEDICOS;j++){
//                if(medicos[j].CRM_medico == crm_Medico){
//                    for (k=0,u=0;k<SIZE_AGENDA_MEDICO_L,u<SIZE_AGENDA_MEDICO_C;k++,u++){
//                        if (medicos.agenda_medico.agenda[horario_Agendamento][dia_Agendamento] == NULL){
//                            medicos[j].agenda_medico.agenda[k][u] == ri_Paciente;
//                        }
//                    }
//                }
//            }
//        }
//
//    }

    PularLinha();
    Exibir_Linha();
    Exibir_BotaoVoltar();
    printf("\t\t\t\t\t");
    scanf("%d",&Op);

    if (Op == 0){
        SelecionarOp_MenuGerenciarAgendamentos();
    } else {
        Exibir_Mensagem_ErroOpcaoInvalida();
    }
}

void Remover_Agendamento(){
    int Op;

    LimparTela();
    Exibir_Cabecalho();
    printf("\n\t\t\tREMOVER AGENDAMENTOS\n");
    Exibir_Linha();

    PularLinha();
    Exibir_Linha();
    Exibir_BotaoVoltar();
    printf("\t\t\t\t\t");
    scanf("%d",&Op);

    if (Op == 0){
        SelecionarOp_MenuGerenciarAgendamentos();
    } else {
        Exibir_Mensagem_ErroOpcaoInvalida();
    }
}
