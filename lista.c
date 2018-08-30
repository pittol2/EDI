/*
 * lista.c
 *
 *  Created on: 30 de ago de 2018
 *      Author: 2018102206
 */

#include <stdio.h>
#include "lista.h"

/*TipoItem Aluno (tipo opaco)
  Estrutura interna do tipo deve ser definida na implementa��o do TAD. Devem ser definidos campos:
  - nome (string)
  - matricula (int)
  - endereco (string)
  typedef struct tipoitem TipoItem;
  */
struct tipoitem {
	char* nome;
	char* end;
	int mat;
};

typedef struct cel Celula;
struct cel {
	TipoItem* aluno;
	Celula* prox;
};

/*Tipo que define a lista (tipo opaco)
  Estrutura interna do tipo deve ser definida na implementa��o do TAD.
  Usar lista COM Sentinela
  typedef struct tipolista TipoLista;
  */
struct tipolista {
	Celula* prim;
	Celula* ult;
};

/*Inicializa o sentinela de uma lista
* inputs: nenhum
* output: Sentinela inicializado
* pre-condicao: nenhuma
* pos-condicao: sentinela da lista de retorno existe e os campos primeiro e ultimo apontam para NULL
*/
TipoLista* InicializaLista() {
	TipoLista* lista = (TipoLista*)malloc(sizeof(TipoLista));
	lista->prim = lista->ult = NULL;
	return lista;
}

/*Insere um aluno na primeira posi��o da lista de alunos
* inputs: aluno a ser inserido na lista (do tipo TipoItem) e a lista
* output: nenhum
* pre-condicao: aluno e lista n�o s�o nulos
* pos-condicao: lista cont�m o aluno inserido na primeira posi��o
*/
void Insere (TipoItem* aluno, TipoLista* lista) {
	Celula* cel = (Celula*)malloc(sizeof(Celula));
	cel->aluno = aluno;
	(lista->ult == NULL) ? cel->prox = NULL : cel->prox = lista->prim;
	lista->prim = cel;
	if (lista->ult == NULL) lista->ult = cel;
}

/*Retira um aluno de matr�cula mat da lista de alunos
* inputs: a lista e a matr�cula do aluno a ser retirado da lista
* output: o aluno (do tipo TipoItem) retirado da lista ou NULL, se o aluno n�o se encontrar na lista
* pre-condicao: lista n�o � nula
* pos-condicao: lista n�o cont�m o aluno de matr�cula mat
*/
TipoItem* Retira (TipoLista* lista, int mat){
	//if (lista->prim == NULL) return NULL;
	Celula* celant, cel;
	celant->prox = lista->prim;
	cel = celant->prox;
	while (celant->prox != NULL) { //para caso celant eh o ultimo da lsita.
		if (cel->aluno->mat == mat) { //se encontra a matricula em cel
			if (lista->prim == cel)      //se eh o primeiro da lista:
				lista->prim = cel->prox; // o primeiro da lsita passa a ser o proximo aluno
			if (lista->ult == cel) { //se eh o ultimo da lista:
				lista->ult = celant; //o ultimo apssa a ser o anterior,
				celant->prox = NULL; //o ultimo aluno recebe NULL no prox
			}
			else  //caso nao seja o ultimo aluno:
				celant->prox = cel->prox;  //celant passa a apontar para o proximo da lista
			free(cel);
			return cel->aluno;
		}
		else { //se nao encontrar a matricula em cel
			celant = cel; //celant anda 1 para frente
			cel = cel->prox; //cel anda 1 para frente
		}
	}
	return NULL;
}

/*Libera toda a mem�ria alocada para a lista (lembre-se de tambem liberar a memoria para o aluno)
* inputs: a lista encadeada de alunos
* output: Lista vazia (NULL)
* pre-condicao: lista n�o � nula
* pos-condicao: mem�ria alocada � liberada
*/
TipoLista* Libera (TipoLista* lista) {
	Celula* p = lista->prim;
	Celula* temp;
	while (p != NULL) {
		temp = lista->prim;
		free(p->)
	}
}

/*Inicializa um TipoItem aluno
* inputs: o nome, a matricula e o endereco do aluno
* output: um ponteiro para o tipo item criado
* pre-condicao: nome, matricula e endereco validos
* pos-condicao: tipo item criado, com os campos nome, matricula e endereco copiados
*/
TipoItem* InicializaTipoItem(char* nome, int matricula, char* endereco) {
	TipoItem* aluno = (TipoItem*)malloc(sizeof(TipoItem));
	aluno->nome = (char*)malloc((srtlen(nome)+1)*sizeof(char));
	strcpy(aluno->nome,nome);
	aluno->end = (char*)malloc((strlen(endereco)+1)*sizeof(char*));
	strcpy(aluno->end,endereco);
	aluno->mat = matricula;
	return aluno;
}

