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
	printf("Aperte enter para começar...");
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

// Evento 01: Encontro do primeiro planeta
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
	if (escolha == 1){
		printf("A nave pousa no planeta e descongela os tripulantes. \n");
		printf("No momento em que eles saem para fora da nave todos começam \n");
		printf("a se sentirem asfixiados ou intoxicados e nenhum sobrevive. \n");
		vocePerdeu();
	}
	else if (escolha == 3){
		gastaCombustivel(10);
	}
}

// Evento 02: Evento dos asteróides
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
	
	if (escolha == 1){
		printf("Você ignora os aviso e segue em frente... \n");
		printf("PÉSSIMA IDEIA, os asteróides eram reais!!! \n");
		
		// Randomizador com o horário atual do sistema como seed
		srand(time(NULL));
		
		// Variável que decide se sobrevive aos asteróides 50% de chance de sobreviver
		int consegue = rand() % 2;
		
		// Não sobrevive
		if (consegue == 0){
			printf("Você tenta desviar dos milhares de detritos pelo caminho mas é acertado \n");
			printf("em cheio por um deles, logo em seguida a nave entra em colapso e explode \n");
			vocePerdeu();
		}
		// Sobrevive
		else if (consegue == 1){
			printf("Vários corpos rochosos surgem em sua frente, com seu alto poder \n");
			printf("de processamento você realiza todos os calculos de desvios instântaneamente, \n");
			printf("alguns deles causam arranhões na parte externa, mas nenhum resulta \n");
			printf("em danos críticos aos seus sistemas e a nave sai quase que ilesa \n");
			printf("desse perigo. Ufa, foi por pouco! \n");
		}
	}
	else if (escolha == 2){
		printf("Após seu processador chegar no limite de temperatura a conclusão foi \n");
		printf("que o melhor a se fazer é dar a volta em segurança e respeitar \n");
		printf("os avisos. \n");
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
  
	if (escolha == 1){
    	printf("A nave pousa no planeta e descongela os tripulantes. \n");
    	printf("No momento do pouso um onda gigantesca atinge a nave e todos os tripulantes morrem \n");
    	vocePerdeu();
    }
    else if (escolha == 3){
		gastaCombustivel(10);
	}
    
}

// Evento04: Evento do buraco negro
void evento04(){
	printf("A busca continua, você não encontra planetas nas redondezas para explorar, será uma\n");
	printf("longa viagem até o mais próximo de onde estamos no momento, isso custará mais combustível... \n");
	printf("Porém, subitamente surge uma ideia em sua rede neural: Arriscar passar próximo ao horizonte \n");
	printf("de eventos de um buraco negro e pegar impulso suficiente para chegar no próximo destino sem o \n");
	printf("uso de combustível extra. Existe o risco da nave se aproximar além do permitido e ser sugada \n");
	printf("para dentro dele. \n");
	exibeStatusAtual();
	printf("Parece arriscado, mas cabe a você decidir o melhor: \n");
	printf("1) Seguir o caminho normal e gastar 10%% de combustível. \n");
	printf("2) Arriscar o impulso e evitar o consumo extra. \n");
	escolha = verificaEscolha(1, 2);
	if (escolha == 2){
		// Randomizador com o horário atual do sistema como seed
		srand(time(NULL));
		
		// Variável que decide se consegue o impulso, 10% de chance de conseguir
		int consegue = rand() % 10;
		
		// Consegue
		if (consegue == 0){
			printf("A nave inicia uma rota rente ao horizonte de eventos. Seus receptores de imagem \n");
			printf("capturam a beleza do fenômeno em uma fotografia e definem como 'majestosa' a \n");
			printf("composição observada. \n");
			printf("A nave acelera e graças ao impulso gerado pela rotação do campo gravital do corpo \n");
			printf("celeste, quase que no mesmo instante chegamos no próximo planeta. \n");
			evento06();
		}
		// Não consegue
		else{
			printf("A atração gravitacional foi mais forte e a nave não consegue passar, \n");
			printf("ela é engolida e transportada para uma parte desconhecida do \n");
			printf("universo. \n");
			printf("O sistema de navegação e motores são danificados e a nave fica a deriva até que \n");
			printf("subitamente ela para, ela foi interceptada por um raio trator \n");
			printf("que aparenta estar vindo de um objeto estranho. \n");
			printf("O objeto parece tentar se comunicar, você realiza uma busca em seu banco de dados sobre \n");
			printf("criptografia e encontra uma forma de traduzir a mensagem: 'Não resista ou sofra as consequências'. \n");
			// Interação com o jogador
			do{
				exibeStatusAtual();
				printf("A cada segundo que passa estamos mais perto do objeto estranho, o que você vai fazer? \n");
				printf("1) Tentar escapar do raio trator e fugir. \n");
				printf("2) Tentar se comunicar pedindo mais informações. \n");
				printf("3) Disparar uma sonda no objeto para tentar afugentá-lo. \n");
				escolha = verificaEscolha(1, 3);
		
				if (escolha == 3){
					if (possuiSondas == 1){
						printf("A sonda e disparada em direção ao objeto, porém ao colidir com ele nada acontece... \n");
						printf("Acho que ele nem percebeu que alguma coisa acertou ele (T-T) \n");
						sondas -= 1;
						atualizaStatusCS();
					}
					else{
						printf("Você não tem mais sondas disponíveis! \n");
					}
				}
			}while (escolha == 3);
			if (escolha == 1){
				printf("Os motores estão danificados! Os esforços são em vão. \n");
				printf("Ainda sim, ficou visível sua resistência. \n");
				printf("Como já era de se esperar, no mesmo instante um raio de laser é disparado e \n");
				printf("a nave é completamente desintegrada. \n");
				vocePerdeu();
			}
		}
	}
	else if (escolha == 1){
		gastaCombustivel(10);
		evento05();
	}
}

