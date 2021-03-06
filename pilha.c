#include <stdio.h>
#include <stdlib.h>

#include "pilha.h"
#define TAM 10

struct Camada{
  char palavra_linha[100]; //Armazena a palavra e a linha lidas à pilha
};

struct Pilha{
	camada posicoes[TAM]; //Tamanho da pilha
	int topo; //A ultima posição da pilha
};

pilha* iniciaPilha() {
	pilha* p = (pilha*) malloc (sizeof(pilha));
  p->topo = 0;
	return p;
}

camada* iniciaCamada() {
	camada* c = (camada*) malloc (sizeof(camada));
	return c;
}

int pilhaVazia(pilha* p){
	if(p->topo == 0){
		printf("Pilha vazia!\n");
		return 1;
	}
	return 0;
}

int pilhaCheia(pilha* p){
	if(p->topo == TAM){
		printf("Pilha cheia!\n");
		return 1;
	}
	return 0;
}

void empilhar(camada* c, pilha* p){
	if(pilhaCheia(p)){
		return;
	}
	p->posicoes[p->topo] = *c;
	p->topo++;
}

void desempilhar(pilha* p){
	if(pilhaVazia(p)){
		return;
	}
	p->topo--;
}

void getPalavraLinha(pilha *p, char palavra[]){
  int i = 0;
  for (i = 0; (p->posicoes[p->topo]).palavra_linha[i] != '\0'; i++){
    palavra[i] = (p->posicoes[p->topo]).palavra_linha[i];
  }
  palavra[i] = '\0';
}

void setPalavraLinha(camada *c, char palavra[]){
  int i;
  for (i = 0; palavra[i] != '\0'; i++){
    (c)->palavra_linha[i] = palavra[i];
  }
  (c)->palavra_linha[i] = '\0';
}
