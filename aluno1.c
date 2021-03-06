// #################################################
//  Instituto Federal da Bahia
//  Salvador - BA
//  Curso de Análise e Desenvolvimento de Sistemas http://ads.ifba.edu.br
//  Disciplina: INF029 - Laboratório de Programação
//  Professor: Renato Novais - renato@ifba.edu.br

//  ----- Orientações gerais -----
//  Descrição: esse arquivo deve conter as questões do trabalho do aluno.
//  Cada aluno deve renomear esse arquivo para Aluno<MATRICULA>.c
//  O aluno deve preencher seus dados abaixo, e implementar as questões do trabalho

//  ----- Dados do Aluno -----
//  Nome: Igor Alexandre de Lima
//  email: igoralwork@gmail.com
//  Matrícula: 2017216017
//  Semestre: 2018.1

//  Copyright © 2016 Renato Novais. All rights reserved.
// Última atualização: 20/06/2018 - 19/08/2016

// #################################################

#include <stdio.h>
#include <stdlib.h>
#include<string.h>

void puxardatas();
/*
## função utilizada para testes  ##


/*
 Q1 = validar data
@objetivo
    Validar uma data
@entrada
    uma string data. Formatos que devem ser aceitos: dd/mm/aaaa, onde dd = dia, mm = mês, e aaaa, igual ao ano. dd em mm podem ter apenas um digito, e aaaa podem ter apenas dois digitos.
@saida
    0 -> se data inválida
    1 -> se data válida
 */
int q1(char *data){
  int datavalida = 1, datainvalida = 0;
  char dd[3], mm[3], aa[5];
  int dia, mes, ano, tam_dia=0, tam_mes=0, tam_ano=0, i, j, x, a;

  i=0;
  while(data[i] > 47){ //Puxar dia
    dd[i]=data[i];
    i++;
  }
  dd[i]='\0';
  while(dd[tam_dia] != '\0'){
    tam_dia++;
  }

  j=0;
  i=tam_dia+1;
  while(data[i] > 47){ //Puxar mês
    mm[j] = data[i];
    j++;
    i++;
  }
  mm[j]='\0';
  while(mm[tam_mes] != '\0'){ 
    tam_mes++;
  }

  j=0;
  x=tam_mes+tam_dia+2;

  while(data[x] != '\0'){ //Puxar ano
    aa[j] = data[x];
    j++;
    x++;
  }

  a=0;
  while(aa[a] != '\0'){
    a++;
  }
  aa[j]='\0';
  //transformar char em int
  dia = atoi(dd);
  mes = atoi(mm);
  ano = atoi(aa);
  
  //validação das datas
  if((mes >= 1 && mes <= 12) && (dia >= 1 && dia <= 31) && (ano >= 10 && ano <= 9999)){
    if((mes == 1 || mes == 3 || mes == 5 || mes == 7 || mes == 8 || mes == 10 || mes == 12) && (dia >= 1 && dia <= 31)){
      return datavalida;
    }
    else if((mes == 4) || (mes == 6) || (mes == 9) || (mes == 11) && (dia >= 1 && dia <= 30)){
      return datavalida;
    }
    else if(dia==29 && mes==2 && (ano%400==0 || (ano%4 == 0 && ano%100 != 0))){
      return datavalida;
    }
    else if(mes == 2 && (dia >= 1 && dia <= 28)){
      return datavalida;
    }
  else
    return datainvalida;
  }
  else
    return datainvalida;
}

/*
 Q2 = diferença entre duas datas
 @objetivo
    Calcular a diferença em anos, meses e dias entre duas datas
 @entrada
    uma string datainicial, uma string datafinal. Além disso, a função tem três parâmetros qtdDias, qtdMeses e qtdAnos. Esses três parâmetros devem ser utilizados para guardar os resultados dos cálculos. Na chamada da função deve passar o valor -1 para os três
 @saida
    1 -> cálculo de diferença realizado com sucesso
    2 -> datainicial inválida
    3 -> datafinal inválida
    4 -> datainicial > datafinal
 */

