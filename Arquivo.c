#include <stdio.h>
#include <stdlib.h>
#include "Arquivo.h"
#include <string.h>


FILE *AbrirArquivoEntrada (char *nome){
  strcat(nome, ".txt");
  FILE *arq = fopen (nome, "r");
}

FILE *GeraArquivoSaida (){
  FILE *arq = fopen ("SAIDA.txt", "w");
}

void EscreveNoArquivo (FILE *arq, char *palavra_linha){
  fprintf(arq, "%s\n", palavra_linha);
}

char *LerPalavra(FILE *arq){
  static int linha = 1;
  char* palavra;
  char letra = fgetc (arq);
  while (letra != EOF){
    //          NUMEROS DE 0 a 9        LETRAS MAIUSCULAS       LETRAS MINUSCULAS
    if (letra > 47 || letra < 58 || letra > 64 || letra < 91 || letra > 96 || letra < 123){
      strcat(palavra, letra);
    }else if (letra == '\n'){
      strcat (palavra, (char) linha);
      linha++;
      return palavra;
    }else{
      strcat (palavra, (char) linha);
      return palavra;
    }
    letra = fgetc (arq);
  }
}
