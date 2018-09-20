/*
 * fila.c
 *
 *  Created on: 20 de set de 2018
 *      Author: 2018102206
 */

#include <stdio.h>
#include "fila.h"
#include "pilha.h"

#define MAXFILA 10;

/*Tipo que define a fila (tipo opaco)
  Estrutura interna do tipo deve ser definida na implementa��o do TAD. Usar como base o TAD Pilha (pilha.h) - n�o usar outra estrutura de dados

typedef struct fila Fila;*/
struct fila {
	Pilha* p1, p2;
};

/*Cria uma fila vazia, usando pilha
* inputs: nenhum
* output: fila alocada e vazia
* pre-condicao: nao tem
* pos-condicao: fila alocada e vazia*/
Fila* cria_fila(void) {
	Fila* f;
	f = (Fila*)malloc(sizeof(Fila));
	f->p1 = cria_pilha();
	f->p2 = cria_pilha();
	return f;
}

/*Insere uma pessoa na fila de Pessoas (lembre-se, fila e' FIFO). Imprime mensagem de erro caso a fila esteja cheia.
* inputs: pessoa a ser inserida na fila (do tipo pessoa) e a fila
* output: nenhum
* pre-condicao: pessoa e fila n�o s�o nulos
* pos-condicao: fila cont�m a pessoa inserida na ultima posi��o*/
void insere (Pessoa* pessoa, Fila* f) {
	if (f->p1->topo == 10/*MAXFILA*/) {
		printf("Fila Cheia!\n");
		return;
	}
	push(pessoa, f->p1);
}

/*Retira uma pessoa da fila (usando FIFO). Imprime mensagem de erro caso a fila esteja vazia.
* inputs: a fila
* output: a Pessoa (do tipo Pessoa) retirada da Fila (ou NULL, caso a fila esteja vazia)
* pre-condicao: fila n�o � nula
* pos-condicao: fila n�o cont�m a pessoa que estava na primeira posicao */
Pessoa* retira (Fila* f) {
	Pessoa* p;
	if (f->p1->topo == 0) {
			printf("Fila Vazia!\n");
			return NULL;
		}
	if (f->p1->topo == 1) {
			p = pop(f->p1);
			return p;
		}
	while (!vazia_pilha(f->p1))
		push(pop(f->p1),f->p2);
	p = pop(f->p2);
	while (!vazia_pilha(f->p2))
			push(pop(f->p2),f->p1);
	return p;
}

/*Imprime os dados de todos as pessoas da fila (do inicio ao fim da fila!). Imprime mensagem de fila vazia, caso a fila esteja vazia.
* inputs: a fila de pessoas
* output: nenhum
* pre-condicao: fila n�o � nula
* pos-condicao: dados dos pessoas impressos na saida padrao
*/
void imprime_fila (Fila* f) {
	imprime_pilha(f->p1);
	/*if (f->p1->topo == 0) {
			printf("Fila Vazia!\n");
			return;
		}
	for(int i=0; i<f->p1->topo; i++) {
		printf("Pessoa %d\n", i)
		printf("Nome : %s\n", f->p1->pp->nome);
		printf("End  : %s\n", f->p1->pp->end);
		printf("Idade: %d\n", f->p1->pp->idade);
		printf("-----------------------------\n")
	}*/
}

/*Verifica se a fila esta ou nao vazia
* inputs: a fila de pessoas
* output: 1 se estiver vazia e zero caso contrario
* pre-condicao: fila n�o � nula
* pos-condicao: nenhuma
*/
int vazia_fila (Fila* f) {
	return vazia_pilha(f->p1);
}

/*Separa a fila f de tal forma que as pessoas com idade maior que 60 sejam movidas para a fila "f_maiores" e as pessoas com idade menor que 60 para a fila "f_menores".
* inputs: a fila de pessoas, as filas f_maiores e f_menores (inicialmente vazias)
* output: nao tem
* pre-condicao: fila f n�o � nula
* pos-condicao: fila f vazia, pessoas com idade maior ou igual a 60 na fila "f_maiores" e as pessoas com idade menor que 60 para a fila "f_menores" */
void separa_filas (Fila* f, Fila* f_maiores, Fila* f_menores){
	if (vazia_fila(f)) {
		printf("Fila Vazia!\n");
		return;
	}
	if (!vazia_fila(f_maiores) && !vazia_fila(f_menores)) {
			printf("Fila_maiores e Fila_menores devem ser vazias!\n");
			return;
	}
	for(int i=0; i<f->p1->topo; i++) {
		if (idade(f->p1->pp[i]) >= 60)
			push(pop(f->p1),f_maiores->p2);
		else
			push(pop(f->p1),f_menores->p2);
	}
	while (!vazia_pilha(f_maiores->p2))
			push(pop(f_maiores->p2),f_maiores->p1);
	while (!vazia_pilha(f_menores->p2))
			push(pop(f_menores->p2),f_menores->p1);
	return;
}

/*Libera toda a mem�ria utilizada pelas estruturas de dados.
* inputs: a fila de pessoas
* output: NULL
* pre-condicao: fila f n�o � nula
* pos-condicao: Mem�ria liberada */
Fila* destroi_fila (Fila* f) {
	destroi_pilha(f->p1);
	destroi_pilha(f->p2);
	free(f);
	return f;
}
