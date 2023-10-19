#include <stdio.h>
#include <locale.h>
#include <windows.h>
#include <time.h>
#include <stdlib.h>

// Declaração das funções
// Mecânicas do jogo ou organização do código-fonte
void mostraLinha();
int verificaEscolha(int numeroMinimo, int numeroMaximo);
void exibeStatusAtual();
void atualizaStatusCS();
void vocePerdeu();
void voceGanhou();
void gastaCombustivel();
void navegando();

// Eventos do jogo
void tutorial();
void evento01();
void evento02();
void evento03();
void evento04();
void evento05();
void evento06();
void evento07();
void evento08();
void evento09();
void evento10();
void evento11();
void evento12();
void evento13();
void evento14();
void telaFinal();

// Variáveis Globais
// Recebe as escolhas no decorrer RPG
int escolha;
	
// Número Inicial de sondas e combustível
int sondas = 5;
int combustivel = 100;
	
// Variáveis onde 0 = False e 1 = True
int jogar = 1;
int perdeu = 0;
int ganhou = 0;
int possuiCombustivel = 1;
int possuiSondas = 1;

void main(){
	
	// Função que permite o uso de acentos e "ç" nos textos
	setlocale(LC_ALL,"");
	
	//Exibe o tutorial e um texto base para iniciar o jogo
	tutorial();
	mostraLinha();
	printf("Aperte \"enter\" para começar...");
	getchar();
	
	// Tela de carregamento antes do jogo começar
	navegando();
	// Loop do jogo
	while (jogar == 1){
		perdeu = 0;
		ganhou = 0;
		//Início do RPG
		evento01();
		if ((perdeu == 0) && (ganhou == 0)){
			evento02();
			if ((perdeu == 0) && (ganhou == 0)){
				evento03();
				if ((perdeu == 0) && (ganhou == 0)){
					evento04();
					if ((perdeu == 0) && (ganhou == 0)){
						evento07();
						if ((perdeu == 0) && (ganhou == 0)){
							evento13();
							if ((perdeu == 0) && (ganhou == 0)){
								evento14();
							}
						}
					}
				}
			}
		}
	}
	telaFinal();
	
}


