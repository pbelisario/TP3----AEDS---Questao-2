#include <stdio.h>
#include <stdlib.h>
#include "Arquivo.c"



int main(int argc, char const *argv[]) {
  File *arq;
  arq = AbrirArquivoEntrada (nome);
  printf("%s\n", LerPalavra(arq) );
  return 0;
}
