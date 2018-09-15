#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>



typedef struct elemento{
	char palavra[100];
	int quantidade;
	struct elemento *prox;
}Elemento;

void transforma(char string[],int tam){
	int i=0;

	for(i=0;i<tam;i++){
		string[i]=toupper(string[i]);
	}
}

void printar(Elemento *vetor_principal){

	printf ("[ %s ]\n",vetor_principal->prox->palavra);
	while(vetor_principal->prox != NULL){
			printf ("[ %s ] and [ %d ] \n",vetor_principal->prox->palavra,vetor_principal->prox->quantidade);
			vetor_principal->prox=vetor_principal->prox->prox;
	}	
}

void igual (char string[], Elemento *aux,int *stop){
	if(strcmp(string,aux->palavra)==0){
		*stop=1;
		aux->quantidade++;
	}
}

void criarOutros(Elemento *vetor_principal,char string[],int tam){
	int i=0,stop=0,ok=0,b=0;

	//VERIFICA É UMA LETRA OU OUTROP CARACTER
	while(stop==0){
		b=(int)string[i];
		if(b >= 65 && b <= 90){
			stop=1;
			ok=1;
		}
		if(i==tam){
			stop=1;
		}
		i++;
	}

	stop=0;

	if(ok==1){
	Elemento *vertice = (Elemento*) malloc (sizeof(Elemento));
	Elemento *aux;

	aux=vetor_principal;

		if(aux->prox != NULL ){
			igual(string,aux,&stop);

			while (aux->prox != NULL ){
				igual(string,aux,&stop);
				aux=aux->prox;
			}

			if(stop == 0){
				strcpy(vertice->palavra,string);
				aux->prox=vertice;	
				vertice->quantidade=1;
				vertice->prox=NULL;
			}
		}

		else{
		strcpy(vertice->palavra,string);
		vetor_principal->prox=vertice;	
		vertice->quantidade=1;
		vertice->prox=NULL;
		}	
	}
}


void ordenar(Elemento *vetor_principal){
	int i=0;
	Elemento *aux, *aux2, *vetor;

	vetor=vetor_principal;	




	/*while(vetor->prox != NULL){
		aux=vetor->prox;
		printf("\nAQUI\n");
		while(aux->prox != NULL){
			if(aux->quantidade > vetor->quantidade){
				aux2->quantidade = vetor->quantidade;
				strcpy(aux2->palavra , vetor->palavra);
				
				strcpy(vetor->palavra,aux->palavra);
				vetor->quantidade = aux->quantidade;
				
				strcpy(aux->palavra,aux2->palavra);
				aux->quantidade = aux2->quantidade;  
			}

			aux = aux->prox;
		}
		vetor = vetor->prox;
	}*/
	printf ("ORDENADO\n");
}




int main (){
	FILE *leitura_string;
	Elemento *vetor_principal=(Elemento*) malloc (sizeof(Elemento));
	char string[300]={0};
	int i=0,tam=0;

	leitura_string=fopen("leitura.txt","rt");

	if(leitura_string==NULL){
		printf ("ERRO NA LEITURA DO ARQUIVO\n");
	}

	//CONTINUANDO O PROGRAMA
	while(fscanf(leitura_string," %s",string) != EOF){

		tam=strlen(string);
		transforma(string,tam);

		criarOutros(vetor_principal,string,tam);
	}


	//printf ("\nMOSTRAR LISTA ENCADEADA\n");
	printar(vetor_principal);
	//ordenar(vetor_principal);
	printar(vetor_principal);

	printf ("[ %s ]\n" , vetor_principal->palavra);
	printf ("[ %s ]\n" , vetor_principal->prox->palavra);
	printf ("[ %s ]\n" , vetor_principal->prox->prox->palavra);

	printf ("\nFIM \n");
	fclose(leitura_string);
	return 0;
}