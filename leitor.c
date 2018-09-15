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

void printar(char string[],int tam,Elemento *vetor_principal){
	int i;

	for(i=0;i<26;i++){
		printf ("\n\nAGORA EH [%d]\n\n",i);	
		while(vetor_principal[i].prox != NULL){
			printf ("[ %s ] and [ %d ] \n",vetor_principal[i].prox->palavra,vetor_principal[i].prox->quantidade);
			vetor_principal[i].prox=vetor_principal[i].prox->prox;
		}
	}
}

void igual (char string[], Elemento *aux,int *stop){
	if(strcmp(string,aux->palavra)==0){
		*stop=1;
		aux->quantidade++;
	}
}

void criarOutros(Elemento *vetor_principal,char string[],int tam){
	int i=0,stop=0,ok=0,b=0,id=0;
	char a=0;

	//VERIFICA A PALAVRA E ONDE É SEU ID
	while(stop==0){
		a=string[i];
		b=(int)a;

		if(b >= 65 && b <= 90){
			id=b-65;
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

	aux=vetor_principal[id].prox;

		if(aux != NULL ){
			igual(string,aux,&stop);

			while (aux->prox != NULL){
				igual(string,aux->prox,&stop);
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
		vetor_principal[id].prox=vertice;	
		vertice->quantidade=1;
		vertice->prox=NULL;
		}	
	}
	printf ("\n");
}

void ordenar(Elemento *vetor_principal){
	int i=0;
	Elemento *aux;
	
	for(i=0;i<26;i++){
		aux=vetor_principal[i];
	}

}

int main (){
	FILE *leitura_string;
	Elemento *vetor_principal=(Elemento*) malloc (27*sizeof(Elemento));
	char string[300]={0};
	int i=0,tam=0;
	

	leitura_string=fopen("leitura.txt","rt");

	if(leitura_string==NULL){
		printf ("ERRO NA LEITURA DO ARQUIVO\n");
	}


	//CONTINUANDO O PROGRAMA
	while(fscanf(leitura_string," %s",string) != EOF){
		printf("[%s] ",string);

		tam=strlen(string);
		transforma(string,tam);

		criarOutros(vetor_principal,string,tam);
	}

	//printf ("\nMOSTRAR LISTA ENCADEADA\n");
	//printar(string,tam,vetor_principal);


	printf ("ORDENAR\n");
	ordenar(vetor_principal);


	printf ("\nFIM \n");
	fclose(leitura_string);
	return 0;
}