#ifndef ESTRUTURAS_H_INCLUDED
#define ESTRUTURAS_H_INCLUDED

#define SIZE_NOME 30
#define SIZE_ENDERECO 35
#define SIZE_EMAIL 30
#define SIZE_TEXTO 200
#define SIZE_AGENDA_MEDICO_L 4
#define SIZE_AGENDA_MEDICO_C 5
#define SIZE_MEDICOS 5
#define SIZE_PACIENTES 10
#define SIZE_PRONTUARIOS 100

//------------------- DEFINIÇÃO DOS TIPOS DE ESTRUTURA DE DADOS -------------------//
struct Codigo{
    int codigo;
};

struct Nome{
    char nome[SIZE_NOME];
};

struct Texto{
    char texto[SIZE_TEXTO];
};

struct Endereco{
    int numero;
    char rua[SIZE_ENDERECO];
    char bairro[SIZE_ENDERECO];
    char cidade[SIZE_ENDERECO];
};

struct Data{
    int dia;
    int mes;
    int ano;
};

struct Horario{
    int hora;
    int minuto;
};

struct Contato{
    int telefone;
    char email[SIZE_EMAIL];
} ;

struct Agenda{
    int agenda[SIZE_AGENDA_MEDICO_L][SIZE_AGENDA_MEDICO_C];
};

struct DataHorarioConsulta{
    struct Data data_consulta;
    struct Horario horario_consulta;
};

struct Medico{
    char nome_medico[SIZE_NOME];
    int CRM_medico;
    int codigo_medico;
    struct Agenda agenda_medico;
};

struct Paciente{
    struct Codigo codigo_paciente;
    struct Nome nome_paciente;
    struct Data dataNascimento_paciente;
    struct Codigo registroImperial_paciente;
    struct Endereco endereco_paciente;
    struct Contato contato_paciente;
    struct Codigo numero_prontuario;
};

struct Prontuario{
    struct Codigo Codigo_Prontuario;
    struct Codigo Codigo_Medico;
    struct Codigo Codigo_Paciente;
    struct Texto DiagEtrata_Paciente;
};

#endif // ESTRUTURAS_H_INCLUDED
