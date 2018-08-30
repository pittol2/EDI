#include <stdio.h>
#include <stdlib.h>
#include "matriz.h"

//Tipo matriz (tipo opaco)
//Estrutura interna do tipo deve ser definida na implementa��o do TAD
struct matriz {
	int linhas;
	int colunas; 
	int** mat;	
};

/*Inicializa uma matriz de nlinhas e ncolunas
* inputs: nlinhas (no de linhas) e ncolunas (no de colunas)
* output: ponteiro para a matriz inicializada
* pre-condicao: nlinhas e ncolunas diferentes de 0
* pos-condicao: matriz de retorno existe e contem nlinhas e ncolunas  
*/
Matriz* inicializaMatriz (int linhas, int colunas)
{
	Matriz* m = (Matriz*)malloc(sizeof(Matriz));
	m->linhas = linhas;
	m->colunas = colunas;
	m->mat = (int**)malloc(linhas*sizeof(int*));
	for (int i=0; i<linhas; i++)
		m->mat[i] = (int*)malloc(colunas*sizeof(int));
	return m;
}

/*Modifica o elemento [linha][coluna] da matriz mat
* inputs: a matriz, a linha, a coluna, e o novo elemento
* output: nenhum
* pre-condicao: matriz mat existe, linha e coluna s�o v�lidos na matriz
* pos-condicao: elemento [linha][coluna] da matriz modificado
*/
void modificaElemento (Matriz* mat, int linha, int coluna, int elem)
{
	mat->mat[linha][coluna] = elem;
}

/*Retorna o elemento mat[linha][coluna]
* inputs: a matriz, a linha e a coluna
* output: elemento mat[linha][coluna]
* pre-condicao: matriz mat existe, linha e coluna s�o v�lidos na matriz
* pos-condicao: mat n�o � modificada
*/
int recuperaElemento(Matriz* mat, int linha, int coluna)
{
	return mat->mat[linha][coluna];
}

/*Retorna o n�mero de colunas da matriz mat
* inputs: a matriz
* output: o n�mero de colunas da matriz
* pre-condicao: matriz mat existe
* pos-condicao: mat n�o � modificada
*/
int recuperaNColunas (Matriz* mat)
{
	return mat->colunas;
}

/*Retorna o n�mero de linhas da matriz mat
* inputs: a matriz
* output: o n�mero de linhas da matriz
* pre-condicao: matriz mat existe
* pos-condicao: mat n�o � modificada
*/
int recuperaNLinhas (Matriz* mat)
{
	return mat->linhas;
}

/*Retorna a matriz transposta de mat
* inputs: a matriz
* output: a matriz transposta
* pre-condicao: matriz mat existe
* pos-condicao: mat n�o � modificada e matriz transposta existe
*/
Matriz* transposta (Matriz* mat)
{
	Matriz* trp;
	int l = trp->linhas = mat->colunas;
	int c = trp->colunas = mat->linhas;
	for (int i=0; i<l; i++)
		for (int j=0; j<c; j++)
			trp->mat[i][j] = mat->mat[j][i];
	return trp;
}

/*Retorna a matriz multiplicacao entre mat1 e mat2
* inputs: as matrizes mat1 e mat2
* output: a matriz multiplica��o
* pre-condicao: matrizes mat1 e mat2 existem, e o numero de colunas de mat1 
* correponde ao numero de linhas de mat2 
* pos-condicao: mat1 e mat2 n�o s�o modificadas e a matriz multiplicacao existe
*/
Matriz* multiplicacao (Matriz* mat1, Matriz* mat2)
{
	Matriz* mult;
	int l = mult->linhas = mat1->linhas;
	int c = mult->colunas = mat2->colunas;
	for (int i=0; i<l; i++)
		for (int j=0; j<c; j++)
			mult->mat[i][j] = 0;
	for (int i=0; i<l; i++)
		for (int j=0; j<c; j++)
			mult->mat[i][j] += mat1->mat[i][j]*mat2->mat[j][i];
	return mult;
}

/*Imprime a matriz
* inputs: matriz mat
* output: nenhum
* pre-condicao: matriz mat existe  
* pos-condicao: nenhuma
*/
void imprimeMatriz(Matriz* mat)
{
	for (int i=0; i<mat->linhas; i++)
	{
		printf("\n");
		for (int j=0; j<mat->colunas; j++) 
			printf("%d ", mat->mat[i][j]);
	}
}

/*Libera mem�ria alocada para a matriz
* inputs: matriz mat
* output: nenhum
* pre-condicao: matriz mat existe  
* pos-condicao: toda a mem�ria alocada para matriz foi liberada
*/
void destroiMatriz(Matriz* mat)
{
	for (int i=0; i<mat->linhas; i++)
		free(mat->mat[i]);	
	free(mat->mat);
	free(mat);
}

//#endif /*MATRIZ_H_*/
