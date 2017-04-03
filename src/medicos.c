#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "estruturas.h"
#include "menus.h"
#include "medicos.h"
#include "pacientes.h"
#include "agenda.h"

int indiceMedico=0;
struct Medico medicos[SIZE_MEDICOS]; // Declaração da estrutura médicos

void Ler_NomeMedico(struct Medico *medicos){ // Ler nome do médico
    PularLinha();
    printf("\t\t\tInsira o nome do medico: ");
    fgets(medicos->nome_medico,SIZE_NOME,stdin);
}

void Ler_CRMMedico(struct Medico *medicos){ // Ler CRM do médico
    PularLinha();
    printf("\t\t\tInsira o CRM do medico: ");
    scanf("%d",&medicos[indiceMedico].CRM_medico);
}

void Ler_CodigoMedico(struct Medico *medicos){ // Ler código do médico
    PularLinha();
    printf("\t\t\tInsira o codigo do medico: ");
    scanf("%d",&medicos[indiceMedico].codigo_medico);
}

void Cadastrar_Medico(){ // Cadastrar médico
    int Op;

    LimparTela();
    Exibir_Cabecalho();
    printf("\n\t\t\tCADASTRAR MEDICOS\n");
    Exibir_Linha();

    if (indiceMedico < SIZE_MEDICOS){ // Conferir se o indice não excede o limite da quantidade de médicos

        LimparBuffer();
        Ler_NomeMedico(&medicos[indiceMedico]);

        Ler_CRMMedico(&medicos);

        Ler_CodigoMedico(&medicos);

        indiceMedico++;

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
        LimparTela();
        SelecionarOp_MenuGerenciarMedicos();
    } else {
        Exibir_Mensagem_ErroOpcaoInvalida();
    }
}

void Remover_Medico(){ // Remover médico
    int i, j, k, f, removerMedico, Op;

    LimparTela();
    Exibir_Cabecalho();
    printf("\n\t\t\tREMOVER MEDICOS\n");
    Exibir_Linha();

    printf("\n\t\t\tCRM\t\tMedico\n");

    for(i=0;i<SIZE_MEDICOS;i++){ // Listar todos os médicos cadastrados
        if((medicos[i].CRM_medico != NULL) && (medicos[i].nome_medico != NULL)){
            printf("\n\t\t\t%d \t\t%s",medicos[i].CRM_medico,medicos[i].nome_medico);
        }
    }

    PularLinha();
    Exibir_Linha();
    PularLinha();

    printf("\n\t\t\tInsira o CRM do medico que deseja remover \n");
    printf("\t\t\t\t\t");
    scanf("%d",&removerMedico);

    if (removerMedico != NULL){ // Conferir se a variável removerMedico não se encontra vazia

        for(i=0;i<SIZE_MEDICOS;i++){ // Percorrer o vetor da estrutura

            if (removerMedico == medicos[i].CRM_medico){ // Conferir se o CRM em questão é igual ao de medicos na posição i

                for (f=0;f<SIZE_NOME;f++){ // Colocar null em todas as posições do vetor de char
                    medicos[i].nome_medico[f] = NULL;
                }

                medicos[i].CRM_medico = NULL;
                medicos[i].codigo_medico = NULL;

                for(j=0;j<SIZE_AGENDA_MEDICO_L;j++){ // Colocar null em toda a agenda do médico
                    for(k=0;k<SIZE_AGENDA_MEDICO_C;k++){

                        medicos[i].agenda_medico.agenda[j][k] = NULL;
                    }
                }

                printf("\n\t\t\tMedico excluido com sucesso!");
            }
        }
    }

    PularLinha();
    Exibir_Linha();
    Exibir_BotaoVoltar();
    printf("\t\t\t\t\t");
    scanf("%d",&Op);

    if (Op == 0){
        LimparTela();
        SelecionarOp_MenuGerenciarMedicos();
    } else {
        Exibir_Mensagem_ErroOpcaoInvalida();
    }
}

void Consultar_MedicosCadastrados(){ // Consultar médicos cadastrados
    int Op,i;

    LimparTela();
    Exibir_Cabecalho();
    printf("\n\t\t\tMEDICOS CADASTRADOS NO SISTEMA\n");
    Exibir_Linha();

    printf("\n\t\t\tCRM\t\t\tMedico\n");

    for(i=0;i<SIZE_MEDICOS;i++){ // Percorrer o vetor de médicos
        if((medicos[i].CRM_medico != NULL) && (medicos[i].nome_medico != NULL)){ // Conferir se o médico em questão existe
            printf("\t\t\t%d \t\t%s\n",medicos[i].CRM_medico,medicos[i].nome_medico);
        }
    }

    PularLinha();
    Exibir_Linha();
    Exibir_BotaoVoltar();
    printf("\t\t\t\t\t");
    scanf("%d",&Op);

    if (Op == 0){
        LimparTela();
        SelecionarOp_MenuGerenciarMedicos();
    } else {
        Exibir_Mensagem_ErroOpcaoInvalida();
    }
}
