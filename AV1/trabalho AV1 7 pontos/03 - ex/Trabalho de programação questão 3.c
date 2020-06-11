/*3)Escreva os valores que serão exibidos  e comente cada linha do programa abaixo.*/
#include<stdio.h>
#include<stdlib.h>
main()
{
	int vetor[3]={1967, 1947, 2007};// Declaro um vetor com 3 posições.
	int *ano;// Declaro um valor para referencia.
	
	ano=&vetor[0];// Atribui o endereço de memoria do vetor na posição 0 que e 1967.
	ano++;// encrementa a posição do vetor passando a ser o vetor na posição 1.
	
	printf("Valor: %d\n", *ano);// imprime o valor 1947 pois a atribuição da linha 10 foi na posição passando de vetor[0] para vetor[1].
	
	(*ano)++;// encrementa no valor de mais 1 no vetor[1].
	
	printf("Valor: %d\n", *ano);// imprime o valor 1948 pois a atribuição da linha 14 foi direcionada para o valor do vetor[1].
	 
	system("pause");//pausa o programa.
}    