//puxarDatas é uma função para devolver os valores dia, mes e ano das variáveis datainicial e datafinal
void puxarDatas(char *data, int *dia, int *mes, int *ano){
  char dd[3], mm[3], aa[5];
  int tam_dia=0, tam_mes=0, tam_ano=0, i, j, x, a; //i, j, x, a servem como auxiliares para puxar dia, mes e ano como foi feito na Q1

  i=0;
  while(data[i] > 47){
    dd[i]=data[i];
    i++;
  }
  dd[i]='\0';
  while(dd[tam_dia] != '\0'){
    tam_dia++;
  }

  j=0;
  i=tam_dia+1;
  while(data[i] > 47){
    mm[j] = data[i];
    j++;
    i++;
  }
  mm[j]='\0';
  while(mm[tam_mes] != '\0'){
    tam_mes++;
  }

  j=0;
  x=tam_mes+tam_dia+2;

  while(data[x] != '\0'){
    aa[j] = data[x];
    j++;
    x++;
  }

  a=0;
  while(aa[a] != '\0'){
    a++;
  }
  aa[j]='\0';

  *dia = atoi(dd);
  *mes = atoi(mm);
  *ano = atoi(aa);
}

int q2(char *datainicial, char *datafinal, int *qtdDias, int *qtdMeses, int *qtdAnos){
    /*nDias = nDias;
    nMeses = nMeses;
    nAnos = nAnos;*/

    int dia=0, mes=0, ano=0;
    int nDias, nMeses, nAnos;
    int x;
    char dd[2], mm[2], aa[4];
    int diainicial, mesinicial, anoinicial;
    int diafinal, mesfinal, anofinal;
    int calculovalido = 0;

    //se a data for valida, puxa dia, mes e ano de datainicial, se não retorna 2(datainicial invalida)
    if(q1(datainicial) == 1){ 
      puxarDatas(datainicial, &dia, &mes, &ano);
      diainicial = dia;
      mesinicial = mes;
      anoinicial = ano;
    }
    else
      return 2;

    //se a data for valida, puxa dia, mes e ano de datafinal, se não retorna 3(datafinal invalida)
    if(q1(datafinal) == 1){
      puxarDatas(datafinal, &dia, &mes, &ano);
      diafinal = dia;
      mesfinal = mes;
      anofinal = ano;
    }
    else return 3;

    //se data inicial for maior que datafinal retorna 4
    if((anoinicial > anofinal) || (anoinicial == anofinal && ((mesinicial > mesfinal) ||  ((mesinicial == mesfinal) && (diainicial > diafinal))))){
        return 4;
    }

    //se data e calculo de diferença forem valido retorna calculovalido = 1
    else{
    nAnos = anofinal - anoinicial;
    if(mesfinal >= mesinicial){
      nMeses = mesfinal - mesinicial;
      if(diafinal >= diainicial){
        nDias = diafinal - diainicial;
      }
      else if(diafinal < diainicial){
        nDias = diainicial - diafinal;
        nMeses = nMeses -1;
        if(((anofinal%400==0 || (anofinal%4 == 0 && anofinal%100 != 0)) && (anoinicial%400==0 || (anoinicial%4 == 0 && anoinicial%100 != 0))) || ((anofinal%400==0 || (anofinal%4 == 0 && anofinal%100 != 0)) && (anoinicial%400!=0 || (anoinicial%4 != 0 && anoinicial%100 == 0)))){
          if((mesfinal==2) || (mesinicial==2)){
            nDias = 29 - nDias;
          }
          else if(((mesfinal == 4) || (mesfinal == 6) || (mesfinal == 9) || (mesfinal == 11)) || ((mesinicial == 4) || (mesinicial == 6) || (mesinicial == 9) || (mesinicial == 11))){
            nDias = 30 - nDias;
          }
          else if((mesfinal == 1 || mesfinal == 3 || mesfinal == 5 || mesfinal == 7 || mesfinal == 8 || mesfinal == 10 || mesfinal == 12) || (mesinicial == 1 || mesinicial == 3 || mesinicial == 5 || mesinicial == 7 || mesinicial == 8 || mesinicial == 10 || mesinicial == 12)){
            nDias = 31 - nDias;
          }
        }
        else{
          if((mesfinal == 2) || (mesinicial == 2)){
            nDias = 28 - nDias;
          }
          else if(((mesfinal == 4) || (mesfinal == 6) || (mesfinal == 9) || (mesfinal == 11)) || ((mesinicial == 4) || (mesinicial == 6) || (mesinicial == 9) || (mesinicial == 11))){
            nDias = 30 - nDias;
          }
          else if((mesfinal == 1 || mesfinal == 3 || mesfinal == 5 || mesfinal == 7 || mesfinal == 8 || mesfinal == 10 || mesfinal == 12) || (mesinicial == 1 || mesinicial == 3 || mesinicial == 5 || mesinicial == 7 || mesinicial == 8 || mesinicial == 10 || mesinicial == 12)){
            nDias = 31 - nDias;
          }
      }
    }
    else if(mesfinal < mesinicial){
      nMeses = mesinicial - mesfinal;
      nAnos = nAnos - 1;
      nMeses = 12 - nMeses;
      if(diafinal >= diainicial){
        nDias = diafinal - diainicial;
      }
      else if(diafinal < diainicial){
        nDias = diainicial - diafinal;
        nMeses = nMeses -1;
        if(((anofinal%400==0 || (anofinal%4 == 0 && anofinal%100 != 0)) && (anoinicial%400==0 || (anoinicial%4 == 0 && anoinicial%100 != 0))) || ((anofinal%400==0 || (anofinal%4 == 0 && anofinal%100 != 0)) && (anoinicial%400!=0 || (anoinicial%4 != 0 && anoinicial%100 == 0)))){
          if((mesfinal==2) || (mesinicial==2)){
            nDias = 29 - nDias;
          }
          else if((((mesfinal == 4) || (mesfinal == 6) || (mesfinal == 9) || mesfinal == 11)) || ((mesinicial == 4) || (mesinicial == 6) || (mesinicial == 9) || (mesinicial == 11))){
            nDias = 30 - nDias;
          }
          else if((mesfinal == 1 || mesfinal == 3 || mesfinal == 5 || mesfinal == 7 || mesfinal == 8 || mesfinal == 10 || mesfinal == 12) || (mesinicial == 1 || mesinicial == 3 || mesinicial == 5 || mesinicial == 7 || mesinicial == 8 || mesinicial == 10 || mesinicial == 12)){
            nDias = 31 - nDias;
          }
        }
        else{
          if((mesfinal == 2) || (mesinicial == 2)){
            nDias = 28 - nDias;
          }
          else if(((mesfinal == 4) || (mesfinal == 6) || (mesfinal == 9) || (mesfinal == 11)) || ((mesinicial == 4) || (mesinicial == 6) || (mesinicial == 9) || (mesinicial == 11))){
            nDias = 30 - nDias;
          }
          else if((mesfinal == 1 || mesfinal == 3 || mesfinal == 5 || mesfinal == 7 || mesfinal == 8 || mesfinal == 10 || mesfinal == 12) || (mesinicial == 1 || mesinicial == 3 || mesinicial == 5 || mesinicial == 7 || mesinicial == 8 || mesinicial == 10 || mesinicial == 12)){
            nDias = 31 - nDias;
          }
        }
    }
    }
  } 
    calculovalido = 1;
  } 
  //se calculovalido retornar 1, é devolvido a diferença(dia, mes e ano) do cálculo
  if(calculovalido ==1){
    *qtdDias = nDias;
    *qtdMeses = nMeses;
    *qtdAnos = nAnos;
    return 1;
  } 
 }


