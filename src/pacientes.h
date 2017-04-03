#ifndef PACIENTES_H_INCLUDED
#define PACIENTES_H_INCLUDED

void Cadastrar_Paciente();
void Ler_nome_Paciente(struct Paciente *pacientes);
void Ler_codigo_Paciente(struct Paciente *pacientes);
void Ler_dataNascimento_Paciente(struct Paciente *pacientes);
void Ler_registroImperial_Paciente(struct Paciente *pacientes);
void Ler_enderecoNumero_Paciente(struct Paciente *pacientes);
void Ler_enderecoRua_Paciente(struct Paciente *pacientes);
void Ler_enderecoBairro_Paciente(struct Paciente *pacientes);
void Ler_enderecoCidade_Paciente(struct Paciente *pacientes);
void Ler_contatoTelefone_Paciente(struct Paciente *pacientes);
void Ler_contatoEmail_Paciente(struct Paciente *pacientes);

void Alterar_Paciente();
void Remover_Paciente();
void Pesquisar_Paciente();
void Consultar_PacientesCadastrados();

#endif // PACIENTES_H_INCLUDED
