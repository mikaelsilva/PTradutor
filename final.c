#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>



typedef struct elemento{
	char palavra[100];
	int quantidade;
}Elemento;

void transforma(char string[],int tam){
	int i=0;
	for(i=0;i<tam;i++){
		string[i]=toupper(string[i]);
	}
}

void printar(Elemento vetor_principal[],int tam2){
	int i;
	for(i=0;i<tam2;i++){
		printf ("[ %s ] and [%d]\n",vetor_principal[i].palavra,vetor_principal[i].quantidade);
	}
}


void criarOutros(Elemento vetor_principal[],char string[],int tam,int *tam2){
	int i=0,stop=0,ok=0,b=0;

	//VERIFICA É UMA LETRA OU OUTROP CARACTER
	while(stop==0){
		b=(int)string[i];
		if(b >= 65 && b <= 90){
			stop=1;
			ok=1;
		}
		else if(i==tam){
			stop=1;
		}
		else{
			string[i]='0';
		}
		i++;
	}
	stop=0;

	if(ok==1){
		for(i=0;i<*tam2;i++){
			if(strcmp(string,vetor_principal[i].palavra)==0){
				vetor_principal[i].quantidade++;
				i=*tam2;
				ok=0;
			}
		}

		if(ok != 0){
			strcpy(vetor_principal[i].palavra,string);
			vetor_principal[i].quantidade=1;
			*tam2=*tam2+1;
		}
	}
}

void ordenar(Elemento vetor_principal[],int tam2){
	int i,j;
	Elemento aux;
	
	for(i=0;i<tam2;i++){
		for(j=i;j<tam2;j++){
			if(vetor_principal[i].quantidade < vetor_principal[j].quantidade){
				aux=vetor_principal[i];
				vetor_principal[i]=vetor_principal[j];
				vetor_principal[j]=aux;
			}
		}
	}
}

int main (){
	FILE *leitura_string;
	Elemento vetor_principal[50000000];
	char string[300]={0};
	int i=0,tam=0,tam2=0;

	leitura_string=fopen("Arquivo.txt","r");

	if(leitura_string==NULL){
		printf ("ERRO NA LEITURA DO ARQUIVO\n");
	}

	//CONTINUANDO O PROGRAMA
	while(fscanf(leitura_string," %s",string) != EOF){
		tam=strlen(string);
		transforma(string,tam);
		criarOutros(vetor_principal,string,tam,&tam2);
	}



	printf ("[ %d ]\n", tam2);
	ordenar(vetor_principal,tam2);
	tam2=100;
	printar(vetor_principal,tam2);


	printf ("[ %d ]\n", tam2);

	printf ("\nFIM \n");
	fclose(leitura_string);
	return 0;
}