/*
 Q3 = encontrar caracter em texto
 @objetivo
    Pesquisar quantas vezes um determinado caracter ocorre em um texto
 @entrada
    uma string texto, um caracter c e um inteiro que informa se é uma pesquisa Case Sensitive ou não. Se isCaseSensitive = 1, a pesquisa deve considerar diferências entre maiúsculos e minúsculos.
        Se isCaseSensitive != 1, a pesquisa não deve  considerar diferências entre maiúsculos e minúsculos.
 @saida
    Um número n >= 0.
 */
int q3(char *texto, char c, int isCaseSensitive){
  char t[250];
  int tam_texto = 0, qnt_ocorrencias = 0;
  	
  if(isCaseSensitive == 1){
  while(texto[tam_texto]!='\0'){
    if(texto[tam_texto] == c){
    qnt_ocorrencias++; 
    }
  tam_texto++;
  }
  return qnt_ocorrencias; //retorna número de ocorrências do caracter buscado
  }

  else
  while(texto[tam_texto]!='\0'){  //verifica se o caracter é igual a ele ou sua varição(minúscula/maiúscula) pela tabela ascii
     if((texto[tam_texto] == c) || (texto[tam_texto] == c + 32) || (texto[tam_texto] == c - 32)){
     qnt_ocorrencias++;
    }
  tam_texto++;
  }
  return qnt_ocorrencias; //retorna numero de ocorrências do caracter buscado
}

