#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Arquivo.h"
#include "pilha.h"


int main(int argc, char const *argv[]) {

  //variáveis de controle da pilha
  camada *dado = iniciaCamada();
  pilha *p = iniciaPilha();
  //variáveis de controle dos arquivos
  FILE *arqEntrada = AbrirArquivoEntrada ();
  FILE *arqSaida = GeraArquivoSaida();

  //Laço que escreve na Pilha a palavra e sua linha correspondente no arquivo
  while (!feof(arqEntrada) && !pilhaCheia(p)) {
    LerPalavra(arqEntrada, dado->palavra_linha );
    empilhar(dado, p);
  }

  //Laço que escreve no Arquivo de Saida o Indice remissivo, apartir das palavras que preencheram a pilha
  while (!pilhaVazia(p)){
    desempilhar(p);
    //desmpilha-se antes de escrever porque o vetor de posição inicia do indice 0
    EscreveNoArquivo(arqSaida, (p->posicoes[p->topo]).palavra_linha);

  }


  return 0;
}
