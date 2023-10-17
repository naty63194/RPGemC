void evento09(){
    printf("Os seus sistemas detectam um novo planeta. \n");
    printf("Esse planeta é Grande e de coloração acizentada \n");
    printf("e não possui satélites naturais. \n");

    do{
      exibeStatusAtual();
      printf("Com essas informações analise as suas opções e decida a sua próxima ação: \n");
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
    if (escolha == 1){
      printf("Sua análise está equivocada e esse planeta não possui condições de abrigar a espécie humana. \n");
      printf("Sua missão falhou\n");
        perdeu = 1;
        vocePerdeu();
      }
    else if (escolha == 3){
      mostraLinha();
      gastaCombustivel(10);
      
    }
  }
