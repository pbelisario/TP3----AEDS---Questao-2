#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Arquivo.h"


FILE *AbrirArquivoEntrada (){
  FILE *arqEntrada = fopen ("nome.txt", "r");
  if (arqEntrada == NULL){printf("%s\n", "Falha ao abrir o arquivo");}
  else {
    printf("%s\n", "Arquivo aberto com sucesso");
    return arqEntrada;
  }
}

FILE *GeraArquivoSaida (){
  FILE *arqSaida = fopen ("SAIDA.txt", "w");
  return arqSaida;
}

void EscreveNoArquivo (FILE *arq, char palavra_linha[]){
  fprintf(arq, "%s\n", palavra_linha);
}


char LerPalavra(FILE *arq, char palavra[]){
  //VARIAVEIS DE CONTROLE
  // Determina a Linha atual
  static int linha = 1;
  // Diz se já se pode terminar a palavra
  int EFimDePalavra = 0;
  // Indice do vetor palavra recebido como argumente
  int index = 0;
  // Caracter a ser analizado para formar uma palavra
  int letra = fgetc (arq);
  // FUNÇÃO EM SI
  // Percorre o arquivo analisando-o de letra em letra concatenando-as ou não,
  // seguindo o parametro em que demarcador de palvra é tudo aquilo que
  // for diferente das 26 letras do alfabeto(de A ate Z) e dos numeros de 0 a 9
  while (letra != EOF){
    // Nessa primeira Condição tem-se como objetivo concatenar as letras para formar uma palavra
    if ((letra >= 'a' && letra <= 'z') || (letra >= 'A' && letra <= 'Z') || (letra >= '0' && letra <= '9')){
        palavra[index] = letra;
        index++;
        EFimDePalavra = 1;
    }else{
      // Caso ja tenha colocado ao menos uma letra no vetor palavra,
      // o finaliza, adicionando a linha em que está a tal palavra  e demarcarndo o fim dele (\0)
      if (EFimDePalavra){
        palavra[index] = ' ';
        palavra[(index + 1)] = (char) (linha + 47);
        palavra[(index + 2)] = ' ';
        palavra[(index + 3)] = '\0';
      }
      //Caso o caracter encontrado seja um <ENTER> passará de linha
      if (letra == '\n'){
        linha++;
      }
      // Retorna o vetor preenchido e com a linha atual atualizada
      // Optou-se por fazer duas compaações indenticas uma vez que,
      // dessa forma palavras que terminassem a linhas, não mais seriam
      // consideradas como da linha seguinte
      if(EFimDePalavra){
        return palavra;
      }
    }
    letra = fgetc (arq);
  }
}
