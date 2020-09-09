/*
 * calculos.c
 *
 *  Created on: 7 sep. 2020
 *      Author: Cristian Barraza
 */
/**/
#include <stdio.h>
#include <stdio_ext.h>
#include <stdlib.h>
#include <ctype.h>

int validarmenu(int* vresultado,char* mensajeError){
	int retorno = -1;
	int buffer;
	if(vresultado != NULL && mensajeError != NULL)
	{

		scanf("%d", &buffer);
		__fpurge(stdin);
		if(buffer >0 && buffer <=5){
		*vresultado = buffer;
		retorno=0;
		}else{
			printf("%s",mensajeError);
			getchar();
			};
		}


	return retorno;
};

int sumar(int a,int b)
{
    int sum;
    sum = a + b;
    return sum;

};
int restar(int a,int b)
{
    int res;
    res = a - b;
    return res;

};
int multiplicar(int a,int b)
{
    int mult;
    mult = a * b;
    return mult;

};
float dividir(float* Resultado,int a,int b){
    float div;
    int retorno = -1;
    if(b != 0 && Resultado != NULL){
    div = (float)a / b;
    *Resultado = div;
    retorno = 0;
    }
    return retorno;

};
double factorial(int a)
{
	double factorial = 1;
	for(int i=1;i<=a;i++){
		factorial = factorial * i;
	}
	if(a == 0){
		factorial = 0;
	}else if(a < 0){
		factorial = -1;
	};
	return factorial;
	};
