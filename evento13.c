void evento13(){
// Contexto
    printf("Navegando pelo vasto espaço,acaba \n");
    printf("Encontrando uma frota de naves de seres \n");
    printf("Que caçam os seres humanos, fazendo \n");
    printf("Os seres humanos como escravos");
    printf("Sob esse perigo, escolha uma das opções abaixo \n ");
    printf("[01] - Utilizar as sondas para atacar as naves \n ");
    printf("[02] - Se esconder da tropa da cratera de um asteroide \n");
    printf("[03] - Fugir para o planeta mais próximo planeta \n");
    escolha = verificaEscolha(1,3);
    // condição 01 que vai resultado em game over
    if ( escolha ==1){
        printf("MISSION FAILED \n");
        printf("O ataque não foi bem sucedido \n");
        printf("A nave foi gravamente atingida e explodiu \n");
        // chamar a função voceperdeu()
    }
    // condição 02 para fugir dos inimigos
    else if ( escolha ==2){
        printf("Seu esconderijo não foi descoberto\n ");
        printf("Você conseguiu dispistar a tropa inimiga\n");
        printf("Continue a sua jornada");
        // chamar a funcao navegando()
        // chamar a funçaõ evento14()
    }
    // condição 03 que vai resultado em game over
    else if ( escolha == 3){
         printf("MISSION FAILED \n");
         printf("Você pousou em planeta hiper tecnológico \n");
         printf("No qual a espécie humana é vista como hostil \n");
         printf("Aonde foi atacada com varias recursos de guerra e sendo atingido \n");
         printf("Fatalmente a tripulação, levando a extinção \n");
        //  chamar a funcao voceperdeu()
    }
}
