#include <stdio.h>
#include <stdlib.h>

/*
Aluno: Natan Xavier de Siqueira
turma: 127
Matricula: 2019200079*/

/*1)Leia 10 números inteiros e armazene em um vetor v. 
Crie dois novos vetores v1 e v2. Copie os valores  impares 
de v para v1, e os valores pares de v para v2 que terão seus 
tamanhos modificados dinamicamente. No final escreva os elementos 
UTILIZADOS de v1 e v2.*/

main() {
	
	const int MAX = 10;
	int num[MAX],i,ip,ii, maxII, maxIP;
	int *par = NULL, *impar = NULL, *mais_par, *mais_impar;
	
	ip=ii=0;
	
	printf("Digite %i numeros: \n",MAX);
	for(i=0;i<MAX;i++) {
		scanf("%i",&num[i]);
		
		if(num[i] % 2 == 0) {
			ip++;
			mais_par = (int*)realloc(par,ip*sizeof(int));
			if(mais_par != NULL) {
				par=mais_par;
				par[ip-1]=num[i];
			}
			else {
				free(par);
				puts("Erro ao (re)alocar memoria");
				exit(1);
			}
		}
		else {
			ii++;
			mais_impar = (int*)realloc(impar,ii*sizeof(int));
			if(mais_impar != NULL) {
				impar=mais_impar;
				impar[ii-1]=num[i];
			}
			else {
				free(impar);
				puts("Erro ao (re)alocar memoria");
				exit(1);
			}
		}
	}
	
	maxII = ii;
	maxIP = ip;
	//<----------tirei do for esas estruturas de seleção----------->
	if(!par == NULL) {//tinhas uns asteristicos nada haver no *par
		printf("\tNumeros pares\n");
		for(ip=0;ip<maxIP;ip++)
			printf("par[%i] = %i\n",ip,par[ip]);
	}
	else
		printf("Não ouve numeros pares\n");
	
	if(!impar == NULL) {//tinhas uns asteristicos nada haver no *impar
		printf("\tNumeros impares\n");
		for(ii=0;ii<maxII;ii++)
			printf("impar[%i] = %i\n",ii,impar[ii]);
	}
	else
		printf("Não ouve numeros impares\n");
	
	
}
