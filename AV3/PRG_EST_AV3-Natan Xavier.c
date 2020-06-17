#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <ctype.h>
#include <locale.h>
#include <string.h>
#include<stdbool.h>

struct livraria {
	char titulo[50], autor[50], editora[50],edisao[50];
};

void EscrevaDigitos(char digitado[]) {
	int i=0;
	char c;
	do {
		do {
    		c=getch();
        	if (isalpha(c)!=0 || c==32) {
        		digitado[i] = c;
        		i++;
        		printf("%c", c);
        		
			}
			else
				if(c==8 && i) {
		   			digitado[i]='\0';
        			i--;
        			printf("\b \b");
        			
        		}
    	}while(c!=13);
    	
	}while(i==0);
	
   printf("\n");
    digitado[i]='\0';
}

void EscrevaNumeros(char digitado[]) {
    int i=0;
	char c;
   	
   	do {
	    do {
	    	c=getch();
	    	
	        if (isdigit(c)!=0) {
	        	digitado[i] = c;
	        	i++;
	        	printf("%c", c);
	        	
	       	}
	       	else
			   	if(c==8&&i) {
	          		digitado[i]='\0';
	          		i--;
	          		printf("\b \b");
	          		
	       		}
	       		
	    }while(c!=13);
	    
   	}while(i==0);
   	
   	printf("\n");
   	
    digitado[i]='\0';
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

ApresentaBuscar(struct livraria **text,int i) {
	
	printf("\n--------------------------------\n\n");
	printf("Titulo: %s\n",(*text)[i].titulo);
	printf("Autor: %s\n",(*text)[i].autor);
	printf("Editora: %s\n",(*text)[i].editora);
	printf("Edição: %s°\n",(*text)[i].edisao);
	printf("\n--------------------------------\n");
	
}

void Busca(struct livraria *text[],char filtro[],char buscado[],int max) {
	int i=0;
	bool achou = false;
	
	formataTexto(buscado);
	
	if(strcmp(filtro,"Titulo") == 0) {
		while(i<max && !achou) {
			if(strcmp(buscado,(*text)[i].titulo) == 0) {
				achou = true;
			}
			i++;
		}
	}
	
	i=0;
	
	if(strcmp(filtro,"Autor") == 0){
		while(i<max && !achou) {
			if(strcmp(buscado,(*text)[i].autor) == 0) {
				achou = true;
			}
			i++;
		}	
	}
	
	i=0;
	
	if(strcmp(filtro,"Editora") == 0) {
		while(i<max && !achou) {
			if(strcmp(buscado,(*text)[i].editora) == 0) {
				achou = true;
			}
			i++;
		}
	}

	if(achou) {
		for(i=0;i<max;i++) {
			if(i==0) {
				printf("\tRegistro Biblioteca\n");
			}
			
			if(strcmp(buscado,(*text)[i].titulo) == 0 && strcmp(filtro,"Titulo") == 0) {				
				ApresentaBuscar(text,i);
			}
			
			if(strcmp(buscado,(*text)[i].autor) == 0 && strcmp(filtro,"Autor") == 0) {	
				ApresentaBuscar(text,i);
			}
			
			if(strcmp(buscado,(*text)[i].editora) == 0 && strcmp(filtro,"Editora") == 0) {
				ApresentaBuscar(text,i);
			}
		}
	}
	else
		printf("nenhum registro encontrado\n");
	
		
}

main() {
	struct livraria *biblioteca = NULL;
	struct livraria *mais_biblioteca;
	
	FILE *documento;
	
	int escolha,i=0,max=0;
	char pesquisa[20],filtro[20];
	
	setlocale(LC_ALL,"");
	
	documento = fopen("Registro da biblioteca.txt","w+");
	
	do {
		system("title Menu");
		printf("Menu\n");
		printf("1 para Cadastro\n");
		printf("2 para Consultar\n");
		printf("3 para Sair do programa\n");
		scanf("%i",&escolha);
		fflush(stdin);
		system("cls");
		
		switch(escolha) {
		case 1:
			system("title Cadastro");
			mais_biblioteca = (struct livraria*)realloc(biblioteca, i+1 *sizeof(struct livraria));
			
			if(mais_biblioteca != NULL)
				biblioteca = mais_biblioteca;
			else {
				free(biblioteca);
				printf("Erro ao (re)alocar memoria");
				
				exit(1);
			}
				
			printf("Digite o titulo do Livro: ");
			EscrevaDigitos(biblioteca[i].titulo);
			formataTexto(biblioteca[i].titulo);
			
			printf("Digite o autor do Livro: ");
			EscrevaDigitos(biblioteca[i].autor);
			formataTexto(biblioteca[i].autor);
			
			printf("Digite a editora do Livro: ");
			EscrevaDigitos(biblioteca[i].editora);
			formataTexto(biblioteca[i].editora);
			
			printf("Digite a edição do Livro: ");
			EscrevaNumeros(biblioteca[i].edisao);
			
			
			if(i==0)
				fprintf(documento,"\tRegistro Biblioteca\n");
				
			fprintf(documento,"\n--------------------------------\n\n");
			fprintf(documento,"Titulo: %s\n",biblioteca[i].titulo);
			fprintf(documento,"Autor: %s\n",biblioteca[i].autor);
			fprintf(documento,"Editora: %s\n",biblioteca[i].editora);
			fprintf(documento,"Edição: %s°\n",biblioteca[i].edisao);
			fprintf(documento,"\n--------------------------------\n");
			
			i++;
			max = i;
			break;
		case 2:
			system("title Pesquisa");
			                                                                            
			do {
				printf("voce pode pesquisar por titulo, autor e editora\n");
				printf("Digite o que deseja buscar\n");
				EscrevaDigitos(filtro);               
				formataTexto(filtro);
				system("cls");
			}while(!(strcmp(filtro,"Titulo") == 0 || strcmp(filtro,"Autor") == 0 || strcmp(filtro,"Editora") == 0));
			
			if(strcmp(filtro,"Titulo") == 0)
				printf("Digite o Titulo:");
			else
				if(strcmp(filtro,"Autor") == 0)
					printf("Digite o Autor:");
				else
					if(strcmp(filtro,"Editora") == 0)
						printf("Digite a Editora:");

			EscrevaDigitos(pesquisa);
			Busca(&biblioteca,filtro,pesquisa,max);
				
			break;
		case 3:
			system("title Fim do programa");
			printf("Fim do Programa\n");
			break;
		default: 
			printf("Opção invalida\n");
		}

		system("Pause");
		system("cls");
	}while(escolha != 3);
	
	fclose(documento);
	free(biblioteca);
}
