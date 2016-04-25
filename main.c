#include <stdio.h>
#include <stdlib.h>

#include "arquivo.h"
#include "pilha.h"


int main(int argc, char const *argv[]) {

  //variáveis de controle da pilha
  camada *dado = iniciaCamada();
  pilha *p = iniciaPilha();
  //variáveis de controle dos arquivos
  FILE *arqEntrada = AbrirArquivoEntrada ();
  FILE *arqSaida = GeraArquivoSaida();
  //Variavel auxiliar
  char palavra[100];

  //Laço que escreve na Pilha a palavra e sua linha correspondente no arquivo
  while (!feof(arqEntrada) && !pilhaCheia(p)) {
    LerPalavra(arqEntrada, palavra);
    setPalavraLinha(dado, palavra);
    empilhar(dado, p);
  }
  //Desempilha-se uma vez aqui porque o ultimo termo lido estava sofrendo duplicata, caso a pilha nao estiver cheia
  if (!pilhaCheia(p)){desempilhar(p);}
  //Laço que escreve no Arquivo de Saida o Indice remissivo, apartir das palavras que preencheram a pilha
  while (!pilhaVazia(p)){
    desempilhar(p);
    //desmpilha-se antes de escrever porque o vetor de posição inicia do indice 0 e o topo possui um valor nulo quando não cheia a pilha
    getPalavraLinha(p, palavra);
    EscreveNoArquivo(arqSaida, palavra);
  }
  printf("%s\n", "FIM DA EXECUÇÃO DO PROGRAMA");

  return 0;
}