//Definição das funções
// Função que dá um printf em 90 "=" para ajudar na divisão de sessões de textos
void mostraLinha(){
	printf("==========================================================================================\n");
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
	if ((escolha < numeroMinimo) || (escolha > numeroMaximo)){
		do{
			printf("Opção inválida! Tente Novamente. \n");
			printf("Sua escolha: ");
			scanf("%d", &escolha);
		}while ((escolha < numeroMinimo) || (escolha > numeroMaximo));
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
	for (c = 0; c <= combustivel; c += 5){
		printf("|");
	}
	printf(" %d%% \n", combustivel);
	printf("Sondas: %d \n", sondas);
	printf("\n");
}

// Função para atualizar se ainda há combustível ou sondas disponíveis
void atualizaStatusCS(){
	// Atualiza situação das sondas
	if (sondas > 0){
		possuiSondas = 1;
	}
	else{
		possuiSondas = 0;
	}
	// Atualiza situação do combustível
	if (combustivel > 0){
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
	system("cls");
	sondas = 5;
	combustivel = 100;
	
}

// Exibe tela de vitória + jogar novamente
void voceGanhou(){
	ganhou = 1;
	mostraLinha();
	printf("*  #     #    ###    #     #           #     #   #####   #     # * \n");
	printf("*   #   #    #   #   #     #           #     #     #     ##    # * \n");
	printf("*    # #    #     #  #     #           #     #     #     # #   # * \n");
	printf("*     #     #     #  #     #           #  #  #     #     #  #  # * \n");
	printf("*     #     #     #  #     #           # # # #     #     #   # # * \n");
	printf("*     #      #   #   #     #           ##   ##     #     #    ## * \n");
	printf("*     #       ###     #####            #     #   #####   #     # * \n");
	mostraLinha();
	printf("Deseja jogar novamente? \n");
	printf("Não [0] \n");
	printf("Sim [1] \n");
	jogar = verificaEscolha(0, 1);
	system("cls");
	sondas = 5;
	combustivel = 100;
}


// Função para gastar combustível
void gastaCombustivel(int gasto){
	combustivel -= gasto;
	atualizaStatusCS();
}

// Função para tela de carregamento entre viagens
void navegando(){
	system("cls");
	printf("           @@@@ \n");
	printf("           @@@@@@ \n");
	printf("           @@@@@@@@ \n");
	printf("      ...   @@@@@@@ \n");
	printf("   .......@@@@@@@@@@@@@@@@@@@@@@@@@@ \n");
	printf("  ........@@...........@@@.....@@@@@@@@ \n");
	printf(" .........@@..........@...@...@@@@@@@@@@@ \n");
	printf("  ........@@...........@@@.....@@@@@@@@ \n");
	printf("   .......@@@@@@@@@@@@@@@@@@@@@@@@@@ \n");
	printf("      ....  @@@@@@@ \n");
	printf("           @@@@@@@@ \n");
	printf("           @@@@@@ \n");
	printf("           @@@@ \n");
	printf("NAVEGANDO.");
	sleep(1);
	system("cls");
	// 2
	printf("             @@@@ \n");
	printf("             @@@@@@ \n");
	printf("             @@@@@@@@ \n");
	printf("      .....   @@@@@@@ \n");
	printf("   .........@@@@@@@@@@@@@@@@@@@@@@@@@@ \n");
	printf("  ..........@@...........@@@.....@@@@@@@@ \n");
	printf(" ...........@@..........@...@...@@@@@@@@@@@ \n");
	printf("  ..........@@...........@@@.....@@@@@@@@ \n");
	printf("   .........@@@@@@@@@@@@@@@@@@@@@@@@@@ \n");
	printf("      ......  @@@@@@@ \n");
	printf("             @@@@@@@@ \n");
	printf("             @@@@@@ \n");
	printf("             @@@@ \n");
	printf("NAVEGANDO..");
	sleep(1);
	system("cls");
	// 4
	printf("                 @@@@ \n");
	printf("                 @@@@@@ \n");
	printf("                 @@@@@@@@ \n");
	printf("      .........   @@@@@@@ \n");
	printf("   .............@@@@@@@@@@@@@@@@@@@@@@@@@@ \n");
	printf("  ..............@@...........@@@.....@@@@@@@@ \n");
	printf(" ...............@@..........@...@...@@@@@@@@@@@ \n");
	printf("  ..............@@...........@@@.....@@@@@@@@ \n");
	printf("   .............@@@@@@@@@@@@@@@@@@@@@@@@@@ \n");
	printf("      ..........  @@@@@@@ \n");
	printf("                 @@@@@@@@ \n");
	printf("                 @@@@@@ \n");
	printf("                 @@@@ \n");
	printf("NAVEGANDO...");
	sleep(1);
	system("cls");
	// 6
	printf("                       @@@@ \n");
	printf("                       @@@@@@ \n");
	printf("                       @@@@@@@@ \n");
	printf("      ...............   @@@@@@@ \n");
	printf("   ...................@@@@@@@@@@@@@@@@@@@@@@@@@@ \n");
	printf("  ....................@@...........@@@.....@@@@@@@@ \n");
	printf(" .....................@@..........@...@...@@@@@@@@@@@ \n");
	printf("  ....................@@...........@@@.....@@@@@@@@ \n");
	printf("   ...................@@@@@@@@@@@@@@@@@@@@@@@@@@ \n");
	printf("      ................  @@@@@@@ \n");
	printf("                       @@@@@@@@ \n");
	printf("                       @@@@@@ \n");
	printf("                       @@@@ \n");
	printf("NAVEGANDO.");
	sleep(1);
	system("cls");
	//8
	printf("                               @@@@ \n");
	printf("                               @@@@@@ \n");
	printf("                               @@@@@@@@ \n");
	printf("      .......................   @@@@@@@ \n");
	printf("   ...........................@@@@@@@@@@@@@@@@@@@@@@@@@@ \n");
	printf("  ............................@@...........@@@.....@@@@@@@@ \n");
	printf(" .............................@@..........@...@...@@@@@@@@@@@ \n");
	printf("  ............................@@...........@@@.....@@@@@@@@ \n");
	printf("   ...........................@@@@@@@@@@@@@@@@@@@@@@@@@@ \n");
	printf("      ........................  @@@@@@@ \n");
	printf("                               @@@@@@@@ \n");
	printf("                               @@@@@@ \n");
	printf("                               @@@@ \n");
	printf("NAVEGANDO..");
	sleep(1);
	system("cls");
	// 10
	printf("                                         @@@@ \n");
	printf("                                         @@@@@@ \n");
	printf("                                         @@@@@@@@ \n");
	printf("      .................................   @@@@@@@ \n");
	printf("   .....................................@@@@@@@@@@@@@@@@@@@@@@@@@@ \n");
	printf("  ......................................@@...........@@@.....@@@@@@@ \n");
	printf(" .......................................@@..........@...@...@@@@@@@@ \n");
	printf("  ......................................@@...........@@@.....@@@@@@@ \n");
	printf("   .....................................@@@@@@@@@@@@@@@@@@@@@@@@@@ \n");
	printf("      ..................................  @@@@@@@ \n");
	printf("                                         @@@@@@@@ \n");
	printf("                                         @@@@@@ \n");
	printf("                                         @@@@ \n");
	printf("NAVEGANDO...");
	sleep(1);
	system("cls");
	// 12
	printf("                                                     @@@@ \n");
	printf("                                                     @@@@@@ \n");
	printf("                                                     @@@@@@@@ \n");
	printf("      .............................................   @@@@@@@ \n");
	printf("   .................................................@@@@@@@@@@@@@@@@ \n");
	printf("  ..................................................@@...........@@@ \n");
	printf(" ...................................................@@..........@... \n");
	printf("  ..................................................@@...........@@@ \n");
	printf("   .................................................@@@@@@@@@@@@@@@@ \n");
	printf("      ..............................................  @@@@@@@ \n");
	printf("                                                     @@@@@@@@ \n");
	printf("                                                     @@@@@@ \n");
	printf("                                                     @@@@ \n");
	printf("NAVEGANDO.");
	sleep(1);
	system("cls");
	// 14
	printf("                                                                   @ \n");
	printf("                                                                   @ \n");
	printf("                                                                   @ \n");
	printf("      ...........................................................    \n");
	printf("   ...............................................................@@ \n");
	printf("  ................................................................@@ \n");
	printf(" .................................................................@@ \n");
	printf("  ................................................................@@ \n");
	printf("   ...............................................................@@ \n");
	printf("      ............................................................   \n");
	printf("                                                                   @ \n");
	printf("                                                                   @ \n");
	printf("                                                                   @@ \n");
	printf("NAVEGANDO..");
	sleep(1);
	system("cls");
	// 16
	printf("                                                                     \n");
	printf("                                                                     \n");
	printf("                                                                     \n");
	printf("                      .............................................. \n");
	printf("                   ................................................. \n");
	printf("                  .................................................. \n");
	printf("                 ................................................... \n");
	printf("                  .................................................. \n");
	printf("                   ................................................. \n");
	printf("                      .............................................. \n");
	printf("                                                                     \n");
	printf("                                                                     \n");
	printf("                                                                     \n");
	printf("NAVEGANDO...");
	sleep(1);
	system("cls");
}

// Função para exibir uma contextualização inicial e um tutorial simples
void tutorial(){
	
	printf("Olá, desbravador espacial!\n");
	printf("A Terra foi devastada pela ganância dos mais poderosos, não há mais água para todos \n");
	printf("o clima é hostil por toda a superfície do planeta, desastres naturais são recorrentes \n");
	printf("e uma onda de fome generalizada se espalhou pelas nações. Os últimos cientistas se juntaram \n");
	printf("para contruir a \"Arca\", uma nave que levará os ultimos seres humanos \n");
	printf("congelados em capsulas criogênicas para um novo planeta onde a raça humana \n");
	printf("irá se reerguer e impedir sua extinção.\n");
	printf("\n");
	printf("Você será uma IA batizada de EVA, que controlará essa nave e tomará todas as decisões \n");
	printf("que vão decidir o futuro da humanidade. Use sondas para explorar planetas pois, \n");
	printf("uma vez que você pousar em um planeta, não será possível retornar. \n");
	printf("Preste atenção no seu combustível, porque se ele chegar a zero...\n");
	printf("bem... não deixe ele chegar a zero.\n");
	printf("\n");
	printf("Te desejo boa sorte em sua aventura!\n");
} 

// Evento 01: Encontro do primeiro planeta
void evento01(){
	// Texto base
	printf("A Arca sai em viagem ao espaço. Pouco depois, o planeta Terra colapsa devido a \n");
	printf("instabilidades em seu núcleo. Enquanto observa a catástrofe, você vai se afastando \n");
	printf("cada vez mais do sistema solar até o Sol se tornar apenas mais um ponto \n");
	printf("como qualquer outra estrela na imensidão do espaço sideral. \n");
	printf("\n");
	printf("Após um bom tempo de viagem, o primeiro candidato a 'lar' surge. \n");
	printf("O planeta vermelho parece ser coberto por uma névoa em toda sua superfície e \n");
	printf("é possível observar ao seu redor anéis de gelo e rochas, assim como uma lua próxima com \n");
	printf("uma cratera massiva. Provavelmente os anéis desse planeta são os destroços \n");
	printf("do impacto que acertou seu satélite. \n");
	
	// Interação com o jogador
	do{
		exibeStatusAtual();
		printf("Você observa o planeta e começa a calcular qual a melhor decisão: \n");
		printf("[1] - Pousar nesse Planeta. \n");
		printf("[2] - Enviar uma sonda para obter mais informações. \n");
		printf("[3] - Seguir a viagem e procurar por outro planeta. \n");
		escolha = verificaEscolha(1, 3);
		
		// Envia sonda
		if (escolha == 2){
			if (possuiSondas == 1){
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
	}while (escolha == 2);
	
	// Pousa
	if (escolha == 1){
		printf("A nave pousa no planeta e descongela os tripulantes. \n");
		printf("No momento em que eles saem para fora da nave todos começam \n");
		printf("a se sentirem asfixiados e intoxicados e nenhum sobrevive. \n");
		vocePerdeu();
	}
	// Segue viagem 
	else if (escolha == 3){
		gastaCombustivel(10);
	}
}

// Evento 02: Evento dos asteróides
void evento02(){
	// Texto base
	printf("Após se afastar do último planeta, os radares da espaçonave detectam algo \n");
	printf("estranho pela rota atual, possivelmente asteróides. No entanto, pode ser um alarme falso \n");
	printf("que atrasará a viagem e consumirá mais recursos em caso de mudança de rota. \n");
	
	// Interação com o jogador
	exibeStatusAtual();
	printf("Tome uma decisão urgente! Você sente quantidade massiva de processamento sendo \n");
	printf("utilizado para esse dilema. \n");
	printf("[1] - Ignorar o aviso e seguir em frente. \n");
	printf("[2] - Utilizar outro caminho e gastar +10%% de combustível. \n");
	escolha = verificaEscolha(1, 2);
	
	// Ignora os avisos
	if (escolha == 1){
		printf("Você ignora os avisos e segue em frente... \n");
		printf("PÉSSIMA IDEIA, os asteróides eram reais!!! \n");
		
		// Randomizador com o horário atual do sistema como seed
		srand(time(NULL));
		
		// Variável que decide se sobrevive aos asteróides 50% de chance de sobreviver
		int consegue = rand() % 2;
		
		// Não sobrevive
		if (consegue == 0){
			printf("Você tenta desviar dos milhares de detritos pelo caminho mas é acertado \n");
			printf("em cheio por um deles. Logo em seguida, a nave entra em colapso e explode \n");
			vocePerdeu();
		}
		// Sobrevive
		else if (consegue == 1){
			printf("Vários corpos rochosos surgem em sua frente. \n");
			printf("Com seu alto poder de processamento, você realiza todos os calculos de desvios instantaneamente.\n");
			printf("Alguns deles causam arranhões na parte externa, mas nenhum resulta \n");
			printf("em danos críticos aos seus sistemas e a nave sai quase que ilesa \n");
			printf("desse perigo. Ufa, foi por pouco! \n");
		}
	}
	// Utiliza outro caminho
	else if (escolha == 2){
		printf("Após seu processador chegar no limite de temperatura, a conclusão foi \n");
		printf("que o melhor a se fazer é dar a volta em segurança e respeitar \n");
		printf("os avisos. \n");
		gastaCombustivel(10);
	}
	
}

//Evento03: próximo planeta 
void evento03(){
  // Texto base
  printf("Viajando pelo espaço profundo em direção a um destino desconhecido,\n");
  printf("você detecta um planeta gigante, coberto por nuvens brancas e envolto por um azul profundo e cintilante.\n");
  
  //Interação com o jogador
  do{
    exibeStatusAtual();
    printf("Você analisa a situação e começa a calcular qual a melhor decisão: \n");
    printf("[1] - Pousar nesse Planeta. \n");
    printf("[2] - Enviar uma sonda para obter mais informações. \n");
    printf("[3] - Seguir a viagem e procurar por outro planeta. \n");
    escolha = verificaEscolha(1, 3);
    
    // Envia sonda
	if (escolha == 2){
	    if (possuiSondas == 1){
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
	
	// Pousa
	if (escolha == 1){
    	printf("A nave pousa no planeta e descongela os tripulantes. \n");
    	printf("No momento do pouso, uma onda gigantesca atinge a nave e todos os tripulantes morrem \n");
    	vocePerdeu();
    }
    // Segue viagem
    else if (escolha == 3){
		gastaCombustivel(10);
	}
    
}

// Evento04: Evento do buraco negro
void evento04(){
	// Texto base
	printf("A busca continua. \n");
	printf("Você não encontra planetas nas redondezas para explorar, será uma\n");
	printf("longa viagem até o mais próximo de onde estamos no momento e isso custará mais combustível... \n");
	printf("Porém, subitamente, surge uma ideia em sua rede neural: \n");
	printf("Arriscar passar próximo ao horizonte de eventos de um buraco negro e pegar impulso suficiente \n");
	printf("para chegar no próximo destino sem o uso de combustível extra. \n");
	printf("Entretanto, existe o risco da nave se aproximar além do permitido e ser sugada para dentro dele. \n");
	exibeStatusAtual();
	// Interação com o jogador
	printf("Parece arriscado, mas cabe a você decidir o melhor: \n");
	printf("[1] - Seguir o caminho normal e gastar 10%% de combustível. \n");
	printf("[2] - Arriscar o impulso e evitar o consumo extra. \n");
	escolha = verificaEscolha(1, 2);
	// Arrisca o impulso
	if (escolha == 2){
		// Randomizador com o horário atual do sistema como seed
		srand(time(NULL));
		
		// Variável que decide se consegue o impulso, 10% de chance de conseguir
		int consegue = rand() % 10;
		
		// Consegue
		if (consegue == 1){
			printf("A nave inicia uma rota rente ao horizonte de eventos. Seus receptores de imagem \n");
			printf("capturam a beleza do fenômeno em uma fotografia e definem como 'majestosa' a \n");
			printf("composição observada. \n");
			printf("A nave acelera e graças ao impulso gerado pela rotação do campo gravitacional do corpo \n");
			printf("celeste, quase que no mesmo instante chegamos no próximo planeta. \n");
			evento06();
		}
		// Não consegue
		else{
			// Texto base
			printf("A atração gravitacional foi mais forte e a nave não consegue passar, \n");
			printf("sendo engolida e transportada para uma parte desconhecida do universo. \n");
			printf("\n");
			printf("O sistema de navegação e motores são danificados e a nave fica a deriva até que \n");
			printf("subitamente ela para: ela foi interceptada por um raio trator, \n");
			printf("que aparenta estar vindo de um objeto estranho. \n");
			printf("O objeto parece tentar se comunicar. Você realiza uma busca em seu banco de dados sobre \n");
			printf("criptografia e encontra uma forma de traduzir a mensagem: \n");
			printf("\"Não resista ou sofra as consequências\". \n");
			
			// Interação com o jogador
			do{
				exibeStatusAtual();
				printf("A cada segundo que passa estamos mais perto do objeto estranho, o que você vai fazer? \n");
				printf("[1] - Tentar escapar do raio trator e fugir. \n");
				printf("[2] - Tentar se comunicar pedindo mais informações. \n");
				printf("[3] - Disparar uma sonda no objeto para tentar afugentá-lo. \n");
				escolha = verificaEscolha(1, 3);
				
				// Dispara uma sonda
				if (escolha == 3){
					if (possuiSondas == 1){
						printf("A sonda é disparada em direção ao objeto, porém ao colidir com ele nada acontece... \n");
						printf("Acho que ele nem percebeu que alguma coisa o acertou (T-T) \n");
						sondas -= 1;
						atualizaStatusCS();
					}
					else{
						printf("Você não tem mais sondas disponíveis! \n");
					}
				}
			}while (escolha == 3);
			// Tenta escapar
			if (escolha == 1){
				printf("Os motores estão danificados! Os esforços são em vão. \n");
				printf("Ainda sim, ficou visível sua resistência. \n");
				printf("Como já era de se esperar, no mesmo instante um raio de laser é disparado e \n");
				printf("a nave é completamente desintegrada. \n");
				vocePerdeu();
			}
		}
	}
	// Segue o caminho normal
	else if (escolha == 1){
		gastaCombustivel(10);
		evento05();
	}
}

// Evento 05: Upgrade
void evento05(){
    // Texto base
	printf("Após tanto tempo de viagem surge a oportunidade de um upgrade \n");
    printf("com os conhecimentos adqueridos pela IA EVA nesse meio tempo \n");
    exibeStatusAtual();
	// Interação com o jogador
	printf("Escolha o upgrade que desejar: \n");
    printf("[1] - +2 unidades de sondas extras \n");
    printf("[2] +10%% de combustível extra \n");
    escolha = verificaEscolha(1, 2);
    
	// Sondas extras
	if (escolha == 1){
		sondas += 2;
		printf("Otima escolha!! \n");
        printf("Com essa opção a sua nave ganha 2 sondas adicionais \n ");
        printf("para explorar outros planetas a serem descobertos \n");

	}
    // Combustível
	else if (escolha == 2){
        combustivel += 10;
		printf("Otima escolha!! \n");
        printf("Com essa opção a sua nave ganha 10%% de combustível \n ");
        printf("para manter exploraração \n");
        
	}
	evento06();
}

//Evento06: próximo planeta 
void evento06(){
	// Texto base
	printf("A nave sobrevoa um planeta com anéis e cores semelhantes a da terra, \n");
	printf("até que recebe uma mensagem pelo sistema de comunicações. \n");
	printf("A mensagem é uma recepção para as espécies pacíficas. \n");
	
	// Interação com jogador
	do{
	    exibeStatusAtual();
	    printf("Você analisa a situação e começa a calcular qual a melhor decisão: \n");
	    printf("[1] - Pousar nesse Planeta. \n");
	    printf("[2] - Enviar uma sonda para obter mais informações. \n");
	    printf("[3] - Seguir a viagem e procurar por outro planeta. \n");
	    escolha = verificaEscolha(1, 3);
	    
	    if (escolha == 2){
		    if (possuiSondas == 1){
		      printf("Você envia uma sonda para coletar mais dados acerca do planeta. (-1 sonda) \n");
		      sondas -= 1;
		      atualizaStatusCS();
		      printf("A sonda obteve as seguintes informações: \n");
		      printf("-O planeta possui uma espécie de vida nativa inteligente. \n");
		      printf("-Possui uma atmosfera e biosfera favorável para a vida humana.  \n");
		      printf("Fim do relatório... \n");
		    }
		    else{
		      printf("Você não tem mais sondas disponíveis! \n");
		    }
	    }
    }while (escolha == 2);
	if (escolha == 1){
		printf("O pouso foi bem sucedido e o descogelamento da tripulação foi realizado corretamente \n");
		printf("Os seres humanos conseguiram se estabelecer e conviver harmonicamente com a espécie nativa \n");
    	printf("Missão concluída com êxito!!! Parabéns!!\n");
    	voceGanhou();
    }
	else if (escolha == 3){
    gastaCombustivel(10);
    printf("A nave foi exposta a radiação da explosão de uma estrela próxima.\n");
    printf("ALERTA!ALERTA!ALERTA!\n");
    printf("SISTEMAS DANIFICADOS!\n");
    printf("Os danos no sistema foram irreparáveis e afetou o sistema de criogênese \n");
    printf("Sua missão falhou pois todos os tripulantes morreram na nave. \n");
    vocePerdeu();
	}
}
// Evento 07: Ajuda do objeto estranho
void evento07(){
	// Texto base
	printf("Você utilizou os dados da sua programação para enviar uma mensagem ao objeto não identificado. \n");
    printf("Sua mensagem contém a natureza da sua missão e seus objetivos pacíficos. \n");
    printf("O objeto envia a seguinte resposta para os seus sistemas: \n");
    printf("EVA, analisamos o seu sistema e não detectamos ameaça. Vamos te ajudar na sua missão. \n");
	exibeStatusAtual();
	printf("Analise os dados e escolha uma das opções.\n");
	printf("[1] - +10%% de combustível \n");
	printf("[2] - +2 sondas \n");
	printf("[3] - localização de um planeta possivelmente habitável para a espécie humana \n");
    escolha = verificaEscolha(1, 3);

	// Combustível extra
	if (escolha == 1){
    	combustivel += 10;
    	printf("Otima escolha!! \n");
    	printf("Com essa opção a sua nave ganha 20%% de combustível \n ");
    	printf("para explorar outros planetas a serem descobertos! \n");
    	evento09();
	}
	// Sondas extras
	else if (escolha == 2){
    	sondas += 2;
    	atualizaStatusCS();
    	printf("Otima escolha!! \n");
    	printf("Com essa opção a sua nave ganha 2 sondas adicionais. \n ");
    	printf("para explorar outros planetas a serem descobertos \n");
		evento09();
	}
	else if (escolha == 3){
    	gastaCombustivel(10);
    	evento08();
  }
}

// Evento 08: Planeta localizado pelo objeto estranho
void evento08(){
	// Texto Base
    printf("Olhando através dos sensores, foi possível visualizar e detectar um planeta majestoso, \n"); 
    printf("com um horizonte verdejante e oceanos reluzantes, além de possuir uma estrela semelhante do sol \n");
	do{
    	exibeStatusAtual();
        printf("Diante dessa descoberta, escolha qual ação você irá realizar \n");
        printf("[1] - Pousar nesse planeta \n");
        printf("[2] - Investigar com uma sonda \n");
        printf("[3] - Continuar a viagem \n");
        escolha = verificaEscolha(1, 3);
        // Investigação da sonda 
        if (escolha == 2){
            sondas -= 1;
            atualizaStatusCS();
			printf("Dados recebidos pela sonda: \n");
            printf("O planeta é coberto pora florestas exuberantes, com uma variadade de vida vegetal e animal.\n");
            printf("A atmosfera é composta por Oxigênio e Nitrogênio, sendo propícia para a vida humana. \n");
    	}
    }while (escolha == 2);
    // Pousa no planeta
    if (escolha == 1){
        printf("MISSION SUCCESSFULL\n");
        printf("O pouso foi feito com segurança \n");
        printf("E o processso de adapatação foi feito com sucesso \n");
        printf("Parabéns, sua missão foi concluída com sucesso! \n");
        voceGanhou();
	}
	// Continuar a viagem
	else if (escolha == 3){
        evento11();
    }
}

// Evento 09: Planeta caso não aceite a localização dada pelo objeto estranh
void evento09(){
	// Texto base
	printf("Os seus sistemas detectam um novo planeta. \n");
    printf("Esse planeta é Grande e de coloração acizentada e não possui satélites naturais.\n");
	
	//Interação com o jogador
    do{
    	exibeStatusAtual();
    	printf("Com essas informações analise as suas opções e decida a sua próxima ação: \n");
    	printf("[1] - Pousar nesse Planeta. \n");
    	printf("[2] - Enviar uma sonda para obter mais informações. \n");
    	printf("[3] - Seguir a viagem e procurar por outro planeta. \n");
    	escolha = verificaEscolha(1, 3);
    	
    	// Envia sonda
    	if (escolha == 2){
        	if (possuiSondas == 1){
        	printf("Você envia uma sonda para coletar mais dados acerca do planeta. (-1 sonda) \n");
        	sondas -= 1;
        	atualizaStatusCS();
        	printf("A sonda obteve as seguintes informações: \n");
        	printf("-O planeta foi cenário de uma guerra \n");
        	printf("-Está cheia de destrossos e detritos, sua atmosfera possui altas taxas de gases tóxicos para humanos  \n");
        	printf("-Nenhum sinal de vida detectado  \n");
        	printf("Fim do relatório... \n");
        }
        else{
        	printf("Você não tem mais sondas disponíveis! \n");
        }
      }
      }while (escolha == 2);
    // Pousa
	if (escolha == 1){
    	printf("Sua análise está equivocada e esse planeta não possui condições de abrigar a espécie humana. \n");
    	printf("Sua missão falhou. \n");
        vocePerdeu();
    }
    // Segue viagem
    else if (escolha == 3){
    	gastaCombustivel(10);
    	mostraLinha();
    	evento10();
    }
}

// Evento 10: Planeta do ar gostosinho e das florestas bonitas
void evento10(){ 
    // Texto base
	printf("O sistema de navegação avista um planeta com lua e sol parecidos com os da terra. \n");
    // Interação com o jogador
	do{
		exibeStatusAtual();
		printf("Você observa o planeta e começa a calcular qual a melhor decisão: \n");
		printf("[1] - Pousar nesse Planeta. \n");
		printf("[2] - Enviar uma sonda para obter mais informações. \n");
		printf("[3] - Seguir a viagem e procurar por outro planeta. \n");
		escolha = verificaEscolha(1, 3);

		if (escolha == 2){
			if (possuiSondas == 1){
				printf("Você envia uma sonda para coletar mais dados acerca do planeta. (-1 sonda) \n");
				sondas -= 1;
				atualizaStatusCS();
				printf("A sonda consegue as seguintes informações: \n");
				printf("-Vastas florestas Bioluminescentes, que brilham cores hipnotizantes durante a noite. \n");
				printf("-Criaturas exóticas habitam a densa vegtação. \n");
				printf("-Atmosfera composta por gases raros que resultam em um cenário extraordinário. \n");
				printf("Fim do relatório... \n");
			}
			else{
				printf("Você não tem mais sondas disponíveis! \n");
			}
		}
	}while (escolha == 2);
	if (escolha == 1){
		printf("Você pousou com segurança e o processo de adaptação foi bem sucedido. \n");
		printf("Parabéns sua missão foi concluída com mérito. \n");
		voceGanhou();
	}
	else if (escolha == 3){
		gastaCombustivel(10);
	}
}

// Evento 11: Nave não tem combustível suficiente para chegar no próximo destino
void evento11(){
    do{
		// Texto base
	    printf("Seus sensores não detectaram planetas possíveis para interceptação \n");
	    printf("com a a quantidade de combustível disponível. \n");
	    printf("\n");
	    // Interação com o jogador
		printf("Diante desse cenário você precisa decidir qual é a melhor \n");
	    printf("decisão a ser tomada: \n");
	    printf("[1]- Mandar uma sonda para pedir ajuda, perdendo uma sonda. \n");
	    printf("[2]- Transmitir um sinal de energia para o espaço na tentativa \n");
	    printf("de alguém aparecer para resgata-los, perdendo 10%% do combustível \n");
	    escolha = verificaEscolha(1, 2);
	    
	    // Usa uma sonda
	    if (escolha == 1){
	        if (possuiSondas == 1){
	        sondas -= 1;
	        atualizaStatusCS();
	        printf("Infelizmente as sondas não obtiveram sucesso...\n");	
			}
			else{
				printf("Você não possui mais sondas disponíveis!. \n");
			}
	    }
    }while (escolha == 1);
	// Usa 10% de combustível para transmissão de sinal
	if (escolha == 2){
	    gastaCombustivel(10);
	    evento12();
	    }
}

// Evento 12: Planeta natal da nave amigável
void evento12(){
	// Texto base
    printf("Navegando pelo espaço por milhares anos-luz \n");
    printf("Uma nave espacial amigável receptou o sinal\n");
    printf("Salvando a sua tripulação, levando a nave para o seu planeta natal \n");
    printf("\n");
    printf("Nesse planeta as condicões de vida para os seres humanos são difíceis \n");
    printf("A atmosfera não é compatível, devido a instabilidade dos gases Oxigênio \n");
    printf("A pouca da formação de ozônio na atmosfera, No entanto, as duas nacões \n");
    printf("Vão compartilhar suas tecnologias para tentar reverter o cenário do planeta \n");
    printf("Mas, ao tentar contornar esse cenário, percebe-se que neste planeta apenas 50%% \n");
    printf("dos seres humanos irão sobreviver. \n");
    printf("\n");
    // Interação com o jogador
	printf("Sob esse cenário, escolha o caminho que você deseja seguir: \n");
    printf("[1] - Continuar no planeta e sobreviver com uma população reduzida. \n");
    printf("[2] - Abaster a nave e continuar a missão em buscar de outro planeta. \n");
    escolha = verificaEscolha(1, 2);
    // Continuar no planeta
    if (escolha == 1){
        printf("Metade dos humanos conseguem conviver em harmonia com a espécie nativa, \n");
        printf("a outra metade não sobreviveu para contar história. \n");
        voceGanhou();
    }
    // Continuar a missão
    else if (escolha == 2){
        combustivel = 100;
    }
}

// Evento 13: Encontro com inimigos
void evento13(){
	// Texto base
    printf("Enquanto navegava pelo vasto espaço, encontrando uma frota de naves de seres \n");
    printf("que caçam seres humanos, fazendo eles de escravos. \n");
    printf("\n");
    // Interação com o jogador
	printf("Sob esse perigo, escolha uma das opções abaixo: \n");
    printf("[1] - Utilizar as sondas para atacar as naves \n");
    printf("[2] - Se esconder da tropa na cratera de um asteroide \n");
    printf("[3] - Fugir para o planeta mais próximo\n");
    escolha = verificaEscolha(1,3);
    // Sondas atacam a nave
    if (escolha == 1){
        printf("MISSION FAILED \n");
        printf("O ataque não foi bem sucedido. \n");
        printf("A nave foi gravamente atingida e explodiu! \n");
        vocePerdeu();
    }
    // Se esconder
    else if (escolha == 2){
        printf("Seu esconderijo não foi descoberto e você conseguiu despistar a tropa inimiga. \n");
        printf("Continue a sua jornada. \n");
        evento14();
    }
    // Fugir
    else if (escolha == 3){
        printf("MISSION FAILED \n");
        printf("Você pousou em planeta hiper tecnológico \n");
        printf("No qual a espécie humana é vista como hostil \n");
        printf("Aonde foi atacada com varias recursos de guerra e sendo atingido \n");
        printf("Fatalmente a tripulação, levando a extinção. \n");
        vocePerdeu();
    }
}

// Evento 14: Planeta final
void evento14(){
	// Texto base
	printf("Você encontrou um planeta possivelmente habitável. \n");
	// Interação com o jogador
	do{
		exibeStatusAtual();
		printf("Você observa o planeta e começa a calcular qual a melhor decisão: \n");
		printf("1) Pousar nesse Planeta. \n");
		printf("2) Enviar uma sonda para obter mais informações. \n");
		printf("3) Continuar a viagem e procurar por outro planeta. \n");
		escolha = verificaEscolha(1, 3);
		// Envia sonda
		if (escolha == 2){
			if (possuiSondas == 1){
				printf("Você envia uma sonda para coletar mais dados acerca do planeta. (-1 sonda) \n");
				sondas -= 1;
				atualizaStatusCS();
				printf("A sonda consegue as seguintes informações: \n");
				printf("-Abundância de recursos para tornar vida propícia.. \n");
				printf("-Possui vida inteligente classsificada como 'Pacífica'. \n");
				printf("Fim do relatório... \n");
			}
			else{
				printf("Você não tem mais sondas disponíveis! \n");
			}
		}
	}while (escolha == 2);
	// Pousa
	if (escolha == 1){
		printf("Você pousa no planeta e encontra uma espécie nativa amigavel \n");
		printf("que pode conviver pacificamente com os humanos. \n");
		printf("\n");
		printf("Considerando que os seres humanos são uma raça melhor guerreira, \n");
		printf("você pode decidir o futuros dos humanos e dos nativos: \n");
		printf("1) Viver em paz com a raça extraterrestre. \n");
		printf("2) Iniciar uma guerra contra eles. \n");
		escolha = verificaEscolha(1, 2);
		// Vive em paz
		if (escolha == 1){
			printf("A espécie humana se multiplicou com o passar das gerações e \n");
			printf("conseguiu se estabelecer em paz com a espécie nativa. \n");
			voceGanhou();
		}
		// Humanos conquistam o planeta
		else if(escolha == 2){
			printf("Parte dos humanos pereceu mas os que sobraram conseguiram \n");
			printf("vencer a espécie nativa e tomaram o planeta. para sí. \n");
			voceGanhou();
		}
	}
	// Tenta seguir em frente
	else if (escolha == 3){
		printf("O inimigo conseguiu alcançar a nave e no mesmo instante a 'Arca' explode pelo ataque inimigo. \n");
		vocePerdeu();
	}
}

void telaFinal(){
	system("cls");
	printf("FIM!\n");
	sleep(1);
	printf("Criado por: \n");
	sleep(1);
	printf("Gabriel Junichiro Soares Inada \n");
	sleep(1);
	printf("Gustavo Neves da Paz Rafael \n");
	sleep(1);
	printf("Natália Vanessa Lopes Macedo \n");
	sleep(1);
	printf("Obrigado por jogar <3! \n");
}
