#include <stdio.h>
#include <stdlib.h>
#include<stdbool.h>

/*
Aluno: Natan Xavier de Siqueira
turma: 127
Matricula: 2019200079*/

/*2)Faça um programa para ler 10 números DIFERENTES a serem 
armazenados em um vetor. Os dados deverão ser armazenados 
no vetor na ordem que forem sendo lidos, ˜ sendo que caso o 
usuário digite um número que já foi digitado anteriormente, 
o programa deverá pedir para ele digitar outro número. Note 
que cada valor digitado pelo usuário deve ser pesquisado no 
vetor, verificando se ele existe entre os números que já foram  
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
