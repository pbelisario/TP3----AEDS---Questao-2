#include <stdio.h>
#include <stdlib.h>
#include "arquivo.h"


FILE *AbrirArquivoEntrada (){
  FILE *arqEntrada = fopen ("nome.txt", "r");
  if (arqEntrada == NULL){
    printf("%s\n", "Falha ao abrir o arquivo");
    //Termina o programa se não houver arquivo
    exit(1);
  }
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

char* itoa(int num, char numeroEmString[], int base, int i) {
    int ENegativo = 0;
    int i_inicial = i;
    //Caso 0, tratado de modo especial
    if (num == 0)
    {
        numeroEmString[(i+1)] = '0';
        numeroEmString[i] = '\0';
        return numeroEmString;
    }

    // Por padrão numeros negativos são tratados somente na
    // base 10. Para as outras formas não possuem sinal.
    if (num < 0 && base == 10)
    {
        ENegativo = 1;
        num = -num;
    }

    // Processamento individual dos digitos
    while (num != 0)
    {
        int aux = num % base;
        //Se o auxiliar for maior do que 9 soma-se a ele subtraido de 10 o valor ASCII de a
        //Caso contrario soma-se a ele o valor ASCII de 0
        numeroEmString[(i+1)] = (aux > 9)? (aux-10) + 'a' : aux + '0';
        num = num/base;
    }

    // se negativo adiona o menos
    if (ENegativo)
        numeroEmString[(i+1)] = '-';

    numeroEmString[i] = '\0'; //

    // como o numero esta escrito ao espelhado
    espelhar(numeroEmString, i, i_inicial);

    return numeroEmString;
}

void espelhar(char numero[], int TamanhoDoNumero, int Posicaoinicial){
    int inicio = Posicaoinicial;
    int fim = TamanhoDoNumero - 1;
    char aux;
    while (inicio < fim)
    {
        aux = numero[inicio];
        numero[inicio] = numero[fim];
        numero[fim] = aux;
        inicio++;
        fim--;
    }
}

char LerPalavra(FILE *arq, char palavra[]){
  //VARIAVEIS DE CONTROLE
  // Determina a Linha atual
  static int linha = 1;
  char linhaS[10]; //Caso o numero de linhas seja maior do que 10 essa string conterá o numero se ele possuir menos do que 10 posições
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
      // o finaliza, adicionando a linha em que está a tal palavra
      if (EFimDePalavra){
        palavra[index] = ' ';
        itoa(linha, palavra, 10, (index+1));
      }
      //Caso o caracter encontrado seja um <ENTER> passará de linha
      if (letra == '\n'){
        linha++;
      }
      // Retorna o vetor preenchido e com a linha atual atualizada
      // Optou-se por fazer duas comparações indenticas uma vez que,
      // dessa forma palavras que terminassem a linhas, não mais seriam
      // consideradas como da linha seguinte
      if(EFimDePalavra){
        return palavra;
      }
    }
    letra = fgetc (arq);
  }
}
