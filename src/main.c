// gcc main.c header.h functions.c -o main

#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>

// Considerações seq"n" será o Texto, seq"n+1" será a Palavra a ser buscada no texto
// Em sua versão básica a complexidade é O(N*M), sendo N o tamanho da palavra e M o tamanho do texto

int match(char *a, char *b);

int main() {
	char *nome_seq1 = "seq1-10.txt";	// <<---- _ indicar nomes arquivos
	char *nome_seq2 = "seq2-10.txt";	// <<----
	int tam_seq = 11;				// <<---- indicar num. caracteres nos arquivos
	char palavra_aux[tam_seq];
	int posicao, flag_parada = 0, leitura_reversa = 1;

	//============= carrega sequencia 1 ===============
	FILE *file1;
    file1 = fopen(nome_seq1, "r");
    
    if(file1 == NULL) printf("Arquivo inexistente\n");

	char texto[tam_seq];

    fscanf(file1, "%s", texto);

	printf("Seq 1: %s\n", texto);
	//============= carrega sequencia 1 ===============

	//============= carrega sequencia 2 ===============
	FILE *file2;
    file2 = fopen(nome_seq2, "r");
    
    if(file2 == NULL) printf("Arquivo inexistente\n");

	char palavra[tam_seq];

    fscanf(file2, "%s", palavra);

	printf("Seq 2: %s\n\n", palavra);
	//============= carrega sequencia 2 ===============

	strcpy(palavra_aux, palavra);

	int p = 0;
	int tam_palavra = strlen(palavra_aux);
	while(flag_parada == 0){
		tam_palavra = strlen(palavra_aux);
		while(tam_palavra > 0){
			printf("Log: flag_parada: %i - tam_palavra: %i - palavra_aux: %s - posicao: %i - leitura_reversa: %i\n", flag_parada, tam_palavra, palavra_aux, posicao, leitura_reversa);
			posicao = match(texto, palavra_aux);
			if(posicao > 1){
				printf("match na posicao: %i\nMaior subsequencia: %s\n", posicao+1, palavra_aux);
				flag_parada = 1;
				// break;
			}
			else printf("no match\n");
			if(leitura_reversa == 1)
				palavra_aux[(strlen(palavra_aux)-1)] = '\0';
			else{
				//char palavra_aux_2[tam_seq];
				//strcpy(palavra_aux_2, palavra_aux);
				palavra_aux[p], "";
				//printf("\n\npalavra_aux_2: %s\n\n", palavra_aux_2);
				//strcpy(palavra_aux, palavra_aux_2);
				printf("\n\npalavra_aux: %s\n\n", palavra_aux);
				tam_palavra--;
				sleep(3);
				p++;
			}
			sleep(1);
			tam_palavra = strlen(palavra_aux);
		}
		strcpy(palavra_aux, palavra);
		leitura_reversa = 0;
		printf("Fora primeiro while\n");
	}

	//============= busca p/ força bruta ===============
	//int tam_texto = strlen(texto);

	//int tam_palavra = strlen(palavra);
	/* A loop to slide pat[] one by one */
	//for (int i = 0; i <= (tam_texto - tam_palavra); i++){
	
	/*
	while(strlen(palavra) != 0){
		
		maior_seq = strstr(texto, palavra);
		
		printf(maior_seq);
		if(maior_seq)
			printf("\npalavra que deu match> %s\n", palavra);
		//int j;

		
		// For current index i, check for pattern match
		for (j = 0; j < tam_palavra; j++){
			printf("palavra: %s (%i) - padrão no texto: ", palavra, tam_palavra);
			for(int k=i; k<(i+j); k++){
				printf("%c", texto[k]);
			}
			printf("\n");
			sleep(1);
			if (texto[i + j] != palavra[j]) break; // se não parar, do indice i do texto até i+j, temos um padrão
		}

		if (j == tam_palavra){ // if pat[0...tam_palavra-1] = txt[i, i+1, ...i+tam_palavra-1]
			printf("Pattern found at index %d do texto - tam_texto: %i - tam_palavra: %i - palavra: %s\n", i, tam_texto, tam_palavra, palavra);
			maior_seq = palavra;
			printf("maior sequencia: %s\n", maior_seq);
			break;
		}
		*/
		//palavra[(strlen(palavra)-1)] = '\0';
		//tam_palavra = strlen(palavra);
	//}
	//============= busca p/ força bruta ===============

	return 0;
}

int match(char *a, char *b){
   int c;
   int position = 0;
   char *x, *y;
   
   x = a; // texto
   y = b; // palavra
   
   while(*a){
      while(*x == *y){
         x++;
         y++;
         if(*x == '\0' || *y == '\0') break;
      }
      if(*y == '\0') break;
         
      a++;
      position++;
      x = a;
      y = b;
   }
   if(*a)
      return position;
   else  
      return -1;  
}