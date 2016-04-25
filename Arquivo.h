#ifndef ARQUIVO_H
#define ARQUIVO_H



//Abre o arquivo que contem o texto a ser lido
FILE *AbrirArquivoEntrada ();

// Cria o arquivo em que estará o indice remissivo
FILE *GeraArquivoSaida ();

//Escreve uma string no arquivo passado
void EscreveNoArquivo (FILE *arq, char palavra_linha[]);

// Dado um arquivo, retorna o vetor palavra (passado como argumento)
// preenchido com a primeira palavra encontrada e sua linha correspondente
char LerPalavra(FILE *arq, char palavra[]);



#endif
