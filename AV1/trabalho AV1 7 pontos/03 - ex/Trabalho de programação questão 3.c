/*3)Escreva os valores que ser�o exibidos  e comente cada linha do programa abaixo.*/
#include<stdio.h>
#include<stdlib.h>
main()
{
	int vetor[3]={1967, 1947, 2007};// Declaro um vetor com 3 posi��es.
	int *ano;// Declaro um valor para referencia.
	
	ano=&vetor[0];// Atribui o endere�o de memoria do vetor na posi��o 0 que e 1967.
	ano++;// encrementa a posi��o do vetor passando a ser o vetor na posi��o 1.
	
	printf("Valor: %d\n", *ano);// imprime o valor 1947 pois a atribui��o da linha 10 foi na posi��o passando de vetor[0] para vetor[1].
	
	(*ano)++;// encrementa no valor de mais 1 no vetor[1].
	
	printf("Valor: %d\n", *ano);// imprime o valor 1948 pois a atribui��o da linha 14 foi direcionada para o valor do vetor[1].
	 
	system("pause");//pausa o programa.
}    


