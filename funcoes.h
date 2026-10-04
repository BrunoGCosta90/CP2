#ifndef FUNCOES_H
#define FUNCOES_H
#define MAX_PERGUNTAS 5

extern char perguntas[MAX_PERGUNTAS][200];
extern char alternativas[MAX_PERGUNTAS][4][100];
extern char respostas[MAX_PERGUNTAS];
extern int pergunta;
extern int totalPerguntas;
extern int acertos;
extern int erros;

void lixo();
void cadastrarPergunta(void);
void listarPerguntas(void);
void jogar(void);
void exibirEstatisticas(void);
int capturaOpcao();
int imprimeMenu();

#endif