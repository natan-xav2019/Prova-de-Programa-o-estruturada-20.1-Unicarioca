#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <stdbool.h>

/*Aluno: Natan Xavier de Siqueira
Turma: 127
Matricula: 2019200079*/

/*Crie um programa que tenha um menu:

1- Entrar com novos dados

2- Listar dados

3- Sair

Ao selecionar a opção 1, os dados de um aluno devem ser armazenado em uma tabela(vetor de registros e em um arquivo), cada registro deve ser criado dinamicamente.

Ao selecionar a opção 2, será listado todos os registros.

Ao selecionar a opção 3, o programa deverá ser encerrado*/

//função verifica se a um numero na string da um sinal falso se encontrar lo.
bool verificaCaracter(char texto[]){
	int i;
	for(i=0;i<strlen(texto);i++)
		if(isdigit(texto[i]))
			return false;
			
	return true;
}

bool verificaNumero(char texto[]){
	int i;
	for(i=0;i<strlen(texto);i++)
		if(isalpha(texto[i]))
			return false;
			
	return true;
}

//função aplica letra maiuscula no inicio e logo apos de um espaço em branco e e deixando o resto em minusculo
void formataTexto(char texto[]){
	int i;
	for(i=0;i<strlen(texto);i++) {
		if(i==0)
			texto[i]=toupper(texto[i]);
		else
			if(texto[i] == ' ') {
				i++;
				texto[i]=toupper(texto[i]);
			}
			else
				texto[i]=tolower(texto[i]);	
	}
}

struct form {
	char nome[30];
	char sexo[10];
	char idade[4];
};

main(){
	struct form *dado = NULL;
	struct form *mais_dado;
	FILE *cadastro;
	
	char apresentar;
	int select,max=0,i,idade;
	
	do {
		printf("\tDigite\n");
		printf("1 - Entrar com novos dados\n");
		printf("2 - Listar dados\n");
		printf("3 - Sair\n");
		scanf("%i",&select);
		fflush(stdin);
		system("cls");
		
		if(select == 1) {
			//Alocação de memoria
			mais_dado = (struct form*) realloc(dado,(max+1) * sizeof(struct form));
			
			if(mais_dado != NULL)
				dado=mais_dado;
			else {
				printf("ERRO AO (RE)ALOCAR MEMORIA");
				exit(1);
			}
			/*entrada valor */
			do {
				printf("Digite o nome: ");
				gets(dado[max].nome);
				formataTexto(dado[max].nome);
				fflush(stdin);
			}while(!verificaCaracter(dado[max].nome));
			
			do {
				printf("Digite o sexo: ");
				scanf("%s",dado[max].sexo);
				fflush(stdin);
				formataTexto(dado[max].sexo);
			}while(strcmp(dado[max].sexo,"Masculino") && strcmp(dado[max].sexo,"Feminino"));
			
			do {
				idade = 0;
				printf("Digite a idade: ");
				scanf("%s",dado[max].idade);
				fflush(stdin); 
				idade = atoi(dado[max].idade);
			}while(idade <= 0 || idade >= 110 ||  !verificaNumero(dado[max].idade) );//isalpha verifica se a uma letra do alfabeto
			
			system("cls");
			/*Gravação dos dados no "Dados Pessoas.txt"*/
			if(max == 0) {
				cadastro = fopen("Dados Pessoas.txt","w");
				fprintf(cadastro,"\n\tTabela\n");
				fprintf(cadastro,"----------------------\n");
			}			
			else
				cadastro = fopen("Dados Pessoas.txt","a");
			
			fprintf(cadastro,"\nNome: %s\n",dado[max].nome);
			fprintf(cadastro,"Sexo: %s\n",dado[max].sexo);
			fprintf(cadastro,"Idade: %s ano(s)\n\n",dado[max].idade);
			fprintf(cadastro,"----------------------\n");
			
			fclose(cadastro);
			max++;
		}
		else//imprime o que esta dentro do "Dados Pessoas.txt"
			if(select == 2) {
				if(cadastro != NULL) {
					cadastro = fopen("Dados Pessoas.txt","r");
					while((apresentar = getc(cadastro) ) != EOF)
    					printf("%c", apresentar);
    			
					fclose(cadastro);
				}
				else
					printf("Sem Dados\n");
					
				system("pause");
				system("cls");
			}
			else
				if(select == 3) {
					printf("Programa encerado\n");
					free(dado);
				}
	}while(select != 3);
	
}
