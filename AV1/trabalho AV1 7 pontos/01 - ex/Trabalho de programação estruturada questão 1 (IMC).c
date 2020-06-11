#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <math.h>
#define MAX 5

double ImcCalculo(float p, float a) {	
	return p/pow(a,2);	
}

void linha() {
	int cont;
	for(cont=0;cont<33;cont++)
	{
		printf("-");
	}
	printf("\n");
}

void MassaCorporal(double massa) {
	if (massa < 18.5)
      		printf("abaixo do peso\n");
    	else
      		if (massa < 24.9)
        		printf("peso normal\n");
      		else
        		if (massa < 29.9)
          			printf("sobrepeso\n");
        		else
          			printf("obesidade grau 1\n");
}

struct pessoa {
		
char nome[20];
float peso, altura;
double imc;
		
};
	
main() {
	struct pessoa pessoas[MAX];
	int i;
	setlocale(LC_ALL,"");
	
	for( i=0 ; i<MAX ; i++ )
	{
		printf("Digite o nome %i: ",i+1);
		scanf("%s",pessoas[i].nome);
		fflush(stdin);
    	do {
    		printf("Digite o peso: ");
			scanf("%f",&pessoas[i].peso);
			fflush(stdin);
    	}while(pessoas[i].peso <= 0);
    	
    	do {
      		printf("Digite o altura: ");
			scanf("%f",&pessoas[i].altura);
			fflush(stdin);
    	}while(pessoas[i].altura <= 0);
    	
    	system("cls");
	}
	
	for( i=0 ; i<MAX ; i++ ) {
		linha();
		
		printf("A pessoa: %s\n",pessoas[i].nome);
    	printf("O peso e de: %.2f\n",pessoas[i].peso);
    	printf("A altura e de: %.2f\n",pessoas[i].altura);

    	pessoas[i].imc=ImcCalculo(pessoas[i].peso,pessoas[i].altura);
	
		MassaCorporal(pessoas[i].imc);
		
		linha();
	}
	
	system("Pause");	
}
