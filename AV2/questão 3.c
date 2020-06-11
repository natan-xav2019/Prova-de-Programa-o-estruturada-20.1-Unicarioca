#include <stdio.h>
#include <stdlib.h> 

/*
Aluno: Natan Xavier de Siqueira
turma: 127
Matricula: 2019200079*/

/*3)Leia uma matriz 5 x 5. Leia também um valor  X. 
O programa devera fazer uma busca desse valor na matriz 
e, ao final, escrever a localização (linha e coluna) ou 
uma mensagem de “não encontrado”.
*/

main() {
	const int MAX = 5;
	int matriz[MAX][MAX],l,c, busca;
	
	for(l=0;l<MAX;l++) 
		for(c=0;c<MAX;c++)
			scanf("%i",&matriz[l][c]);
	
	
	printf("Digite um numero para ser buscado: \n");
	scanf("%i",&busca);
	
	for(l=0;l<MAX;l++) {
		for(c=0;c<MAX;c++) {
			if(busca == matriz[l][c]) {
				printf("Encontrado na linha %i e coluna %i\n", l, c);
				printf("O valor da matriz = %i\n",matriz[l][c]);
				exit(1);
			}
		}
	} 
		
	printf("Numero nao encontrado\n");
	system("pause");
	
}
