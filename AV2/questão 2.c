#include <stdio.h>
#include <stdlib.h>
#include<stdbool.h>

/*
Aluno: Natan Xavier de Siqueira
turma: 127
Matricula: 2019200079*/

/*2)Fa�a um programa para ler 10 n�meros DIFERENTES a serem 
armazenados em um vetor. Os dados dever�o ser armazenados 
no vetor na ordem que forem sendo lidos, � sendo que caso o 
usu�rio digite um n�mero que j� foi digitado anteriormente, 
o programa dever� pedir para ele digitar outro n�mero. Note 
que cada valor digitado pelo usu�rio deve ser pesquisado no 
vetor, verificando se ele existe entre os n�meros que j� foram  
fornecidos. Exibir na tela o vetor final que foi digitado.*/

bool NumeroIgual(int numero,int max, int num[]) {
	int i;
	for(i=0;i<max;i++)
		if(numero == num[i])
			return true;

	return false;
}

main() {
	const int MAX = 10;
	int num[MAX], i=0;
		
	printf("Digite %i numeros diferentes:\n", MAX);
	while(i<MAX) {
		do {
			scanf("%i",&num[i]);
			if(NumeroIgual(num[i],i, num))
				printf("Digite somente numeros diferentes\n");

		}while(NumeroIgual(num[i],i, num));
		i++;
	}
	
	printf("numeros diferentes:\n");
	for(i=0;i<MAX;i++) {
		printf("numero: %i\n",num[i]);
	}
}
