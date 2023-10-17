//Evento06: próximo planeta 
void Evento06(){
  printf("A nave sobrevoa um planeta com anéis e cores semelhantes a da terra.\n");
  printf(", até que recebe uma mensagem pelo sistema de comunicações.\n");
  printf("A mensagem é uma recepção para as espécies pacíficas.\n");

  do{
    exibeStatusAtual();
    printf("Você analisa a situação e começa a calcular qual a melhor decisão: \n");
    printf("0) Pousar nesse Planeta. \n");
    printf("1) Enviar uma sonda para obter mais informações. \n");
    printf("2) Seguir a viagem e procurar por outro planeta. \n");
    escolha = verificaEscolha(2);
    
    mostraLinha();
    if(escolha == 1){
    if(possuiSondas == 1){
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
  }while (escolha == 1);
   mostraLinha();
  if(escolha == 0){
      printf("O pouso foi bem sucedido e o descogelamento da tripulação foi realizado corretamente \n");
      printf("Os seres humanos conseguiram se estabelecer e conviver harmonicamente com a espécie nativa\n");
    printf("Missão concluída com êxito!!! Parabéns!!\n");
    // mostrar função veceu

    }else if (escolha == 2){
     mostraLinha();
    gastaCombustivel(10);
    atualizaStatusCS();
    printf("A nave foi exposta a radiação da explsão de uma estrela próxima.\n");
    printf("ALERTA!ALERTA!ALERTA!\n");
    printf("SISTEMAS DANIFICADOS!\n");
    printf("Os danos no sistema foram inrreparáveis e afetou o sistema de criogênese\n");
     printf("Sua missão falhou pois todos os tripulantes morreram na nave\n");
    perdeu = 1;
    vocePerdeu();
    
}

}