// Evento 05: Upgrade
void evento05(){
    // Texto base
	printf("Após tanto tempo de viagem surge a oportunidade de um upgrade");
    printf("Com os conhecimentos adqueridos pela IA EVA nesse meio tempo \n");
    printf("Escolha o upgrade que desejar: \n");
    printf("1) +2 unidades de sondas extras \n");
    printf("2) +10%% de combustível extra \n");
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
        combustivel += 20;
		printf("Otima escolha!! \n");
        printf("Com essa opção a sua nave ganha 2 sondas adicionais \n ");
        printf("Para explorar outros planetas a serem descobertos \n");
        
	}
	evento06();
}

//Evento06: próximo planeta 
void evento06(){
  printf("A nave sobrevoa um planeta com anéis e cores semelhantes a da terra, \n");
  printf("até que recebe uma mensagem pelo sistema de comunicações. \n");
  printf("A mensagem é uma recepção para as espécies pacíficas. \n");

  do{
    exibeStatusAtual();
    printf("Você analisa a situação e começa a calcular qual a melhor decisão: \n");
    printf("1) Pousar nesse Planeta. \n");
    printf("2) Enviar uma sonda para obter mais informações. \n");
    printf("3) Seguir a viagem e procurar por outro planeta. \n");
    escolha = verificaEscolha(1, 3);
    
    mostraLinha();
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
		printf("Os seres humanos conseguiram se estabelecer e conviver harmonicamente com a espécie nativa\n");
    	printf("Missão concluída com êxito!!! Parabéns!!\n");
    	voceGanhou();
    }
	else if (escolha == 3){
    mostraLinha();
    gastaCombustivel(10);
    printf("A nave foi exposta a radiação da explsão de uma estrela próxima.\n");
    printf("ALERTA!ALERTA!ALERTA!\n");
    printf("SISTEMAS DANIFICADOS!\n");
    printf("Os danos no sistema foram inrreparáveis e afetou o sistema de criogênese\n");
    printf("Sua missão falhou pois todos os tripulantes morreram na nave\n");
    perdeu = 1;
    vocePerdeu();
	}
}
// Evento 07:
void evento07(){
	printf("evento 07\n");
}

// Evento 08:
void evento08(){
	printf("evento 08\n");
}

// Evento 09:
void evento09(){
	printf("evento 09\n");
}

// Evento 10:
void evento10(){
	printf("evento 10\n");
}

// Evento 11:
void evento11(){
	printf("evento 11\n");
}

// Evento 12:
void evento12(){
	printf("evento 12\n");
}

// Evento 13:
void evento13(){
	printf("evento 13\n");
}

// Evento 14:
void evento14(){
	printf("evento 14\n");
}
