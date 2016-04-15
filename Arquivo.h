#ifndef ARQUIVO_H
#define ARQUIVO_H

FILE *AbrirArquivoEntrada (char* nome); //Abre o arquivo que contem o texto a ser lido
FILE *GeraArquivoSaida (); // Cria o arquivo em que estará o indice remissivo

void EscreveNoArquivo(FILE *arq, char *palavra_linha);




#endif
