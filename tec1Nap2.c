#include <stdio.h>
#include <locale.h>

// Função que dá um printf em 60 "=" para ajudar na divisão de sessões de textos
void mostraLinha(){
	printf("============================================================\n");
}

// Função pra pedir as escolhas do usuário no decorrer do RPG
// Parâmetro "numeroEscolhas" define até que número será aceito como opção válida 
int verificaEscolha(int numeroEscolhas){
	int escolha;
	
	// Solicita uma escolha ao usuário
	printf("Sua escolha: ");
	scanf("%d", &escolha);
	
	// Verifica se é uma opção válida
	// Caso seja inválida pede novamente até uma opção válida ser inserida
	// Caso seja válida retorna a escolha
	if((escolha < 1) || (escolha > numeroEscolhas)){
		do{
			printf("Opção inválida! Tente Novamente. \n");
			printf("Sua escolha: ");
			scanf("%d", &escolha);
		}while((escolha < 1) || (escolha > numeroEscolhas));
	}
	return escolha;
}

// Função para exibir uma contextualização inicial e um tutorial simples
void tutorial(){
	
	printf("Olá desbravador espacial!\n");
	printf("A Terra foi devastada pela ganância dos mais poderosos, não há mais água para todos \n");
	printf("o clima é hostil por toda a superfície do planeta, desastres naturais são recorrentes \n");
	printf("e uma onda de fome generalizada se espalhou pelas nações, os últimos cientistas se juntaram \n");
	printf("para contruir a 'Arca', uma nave que levará os ultimos seres humanos \n");
	printf("congelados em capsulas criogênicas para um novo planeta onde a raça humana \n");
	printf("irá se reerguer e impedir sua extinção.\n");
	printf("\n");
	printf("Você será uma IA batizada de EVA que controlará essa nave e tomará todas as decisões \n");
	printf("que vão decidir o futuro da humanidade, use sondas para explorar planetas pois \n");
	printf("uma vez que você pousar em um planeta não será possível retornar. \n");
	printf("Preste atenção no seu combustível, porque se ele chegar a zero...\n");
	printf("bem... não deixe ele chegar a zero.\n");
	printf("\n");
	printf("Te desejo boa sorte em sua aventura!\n");
} 


void main(){
	int escolha;
	// Número Inicial de Sondas e combustível
	int sondas = 5;
	int combustivel = 100;
	
	// Variáveis onde 0 = False e 1 = True
	int possuiCombustivel = 1;
	int possuiSondas = 1;
	
	// Função que permite o uso de acentos e "ç" nos textos
	setlocale(LC_ALL,"");
	
	//Exibe o tutorial e um texto base para iniciar o jogo
	tutorial();
	mostraLinha();
	
	//Início do RPG
	
}
