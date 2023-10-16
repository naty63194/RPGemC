//Evento03: próximo planeta 
int Evento03(int escolha, int possuiSondas, int perdeu, int sondas){
  printf("Viajando pelo espaço profundo em direção a um destino desconhecido.\n");
  printf("Você detecta um planeta gigante, coberto por nuvens brancas e envolto por um azul profundo e cintilante.\n");
  
  do{
    exibeStatusAtual();
    printf("Você analisa a situação e começa a calcular qual a melhor decisão: \n");
    printf("1) Pousar nesse Planeta. \n");
    printf("2) Enviar uma sonda para obter mais informações. \n");
    printf("3) Seguir a viagem e procurar por outro planeta. \n");
    escolha = verificaEscolha(3);
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
      perdeu = 1;
    }
}

    
