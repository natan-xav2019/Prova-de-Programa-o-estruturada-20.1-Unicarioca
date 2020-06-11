#include <stdio.h> // Uma biblioteca para chamar as funções "printf("Hello World\n")" e "scanf("%i",&x)".
#include <locale.h>// Uma biblioteca para caracteres nao bugarem ussando o "setlocale(LC_ALL,"")".
#include <math.h>// biblioteca matematica para usar funçoes como "sqrt(radicando)" e "pow(base,expoente)".

int quant_raiz(float a,float b, float c, float *x1, float *x2)//Função que calcula a quantidade de raizes.
{
	float delta;//Variavel onde sera guardada o valor de delta.
	
	delta=pow(b,2)-4*a*c;//Calculo de delta e atribuida a variavel float delta.
	//Logica para determinar se delta e positivo negativo ou igual a zero.
	if(delta<0)//Delta menor do que zero executa esse bloco.
		return -1;//devolve -1 mostrando que nao a raizes reais.
	else
		if(delta==0) { /*delta = a zero executa esse bloco*/
			*x1=(-b+sqrt(delta))/(a*2);//passase a expreção para o endereço de memoria de r1 por referência.
			*x2=*x1;//passase a expreção para o endereço de memoria de r2 por referência.
			return 1; //devolve 1 mostrando que a duas raizes iguals.
		}
		else { /*delta diferente de zero executa esse bloco*/
			*x1=(-b+sqrt(delta))/(a*2);//passase a expreção para o endereço de memoria de r1 por referência.
			*x2=(-b-sqrt(delta))/(a*2);//passase a expreção para o endereço de memoria de r2 por referência.
			return 2; //devolve 1 mostrando que a duas raizes diferentes.
		}	
}

int main()//bloco principal do programa.
{
	float q_raiz ,a ,b ,c , r1, r2;//variavez.
	
	setlocale(LC_ALL,"");//comando para as os caracteres especificos da lingua portugesa.
	//apresentação de entrada.
	
	do {//inicio testando sempre uma vez podendo testa quantas vezes for necessaria se a condicional continuar sendo verdadeira.
		printf("Digite uma equação do segundo grau\n");//Mensagem para o usuario.
		printf("Dígite o valor de A: ");//Mensagem para o usuario inserir.
		scanf("%f",&a);//entrada de A.
		if(a==0) { /*Se a igual a zero executa esse bloco*/
			printf("\nPara ser uma equação do segundo grau a tem que ser diferente de 0\n");//Mensagem para o usuario.
			printf("\nAperte qualquer tecla para recomeçar\n");//Mensagem para o usuario.
			system("Pause");//Pausa o programa ate que o usuario aperte alguma tecla.
			system("cls");//limpa a Tela
		}	
	}while(a==0);//Recomeça o laço com a partir do inicio do bloco.
	printf("Dígite o valor de B: ");//Mensagem para o usuario.
	scanf("%f",&b);//entrada de B.
	printf("Dígite o valor de C: ");//Mensagem para o usuario.
	scanf("%f",&c);//entrada de C.
	
	/*Função que ve a quantidade de raizes e passa r1 e r2 como referência ou seja
	passa o seu endereço de memoria para guardar os valores em x1 e x2.*/
	q_raiz=quant_raiz(a,b,c, &r1, &r2);
	if(q_raiz>0) { /*Caso delda for possitivo ou igual a 0.*/
		printf("As raises sao diferentes\n");//Mensagem para o usuario.
		printf("raiz 1 = %.2f\n",r1);//Mostrar valor da r1.
		printf("raiz 2 = %.2f\n",r2);//Mostrar valor da r2.
 	}
	else
		if(q_raiz==0) {
			printf("As raises são iguals\n");//Mensagem para o usuario.
			printf("raiz 1 = %.2f\n",r1);//Mostrar valor da r1.
			printf("raiz 2 = %.2f\n",r2);//Mostrar valor da r2.
		}
		else//Mostrar caso delta for negativo.
			printf("\nNão possui raizes reais\n");//Mensagem para o usuario.
	
	return 0;// Fim do programa.
}
