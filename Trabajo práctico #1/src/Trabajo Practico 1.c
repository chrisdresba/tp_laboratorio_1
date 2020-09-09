/*
 ============================================================================
 Name        : Prueba.c
 Author      : Cristian Andres Barraza
 Version     : Linux - Ubuntu
 Copyright   : Your copyright notice
 Description : Menu de calculos - TP1
 ============================================================================
 */
#include <stdio.h>
#include <stdio_ext.h>
#include <stdlib.h>
#include <ctype.h>
#include "calculos.h"


int main(){
	setbuf(stdout, NULL);

    int num1;
    int num2;
    int numeroingresado;
    int flagnum1 = 0;
    int flagnum2 = 0;
    int flag3 = 0;
    int resSuma;
    int resResta;
    int resMultip;
    float divid;
    double factor1;
    double factor2;
    int resultado;
    int opcion;

    do{


    	printf("\n\t<---MENU TP1--->\n ");
    	if(flagnum1 == 0 && flagnum2 == 0){
    	printf("1.Ingrese el 1er operando (A=x) \n 2.Ingrese el 2do operando (B=y)\n 3.Calcular todas las operaciones \n 4.Informar los resultados \n 5.Salir\n");
    	} else if(flagnum1 != 0 && flagnum2 == 0){
    	printf("1.Ingrese el 1er operando (A=%d) \n 2.Ingrese el 2do operando (B=y)\n 3.Calcular todas las operaciones \n 4.Informar los resultados \n 5.Salir\n",num1);
    	}else{
    		printf("1.Ingrese el 1er operando (A=%d) \n 2.Ingrese el 2do operando (B=%d)\n 3.Calcular todas las operaciones \n 4.Informar los resultados \n 5.Salir\n",num1,num2);
    	};

    	if(validarmenu(&opcion,"Opción incorrecta\n") == 0){
    	switch(opcion){

    	case 1:
    		printf("Ingrese un numero: ");
    		scanf("%d", &numeroingresado);
    		__fpurge(stdin);  //UBUNTU system("PAUSE")
    		if(numeroingresado > -999 && numeroingresado <= 1000){
    			num1=numeroingresado;
    			flagnum1++;
    			numeroingresado = -999;
    		} else{
    			printf("\nError - Dato incorrecto\n");
    		};
    		break;

    	case 2:
    		if(flagnum1 == 0){
    	printf("\n\tDebe ingresar el primer numero para realizar la operacion\n");
    		    	break;
    		};
    		printf("Ingrese un segundo numero: ");
    		   scanf("%d", &numeroingresado);
    		  	__fpurge(stdin);
    	 if(numeroingresado > -999 && numeroingresado <= 1000){
    		    num2=numeroingresado;
    		    flagnum2++;
    		   } else{
    		  	printf("\nError - Dato incorrecto\n");
    		    		};
    		break;

    	case 3:
    		if(flagnum1 > 0 && flagnum2 > 0){
    			resSuma = sumar(num1,num2);
    			resResta = restar(num1,num2);
    			resMultip = multiplicar(num1,num2);
    			resultado = dividir(&divid,num1,num2);
    			factor1 = factorial(num1);
    			factor2 = factorial(num2);
    			flag3++;
    		}else {
    			printf("\n\tDebe ingresar el/los numero/s para realizar la operacion\n");
    		}

    		break;
    	case 4:
    		if (!(flagnum1 > 0 && flagnum2 > 0)){
    	 printf("\nDebe ingresar el/los numero/s para realizar la operacion\n");

    	 } else if (flag3 == 0){
    	 printf("\nPrimero debe indicar: \n3.Calcular todas las operaciones\n");
    		   		}

    if(flagnum1 > 0 && flagnum2 > 0 && flag3 > 0){
    printf("\n\ta) El resultado de %d+%d es: %d.",num1,num2,resSuma);
    printf("\n\tb) El resultado de %d - %d es: %d.",num1,num2,resResta);
    printf("\n\tc) El resultado de %d*%d es: %d.",num1,num2,resMultip);
    if(resultado == 0){
    	 printf("\n\td) El resultado de %d/%d es: %.2f.",num1,num2,divid);
    }else{
    	 printf("\n\td) No se puede dividir por cero");
    };
    if(factor1 >= 0){
    printf("\n\te) El factorial de %d es: %.0lf y ",num1,factor1);
    }else{
    printf("\n\te) No se puede calcular el factorial de un negativo y ");
    }
    if(factor2 >= 0){
    printf("el factorial de %d es: %.0lf .",num2,factor2);
    }else{
    printf("no se puede calcular el factorial de un negativo.");
    }
    flagnum1 = 0;
    flagnum2 = 0;
    flag3 = 0;
    }
    break;

    	}
    	 getchar();  //UBUNTU system("PAUSE")

    };
    	system("clear"); //UBUNTU
    }while(opcion != 5);

    system("clear");  //UBUNTU
    return 0;
}
