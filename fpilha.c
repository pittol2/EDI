/*
 * pilha.c
 *
 *  Created on: 20 de set de 2018
 *      Author: 2018102206
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pilha.h"

#define MAXTAM 10

/*TipoItem Pessoa (tipo opaco). Contem campos:
  - nome (string)
  - idade (int)
  - endereco (string)

typedef struct pessoa Pessoa;*/
struct pessoa {
	char* nome;
	int idade;
	char* end;
};

/*Tipo que define a Pilha (tipo opaco)
  Atencao: Esta pilha pode conter ate 10 Pessoas

typedef struct pilha Pilha;*/
struct pilha {
	int topo;
	Pessoa* pp[MAXTAM];
};

/*Inicializa a Pilha
* inputs: nenhum
* output: P (a pilha criada)
* pre-condicao: nenhuma
* pos-condicao: P est� definida e vazia
*/
Pilha* cria_pilha() {
	Pilha* p;
	p = (Pilha*)malloc(sizeof(Pilha)); //maloca pilha
	p->topo = 0;
	//p->pp = (Pessoa*)malloc(MAXTAM*sizeof(Pessoa)); //maloca vetor da pilha
	return p;
}

/*Insere uma pessoa no topo da pilha (se houver espaco)
* inputs: P (uma pilha) e E (uma pessoa)
* output: nenhum
* pre-condicao: P incializada e com espaco para o elemento.
* pos-condicao: Ao final da fun��o, a pilha tem E como o elemento
do topo
*/
void push(Pessoa* pessoa, Pilha* pilha) {
	if (pilha->topo == MAXTAM) {
		printf("pilha cheia\n");
		return;
	}
	pilha->pp[pilha->topo] = pessoa;
	pilha->topo++;
	return;
}

/*Retira uma Pessoa do topo da Pilha (se pilha n�o vazia)
* inputs: a Pilha
* output: a pessoa retirada do topo da pilha
* pre-condicao: Pilha n�o � nula e n�o � vazia
* pos-condicao: pilha n�o cont�m o elemento retirado do topo
*/
Pessoa* pop(Pilha* pilha) {
	if (pilha->topo == 0) {
		printf("pilha vazia\n");
		return NULL;
	}
	else {
		pilha->topo--;
		return pilha->pp[pilha->topo];
	}
}

/*Imprime as pessoas da pilha
 * inputs: a pilha
 * output: nenhum
 * pre-condicao: pilha P n�o vazia
 * pos-condicao: Pilha permanece inalterada
 */
void imprime_pilha (Pilha* pilha) {
	if (pilha->topo == 0) {
		printf("pilha vazia\n");
		return;
	}
	for(int i=0; i<pilha->topo; i++) {
		printf("Nome: %s\n", pilha->pp[i]->nome);
		printf("Idade: %d\n", pilha->pp[i]->idade);
		printf("Endereço: %s\n", pilha->pp[i]->end);
		printf("-----------------------------\n");
	}
	return;
}

/*Libera a memoria ocupada pela pilha
* inputs: a Pilha
* output: NULL
* pre-condicao: Pilha n�o � nula
* pos-condicao: Toda memoria eh liberada
*/
Pilha* destroi_pilha(Pilha* pilha) {
	//free(pilha->pp);
	free(pilha);
	return pilha;
}

/*Inicializa um TipoItem Pessoa
* inputs: o nome, a idade e o endereco da pessoa
* output: um ponteiro para o tipo item criado
* pre-condicao: nome, idade e endereco validos
* pos-condicao: tipo item criado, com os campos nome, idade e endereco copiados
*/
Pessoa* inicializaPessoa(char* nome, int idade, char* endereco) {
	Pessoa* p = (Pessoa*)malloc(sizeof(Pessoa));
	p->nome = (char*)malloc((strlen(nome)+1)*sizeof(char));
	strcpy(p->nome,nome);
	p->end = (char*)malloc((strlen(endereco)+1)*sizeof(char));
	strcpy(p->end,endereco);
	p->idade = idade;
	return p;
}

/*Verifica se a pilha está vazia
* inputs: a Pilha
* output: 1 (Pilha vazia) ou 0 (Pilha nao-vazia)
* pre-condicao: Pilha P nao vazia
* pos-condicao: Pilha permanece inalterada
*/
int vazia_pilha(Pilha* p) {
	if (p->topo == 0) return 1;
	else return 0;
}

/*Retorna a idade da pessoa
* inputs: E (a pessoa)
* output: a idade da pessoa
* pre-condicao: pessoa alocada na fila
* pos-condicao: Pilha permanece inalterada
*/
int idade(Pessoa* p) {
	return p->idade;
}


//#endif /* PILHA_H_ */

