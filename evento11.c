#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
void evento11(){
    // inicio
    //Variável que vai ser base das condições propostas 
    int escolha;
// do while para ficar nesse loop enquanto o usuário escolher a opção 01
    do {
        //Desenvolvimento 
    printf("Seus sensores não detectaram planetas \n");
    printf("possíveis para intercptação com a a quantidade de combustível disponível \n");
    // chamar a função Navegando()
    printf("Diante desse cenário \n");
    printf("você  precisa decidir qual é a melhor decisão a ser tomada \n");
    printf("[01]- Mandar uma sonda para pedir ajuda, perdendo uma sonda \n");
    printf("[02]-  Transmitir um sinal de energia para o espaço com a tentativa \n ");
    printf("de alguém tentar resgata-los, perdendo 10%% do combustível \n ");
    scanf("%d",&escolha);
    system("cls");
    // condicao 01 para perde a sonda e ficar no loop
        if ( escolha ==1){
        // chamar a função Navegando()
        system("cls");
        printf("INFELIZMENTE \n");
        printf("As sondas não obtiveram sucesso\n");
        // chamar a função atualizaStatusCS()
        system("pause"); 
        // chamar a função mostrarLinha()
    }
    // condição 02 para perde 10% de combustível e seguir o caminho
    else if ( escolha ==2){
        // chamr a funcao navegando()
        printf("Mesmo com a dificuldade do trasmitir o sinal\n ");
        printf("alguém conseguir receber o sinal \n");
        //  chamar a função gastaCombustivel(10);
         // chamar a função mostrarLinha()
    }
    } while (escolha==1);
    // chamar a funcao navegando() para completar o evento12!!!!!!!!!
    // FIM DO EVENTO11
}
