#include <stdio.h>
#include <stdbool.h>
#include "funcoes.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main() {
	
	while (true) {
		int opcao;
		
		opcao = imprimeMenu();
		
		if( opcao == 0){
			printf("Saindo...\n");
			break;
		}
		
		switch (opcao){
		
			case 1:
				jogar(); 
				break;
			case 2:
				cadastrarPergunta();
				break;
			case 3:
				listarPerguntas();
				break;
			case 4:
				exibirEstatisticas();
				break;
			case 0:
			default:
				break;
	}
	}
	
	
	
	return 0;
}