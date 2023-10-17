#include <stdio.h>
#include <locale.h>
#include <windows.h>
#include <time.h>
#include <stdlib.h>

// Declaração das funções
void mostraLinha();
int verificaEscolha(int numeroMinimo, int numeroMaximo);
void exibeStatusAtual();
void atualizaStatusCS();
void vocePerdeu();
void gastaCombustivel();
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
// Parâmetro "numeroMinimo" define menor número aceito como opção válida 
// Parâmetro "numeroMaximo" define maior número aceito como opção válida
int verificaEscolha(int numeroMinimo, int numeroMaximo){
	int escolha;
	
	// Solicita uma escolha ao usuário
	printf("Sua escolha: ");
	scanf("%d", &escolha);
	
	// Verifica se é uma opção válida
	// Caso seja inválida pede novamente até uma opção válida ser inserida
	// Caso seja válida retorna a escolha
	if((escolha < numeroMinimo) || (escolha > numeroMaximo)){
		do{
			printf("Opção inválida! Tente Novamente. \n");
			printf("Sua escolha: ");
			scanf("%d", &escolha);
		}while((escolha < numeroMinimo) || (escolha > numeroMaximo));
	}
	mostraLinha();
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
		mostraLinha();
			printf("SEU COMBUSTÍVEL ACABOU! \n");
			mostraLinha();
			vocePerdeu();
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
	jogar = verificaEscolha(0, 1);
	sondas = 5;
	combustivel = 100;
	
}

// Função para gastar combustível
void gastaCombustivel(int gasto){
	combustivel -= gasto;
	atualizaStatusCS();
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
		printf("1) Pousar nesse Planeta. \n");
		printf("2) Enviar uma sonda para obter mais informações. \n");
		printf("3) Seguir a viagem e procurar por outro planeta. \n");
		escolha = verificaEscolha(1, 3);

		if(escolha == 2){
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
	}while(escolha == 2);
	if(escolha == 0){
		printf("A nave pousa no planeta e descongela os tripulantes. \n");
		printf("No momento em que eles saem para fora da nave todos começam \n");
		printf("a se sentirem asfixiados ou intoxicados e nenhum sobrevive. \n");
		vocePerdeu();
	}
	else if(escolha == 3){
		gastaCombustivel(10);
	}
}

// Função para exibir evento dos asteróides
void evento02(){
	//Texto base
	printf("Após se afastar do último planeta, os radares da espaçonave detectam algo \n");
	printf("estranho pela rota atual, possivelmente asteróides, porém, pode ser um alarme falso \n");
	printf("que atrasará a viagem e consumirá mais recursos em caso de mudança de rota. \n");
	
	// Interação com o jogador
	exibeStatusAtual();
	printf("Tome uma decisão urgente! Você sente quantidade massiva de processamento sendo \n");
	printf("utilizado para esse dilema. \n");
	printf("1) Ignorar o aviso e seguir em frente. \n");
	printf("2) Utilizar outro caminho e gastar +10%% de combustível. \n");
	escolha = verificaEscolha(1, 2);
	
	if(escolha == 1){
		printf("Você ignora os aviso e segue em frente... \n");
		printf("PÉSSIMA IDEIA, os asteróides eram reais!!! \n");
		
		// Inicializo o randomizador com o horário atual do sistema como seed
		srand(time(NULL));
		
		// Variável que decide se sobrevive aos asteróides 50% de chance de sobreviver
		int consegue = rand() % 2;
		
		// Não sobrevive
		if(consegue == 0){
			printf("Você tenta desviar dos milhares de detritos pelo caminho mas é acertado \n");
			printf("em cheio por um deles, logo em seguida a nave entra em colapso e explode \n");
			vocePerdeu();
		}
		// Sobrevive
		else if(consegue == 1){
			printf("Vários corpos rochosos surgem em sua frente, com seu alto poder \n");
			printf("de processamento você realiza todos os calculos de desvios instântaneamente, \n");
			printf("alguns deles causam arranhões na parte externa, mas nenhum resulta \n");
			printf("em danos críticos aos seus sistemas e a nave sai quase que ilesa \n");
			printf("desse perigo. Ufa, foi por pouco! \n");
		}
	}
	else if(escolha == 2){
		printf("Após seu processador chegar no limite de temperatura a conclusão foi \n");
		printf("que o melhor a se fazer é dar a volta em segurança e respeitar \n");
		printf("os avisos. ");
		gastaCombustivel(10);
	}
	
}

//Evento03: próximo planeta 
void evento03(){
  printf("Viajando pelo espaço profundo em direção a um destino desconhecido.\n");
  printf("Você detecta um planeta gigante, coberto por nuvens brancas e envolto por um azul profundo e cintilante.\n");
  
  do{
    exibeStatusAtual();
    printf("Você analisa a situação e começa a calcular qual a melhor decisão: \n");
    printf("1) Pousar nesse Planeta. \n");
    printf("2) Enviar uma sonda para obter mais informações. \n");
    printf("3) Seguir a viagem e procurar por outro planeta. \n");
    escolha = verificaEscolha(1, 3);
    if(escolha == 2){
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
	}while (escolha == 2);
  
	if(escolha == 1){
    	printf("A nave pousa no planeta e descongela os tripulantes. \n");
    	printf("No momento do pouso um onda gigantesca atinge a nave e todos os tripulantes morrem \n");
    	vocePerdeu();
    }
    else if(escolha == 3){
		gastaCombustivel(10);
	}
    
}
