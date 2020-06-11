#include <stdio.h>
#include <string.h>

/*4)Fa�a um programa que modifique as vogais de uma frase. 
O programa deve ler uma frase (max. 100 caracteres) e 
armazen�-la num vetor. Imprimir a frase lida trocando 
as vogais, isto �, trocar 'a' pelo 'u', 'e' pelo 'o', 
'i' pelo 'u', 'o' pelo 'a' e o 'u' pelo 'e'. Usar uma 
fun��o void (procedimento) para realizar a troca e uma 
fun��o para realizar a impress�o da frase trocada. A fun��o 
deve ter como par�metro um ponteiro char referente ao vetor. 
Dica: Use a fun��o gets() da biblioteca string.h para realizar 
a leitura da frase. Use o switch para realizar as trocas. S� considere 
as letras min�sculas.*/


void trocaDeVogal(char text[]){
	int i;
	
	for(i=0;i<strlen(text);i++) {
		
		switch(text[i]) {
		case 'a': text[i] = 'u';
			break;
		case 'e': text[i] = 'o';
			break;
		case 'i': text[i] = 'u';
			break;
		case 'o': text[i] = 'a';
			break;
		case 'u': text[i] = 'e';
			break;
		}
	}
}

void apresentar(char *text) {
	printf("%s\n",text);
}

main(){
	
	char texto[101];//esse mais um e para o digito de verifica��o de string por isso 101 em vez de 100
	
	printf("Digite uma fraze com ate 100 caracteres:\n");
	gets(texto);
	
	trocaDeVogal(texto);
	
	apresentar(texto);
	system("pause");
}