/*
 Q4 = encontrar palavra em texto
 @objetivo
    Pesquisar todas as ocorrências de uma palavra em um texto
 @entrada
    uma string texto base (strTexto), uma string strBusca e um vetor de inteiros (posicoes) que irá guardar as posições de início e fim de cada ocorrência da palavra (strBusca) no texto base (texto).
 @saida
    Um número n >= 0 correspondente a quantidade de ocorrências encontradas.
    O vetor posicoes deve ser preenchido com cada entrada e saída correspondente. Por exemplo, se tiver uma única ocorrência, a posição 0 do vetor deve ser preenchido com o índice de início do texto, e na posição 1, deve ser preenchido com o índice de fim da ocorrencias. Se tiver duas ocorrências, a segunda ocorrência será amazenado nas posições 2 e 3, e assim consecutivamente. Suponha a string "Instituto Federal da Bahia", e palavra de busca "dera". Como há uma ocorrência da palavra de busca no texto, deve-se armazenar no vetor, da seguinte forma:
        posicoes[0] = 13;
        posicoes[1] = 16;
        Observe que o índice da posição no texto deve começar ser contado a partir de 1.
        O retorno da função, n, nesse caso seria 1;

 */
int q4(char *strTexto, char *strBusca, int posicoes[30]){
   int qtdOcorrencias = 0;
  int i, j, tam_palavra = 0, verificador_repeticao, cont_posicao = -2, cont_repeticao = 0, cont_acento=0;

  while(strBusca[tam_palavra] != '\0'){
    tam_palavra++;
  }
  
  for(i = 0; strTexto[i]!='\0'; i++){
    if(strTexto[i]==-95 || strTexto[i]==-87 || strTexto[i]==-83 || strTexto[i]==-77 || strTexto[i]==-70 || strTexto[i]==-93 || strTexto[i]==-89 || strTexto[i]==-76)
       cont_acento++; //Contagem de caracteres com acento
    if(strBusca[0] == strTexto[i]){
      verificador_repeticao = 1; //Verifica se tem ocorrência da palavra no texto
      for(j = 0; j < tam_palavra; j++){
        if(strBusca[j] != strTexto[i + j]){
          verificador_repeticao = 0; //Caso não tenha ocorrência o retorno sera 0
          break;
        }
      }
      if(verificador_repeticao == 1){ //Caso tenha ocorrência ele ira contar o número de repeticões, a posicão onde comeca e onde finaliza
        cont_repeticao++;
        cont_posicao = cont_posicao + 2;
        qtdOcorrencias = cont_repeticao;
        posicoes[cont_posicao] = i + 1 - cont_acento; //posicão inicial, caso tenha acento ele ira retirar o excesso
        posicoes[cont_posicao+1] = i + tam_palavra - cont_acento; //posicão final, caso tenha acento ele ira retirar o excesso
      }
    }   
  } 
    return qtdOcorrencias;
}

/*
 Q5 = inverte número
 @objetivo
    Inverter número inteiro
 @entrada
    uma int num.
 @saida
    Número invertido
 */

int q5(int num){
    int inverso = 0, guard;

    while(num > 0) { //enquanto for maior que 0, o número sera dividido e seu resto sera jogado numa variável que multiplicara seu valor por 10 a cada loop 
        guard = num % 10;
        inverso = inverso * 10 + guard;
        num /= 10;
    }
    return inverso; //retorna o numero invertido
}

/*
 Q6 = ocorrência de um número em outro
 @objetivo
    Verificar quantidade de vezes da ocorrência de um número em outro
 @entrada
    Um número base (numerobase) e um número de busca (numerobusca).
 @saida
    Quantidade de vezes que número de busca ocorre em número base
 */

int q6(int numerobase, int numerobusca){
  int guard_numero, qtdOcorrencias = 0;
  int tamanho = 1;

  guard_numero = numerobusca; 

  while(guard_numero != 0){ //Enquanto K(numerobusca) for diferente de zero ele sera dividido para calcular seu tamanho
  tamanho = tamanho * 10;
  guard_numero = guard_numero / 10;
}
  guard_numero = numerobase;

  while(guard_numero != 0){
    if(guard_numero % tamanho == numerobusca){ //Verifica se o resto da divisao do numero(numerobase) é igual a K(numerobusca) 
      qtdOcorrencias++;
      guard_numero = guard_numero / tamanho;
    }
    else
      guard_numero = guard_numero / 10;
  }
  return qtdOcorrencias;
}
