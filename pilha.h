#ifndef PILHA_H
#define PILHA_H

typedef struct Camada camada;
typedef struct Pilha pilha;

pilha* iniciaPilha(void);
//inicia a pilha
camada* iniciaCamada(void);
//cria uma camada (contem posicao)
void empilhar (camada*,pilha*);
//empilha uma posicao, verificando se esta cheia
void desempilhar(pilha*);
//desempilha um elemento da pilha, verificando se esta vazia
int pilhaVazia(pilha*);
//verifica se a pilha está vazia
int pilhaCheia(pilha*);
//verifica se a pilha está cheia
void getPalavraLinha(pilha *p, char palavra[]);
//Escreve em um vetor auxiliar (palavra) o palavra da camada atual  da pilha
void setPalavraLinha(camada *c, char palavra[]);
//Escreve em uma camada à ser empilhada o vetor auxiliar (palavra)

#endif
