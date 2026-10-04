#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#include "funcoes.h"

#define MAX_PERGUNTAS 5

char perguntas[MAX_PERGUNTAS][200];
char alternativas[MAX_PERGUNTAS][4][100];
char respostas[MAX_PERGUNTAS];
int pergunta = 0;
int totalPerguntas = 0;
int perguntasRespondidas = 0;
int acertos = 0;
int totalAcertos = 0;
int erros = 0;
int totalErros = 0;

void lixo(){
	char lixo;
	while ((lixo = getchar()) != '\n' && lixo != EOF);
}

void cadastrarPergunta(void){
	//char lixo;
	lixo();
	if (pergunta == 0 ) {
		pergunta = 1;
	} else if (pergunta == 5){
		int recomecar;
		printf("\nLimite de perguntas alcancado, deseja comecar do zero? 1-Sim 2-Nao.");
		scanf("%d", &recomecar);
		lixo();
		while (recomecar < 1 || recomecar > 2){
			printf("Opcao invalida! Digite 1 para recomecar ou 2 para sair.\n");
			scanf("%d", &recomecar);
		}
		if (recomecar == 1){
			pergunta = 1;
		} else if (recomecar == 2){
			return;
		}
	}
	
	printf("\n===Cadastro de Perguntas===\n");
	
	for (pergunta; pergunta < 6; pergunta++){
		int continua;
		printf("Digite a %da pergunta:\n", pergunta);
		fgets(perguntas[pergunta - 1], sizeof(perguntas[pergunta - 1]), stdin);
		printf("Digite as alternativas de A a D:\n");
		printf("A) ");
		fgets(alternativas[pergunta - 1][0], sizeof(alternativas[pergunta - 1][0]), stdin);
		printf("B) ");
		fgets(alternativas[pergunta - 1][1], sizeof(alternativas[pergunta - 1][1]), stdin);
		printf("C) ");
		fgets(alternativas[pergunta - 1][2], sizeof(alternativas[pergunta - 1][2]), stdin);
		printf("D) ");
		fgets(alternativas[pergunta - 1][3], sizeof(alternativas[pergunta - 1][3]), stdin);
		printf("Qual a resposta certa, informe apenas a letra (A, B, C, D):\n");
		scanf(" %c", &respostas[pergunta -1]);
		lixo();
		//while ((lixo = getchar()) != '\n' && lixo != EOF);
		respostas[pergunta - 1] = toupper(respostas[pergunta - 1]);
		while (respostas[pergunta - 1] != 'A' && respostas[pergunta - 1] != 'B' && 
               respostas[pergunta - 1] != 'C' && respostas[pergunta - 1] != 'D'){
			  	printf("Opcao invalida!\nEscolha outra opcao de A a D: ");
			  	scanf(" %c", &respostas[pergunta - 1]);
			  	respostas[pergunta - 1] = toupper(respostas[pergunta - 1]);
			  }
		totalPerguntas++;
		
		if (pergunta < 5){
			printf("Deseja cadastrar mais perguntas? 1-Sim 2-Nao\n");
			scanf("%d", &continua);
			lixo();
			while (continua < 1 || continua > 2){
			printf("Numero invalido! Digite 1 para continuar ou 2 para sair.\n");
			scanf("%d", &continua);
			}
			if (continua == 2){
			break;
			}
		}
		
	}
	if (pergunta == 6){
		pergunta = 5;
	}
}

void listarPerguntas(void){
	int i;
	printf("\n===Listando as perguntas e alternativas===");
	for (i = 0; i < pergunta; i++) {
		printf("\nPergunta %d/%d\n", i+1, pergunta);
		printf("%s", &perguntas[i]);
		printf("A) %s", alternativas[i][0]);
		printf("B) %s", alternativas[i][1]);
		printf("C) %s", alternativas[i][2]);
		printf("D) %s\n", alternativas[i][3]);
	}
}
void jogar(void){
	int i;
	char resposta;
	printf("\n===Jogar===\n");
	for (i = 0; i < pergunta; i++){
		printf("%s", perguntas[i]);
		printf("A) %s", alternativas[i][0]);
		printf("B) %s", alternativas[i][1]);
		printf("C) %s", alternativas[i][2]);
		printf("D) %s", alternativas[i][3]);
		printf("Resposta: ");
		scanf(" %c", &resposta);
		lixo();
		//while ((lixo = getchar()) != '\n' && lixo != EOF);
		resposta = toupper(resposta);
		while (resposta != 'A' && resposta != 'B' && 
            resposta != 'C' && resposta != 'D'){
			printf("Opcao invalida!\nEscolha outra opcao de A a D: ");
			scanf(" %c", &resposta);
			resposta = toupper(resposta);
		}
		if (resposta == respostas[i]){
			printf("Correto!\n\n");
			acertos++;
			totalAcertos++;
		} else {
			printf("Errado!\n\n");
			erros++;
			totalErros++;
		}
		perguntasRespondidas++;
		
	}
	printf("Placar final: %d/%d acertos (%d%%)\n\n", acertos, pergunta, (100 / pergunta) * acertos);
	acertos = 0;
	erros = 0;
}
void exibirEstatisticas(void){
	printf("\n===Estatisticas===\n");
	if (totalPerguntas == 0 || perguntasRespondidas == 0){
		printf("O jogo ainda não começou.\n");
	}else if(totalPerguntas > 0 && perguntasRespondidas > 0) {
		printf("Total de perguntas cadastradas: %d\n", totalPerguntas);
		printf("Total de perguntas respondidas: %d\n", perguntasRespondidas);
		printf("Total de acertos: %d\n", totalAcertos);
		printf("Total de erros: %d\n", totalErros);
		printf("Percentual de acertos: %d%%\n", (100 / perguntasRespondidas) * totalAcertos);
	}
	
}

int capturaOpcao(){
	int o;
	printf("Escolha uma opcao: ");
	scanf("%d", &o);
	while (o < 0 || o > 4){
		printf("Por favor, escolha uma opcao entre 0 e 4: ");
		scanf("%d", &o);
	}
	return o;
}

int imprimeMenu(){
	int opcao;
	printf("=====Quiz=====\n");
	printf("1. Jogar\n");
	printf("2. Cadastrar pergunta\n");
	printf("3. Listar perguntas\n");
	printf("4. Estatisticas\n");
	printf("0. Sair\n");
	opcao = capturaOpcao();
	return opcao;
}