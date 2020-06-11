#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <locale.h>
#define MAX 10
/*Desenvolva um programa que receba o nome, sexo e idade de dez pessoas. O programa deve exibir um menu para busca por sexo ou por idade.
1 - Sexo
2 - Idade
3 - Sair

	2º Periodo de Ciência da Computação
			trabalho de AV1 (3 pontos)
	
Programador: Natan Xavier de Siqueira
Matricula: 2019200079
Materia: Programação estruturada
*/

struct from {//Formulario
	char name[30],sex;
	int age;
};

int checkSex(char sex) {//teste logico para masculino e feminino
	return sex == 'M' || sex == 'F' ? 1 : 0;
}

void line(int x) {//Função linha
	int cont;
	
	for( cont=0; cont<x ; cont++) {
		printf("---");
	}
	printf("\n");
}

void introduction() {//abertura do do programa
	line(26);
	printf("Por favor complete o cadastro dos 10 usuários com nome, sexo e idade.\n");
	line(26);
}

int menu() {//Menu de opições
	int action;
	printf("Menu de opções de filtro digite\n");
	printf("1 - Sexo\n2 - Idade\n3 - Sair\n");
	scanf("%i",&action);
	fflush(stdin);
	
	return action;
}
//função para pega o nome idade e genero dos usuarios e imprimir filtrando com base no caracter pedido pelo usuario. 
void userC(char filterC,char text[], struct from froms[MAX]) {
  	int i,quant=0;
  	
  	system("cls");
  	
	printf("\t\t%s\n",text);
	line(26);
	for(i=0;i<MAX;i++) {
		if(froms[i].sex == filterC) {
			quant++;
			printf("Usuário: %s\n",froms[i].name);
			printf("Sexo: %c\n",froms[i].sex);
			printf("Idade: %i\n",froms[i].age);
			line(26);
		}
	}
	if(!quant) {
		printf("\t\tFomulário Vazio\n");
		line(26);
	}
}

void filterAge(int filterI, struct from froms[MAX]) {//Filtro baseado na idade pedida pelo usuario
	int i,quant=0;
	
	system("cls");
	
	printf("\t\tFiltro para idade de %i ano\n",filterI);
	line(26);
	for(i=0;i<MAX;i++) {
		if( froms[i].age == filterI) {
			quant++;
			printf("Usuário: %s\n",froms[i].name);
			printf("Sexo: %c\n",froms[i].sex);
			printf("Idade: %i\n",froms[i].age);
			line(26);
		}
	}
	if(!quant) {
		printf("\t\tFomulário Vazio\n");
		line(26);
	}
}

void filterSex(char filterC, struct from froms[MAX]) {//enviando o caracter para a função correspondente
	if(filterC == 'M') {
    	userC(filterC,"Filtro Masculino",froms);
  	}
	else
    if(filterC == 'F') {
		userC(filterC,"Filtro Feminino",froms);
	}
}

main() {
	
	struct from froms[MAX];
	int action,i,filterI;
	char filterC;
	
	setlocale(LC_ALL,"");
	
	for(i=0;i<MAX;i++) {
		system("title Filtro de Formulário");
		introduction();
		
		printf("Fomulário do usuário %i\n\n",i+1);
		
		printf("Digite o nome: ");
		gets(froms[i].name);
		
		do{
			printf("Digite a idade: ");
			scanf("%i",&froms[i].age);
			fflush(stdin);
			
			if(froms[i].age <= 0)
				printf("Digite uma idade maior que zero.\n");
			
		}while(froms[i].age <= 0);
		
		do{
			printf("Digite o gênero: ");
			scanf("%c",&froms[i].sex);
			fflush(stdin);
			
			froms[i].sex = toupper(froms[i].sex);
		
			if( !checkSex(froms[i].sex) )
				printf("Digite apenas Masculino ou Feminino.\n");
				
		}while( !checkSex(froms[i].sex) );// teste logico para F,f,M,m.
		
		system("cls");
	}
	
	while(action != 3) {//o menu ira repetir enquando for diferente de 3
		
		system("cls");
		
		action = menu();
		
		if(action == 1) {//filtro sexo
			do {
				printf("Você gostaria de filtrar por masculino ou feminino?\n");
				scanf("%c",&filterC);
				fflush(stdin);
			
				filterC = toupper(filterC);
			
				if( !checkSex(filterC) )
					printf("Digite apenas Masculino ou Feminino.\n");
				
			}while( !checkSex(filterC) );
			
			filterSex(filterC,froms);
		}
		else
			if(action == 2) {//filtro por idade
				do {
					printf("Você gostaria de filtrar pessoas de qual idade?\n");
					scanf("%i",&filterI);
					fflush(stdin);
			
					if(filterI <= 0)
						printf("Digite uma idade maior que zero.\n");
						
				}while(filterI <= 0);
			
				filterAge(filterI,froms);
			}
			else
				if(action == 3)//fim do programa
					printf("Fim do Programa\n");
				else//opição invalida
					printf("DIGITE SOMENTE O QUE FOI PEDIDO.\n");
				
			system("Pause");
	}
}
