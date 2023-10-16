#include <stdio.h>
#include <locale.h>

// Declaração das funções
void mostraLinha();
int verificaEscolha(int numeroEscolhas);
void exibeStatusAtual();
void atualizaStatusCS();
void vocePerdeu();
void tutorial();
void evento01();
void evento02();
void evento03();

// Variáveis Globais
int escolha;
	
// Número Inicial de sondas e combustível
int sondas = 5;
int combustivel = 100;
	
// Variáveis onde 0 = False e 1 = True
int jogar = 1;
int perdeu = 0;
int possuiCombustivel = 1;
int possuiSondas = 1;

void main(){
	
	// Função que permite o uso de acentos e "ç" nos textos
	setlocale(LC_ALL,"");
	
	//Exibe o tutorial e um texto base para iniciar o jogo
	tutorial();
	mostraLinha();
	
	// Loop do jogo
	while(jogar == 1){
		perdeu = 0;
		//Início do RPG
		evento01();
		if(perdeu == 0){
			evento02();
			if(perdeu == 0){
				evento03();
			}
		}
	}
	printf("FIM");
	
}


//Definição das funções
// Função que dá um printf em 70 "=" para ajudar na divisão de sessões de textos
void mostraLinha(){
	printf("======================================================================\n");
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
	if((escolha < 0) || (escolha > numeroEscolhas)){
		do{
			printf("Opção inválida! Tente Novamente. \n");
			printf("Sua escolha: ");
			scanf("%d", &escolha);
		}while((escolha < 1) || (escolha > numeroEscolhas));
	}
	return escolha;
}

// Função que exibe a barra de combustível e sondas restantes  
void exibeStatusAtual(){
	int c;
	mostraLinha();
	printf("Status Atual: \n");
	// Exibição do combustível em uma "barra"
	printf("Combustível: ");
	for(c = 0; c <= combustivel; c += 5){
		printf("|");
	}
	printf(" %d%% \n", combustivel);
	printf("Sondas: %d \n", sondas);
	printf("\n");
}

// Função para atualizar se ainda há combustível ou sondas disponíveis
void atualizaStatusCS(){
	// Atualiza situação das sondas
	if(sondas > 0){
		possuiSondas = 1;
	}
	else{
		possuiSondas = 0;
	}
	// Atualiza situação do combustível
	if(combustivel > 0){
		possuiCombustivel = 1;
	}
	else{
		possuiCombustivel = 0;
	}
}

// Exibe "Tela de derrota" + opção de jogar novamente
void vocePerdeu(){
	perdeu = 1;
	mostraLinha();
	printf(" ¦¦¦¦¦¦   ¦¦¦¦¦  ¦¦¦    ¦¦¦ ¦¦¦¦¦¦¦      ¦¦¦¦¦¦  ¦¦    ¦¦ ¦¦¦¦¦¦¦ ¦¦¦¦¦¦ \n");
	printf("¦¦       ¦¦   ¦¦ ¦¦¦¦  ¦¦¦¦ ¦¦          ¦¦    ¦¦ ¦¦    ¦¦ ¦¦      ¦¦   ¦¦ \n");
	printf("¦¦   ¦¦¦ ¦¦¦¦¦¦¦ ¦¦ ¦¦¦¦ ¦¦ ¦¦¦¦¦       ¦¦    ¦¦ ¦¦    ¦¦ ¦¦¦¦¦   ¦¦¦¦¦¦ \n");
	printf("¦¦    ¦¦ ¦¦   ¦¦ ¦¦  ¦¦  ¦¦ ¦¦          ¦¦    ¦¦  ¦¦  ¦¦  ¦¦      ¦¦   ¦¦ \n");
	printf(" ¦¦¦¦¦¦  ¦¦   ¦¦ ¦¦      ¦¦ ¦¦¦¦¦¦¦      ¦¦¦¦¦¦    ¦¦¦¦   ¦¦¦¦¦¦¦ ¦¦   ¦¦ \n");
	mostraLinha();
	printf("Deseja jogar novamente? \n");
	printf("Não [0] \n");
	printf("Sim [1] \n");
	jogar = verificaEscolha(1);
	sondas = 5;
	combustivel = 100;
	
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

// Função para exibir o encontro do primeiro planeta
void evento01(){
	// Texto base
	printf("A Arca sai em viagem ao espaço, pouco depois o planeta Terra colapsa devido a \n");
	printf("instabilidades em seu núcleo, enquanto observa a catástrofe você vai se afastando \n");
	printf("cada vez mais do sistema solar até o sol se tornar apenas mais um ponto \n");
	printf("como qualquer outra estrela na imensidão do espaço sideral. \n");
	printf("\n");
	printf("Após um bom tempo de viagem o primeiro candidato a 'lar' surge. \n");
	printf("O planeta vermelho parece ser coberto por uma névoa em toda sua superfície, \n");
	printf("é possível observar ao seu redor anéis de gelo e rochas, assim como uma lua próxima com \n");
	printf("uma cratera massiva, provavelmente os anéis desse planeta são os destroços \n");
	printf("do impacto que acertou seu satélite. \n");
	// Interação com o jogador
	do{
		exibeStatusAtual();
		printf("Você observa o planeta e começa a calcular qual a melhor decisão: \n");
		printf("0) Pousar nesse Planeta. \n");
		printf("1) Enviar uma sonda para obter mais informações. \n");
		printf("2) Seguir a viagem e procurar por outro planeta. \n");
		escolha = verificaEscolha(2);

		if(escolha == 1){
			mostraLinha();
			if(possuiSondas == 1){
				printf("Você envia uma sonda para coletar mais dados acerca do planeta. (-1 sonda) \n");
				sondas -= 1;
				atualizaStatusCS();
				printf("A sonda consegue as seguintes informações: \n");
				printf("-Planeta geologicamente estável. \n");
				printf("-Não há sinais de oxigênio. \n");
				printf("-Superfície com altos índices de toxicidade por enxofre. \n");
				printf("Fim do relatório... \n");
			}
			else{
				printf("Você não tem mais sondas disponíveis! \n");
			}
		}
	}while(escolha == 1);
	if(escolha == 0){
		printf("A nave pousa no planeta e descongela os tripulantes. \n");
		printf("No momento em que eles saem para fora da nave todos começam \n");
		printf("a se sentirem asfixiados ou intoxicados e nenhum sobrevive. \n");
		vocePerdeu();
	}
}

// Função para exibir evento dos asteróides
void evento02(){
	printf("Evento 02 \n");
}

//Evento03: próximo planeta 
void evento03(){
  printf("Viajando pelo espaço profundo em direção a um destino desconhecido.\n");
  printf("Você detecta um planeta gigante, coberto por nuvens brancas e envolto por um azul profundo e cintilante.\n");
  
  do{
    exibeStatusAtual();
    printf("Você analisa a situação e começa a calcular qual a melhor decisão: \n");
    printf("0) Pousar nesse Planeta. \n");
    printf("1) Enviar uma sonda para obter mais informações. \n");
    printf("2) Seguir a viagem e procurar por outro planeta. \n");
    escolha = verificaEscolha(2);
    if(escolha == 1){
	    if(possuiSondas == 1){
	      printf("Você envia uma sonda para coletar mais dados acerca do planeta. (-1 sonda) \n");
	      sondas -= 1;
	      atualizaStatusCS();
	      printf("A sonda obteve as seguintes informações: \n");
	      printf("-O planeta é composto quase que exclusivamente de água. \n");
	      printf("-Pressão atmosférica e temperatura adequadas para a vida humana. \n");
	      printf("Fim do relatório... \n");
	    }
	    else{
	      printf("Você não tem mais sondas disponíveis! \n");
    	}
    }
	}while (escolha == 1);
  
	if(escolha == 0){
    	printf("A nave pousa no planeta e descongela os tripulantes. \n");
    	printf("No momento do pouso um onda gigantesca atinge a nave e todos os tripulantes morrem \n");
    	vocePerdeu();
    }
    
    
}
