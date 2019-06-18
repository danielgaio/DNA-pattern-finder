// gcc main.c -o main

#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#define tam_seq 101	// <<---- indicar num. caracteres nos arquivos

// Considerações: seq"n" será o Texto, seq"n+1" será a Palavra a ser buscada no texto
// Em sua versão básica a complexidade é O(N*M), sendo N o tamanho da palavra e M o tamanho do texto

int tam_maior_subsequencia( char *texto, char *palavra, int tam_texto, int tam_palavra );
int max(int a, int b);
int busca_subsequencia(char *, char *palavra);

int count = 0;

int main() {
	char *nome_seq1 = "seq7-100.txt";	// <<---- _ indicar nomes arquivos
	char *nome_seq2 = "seq8-100.txt";	// <<----			
	char palavra_aux[tam_seq];
	int posicao;

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



	//============= busca força bruta ===============
	strcpy(palavra_aux, palavra);

	// tenta combinações diminuindo a palavra a partir do fim
	for(int i = 1; i < tam_seq; i++){
		posicao = busca_subsequencia(texto, palavra_aux);
		
		if(posicao != -1){
			printf("                                  	texto	: %s\n", texto);
			printf("iteração: %i - posição match: %i -	palavra	: %s\n", i, posicao+1, palavra_aux);
			//sleep(1);
		}
		
		

		// remove ultimo caractere
		palavra_aux[(strlen(palavra_aux)-1)] = '\0';
	}
	printf("\n");

	//sleep(2);

	strcpy(palavra_aux, texto);
	char texto_aux[tam_seq];
	strcpy(texto_aux, palavra);

	// tenta combinações com seq1 sendo a palavra
	for(int i = 1; i < tam_seq; i++){
		posicao = busca_subsequencia(texto_aux, palavra_aux);
		
		if(posicao != -1){
			printf("                                  	texto	: %s\n", texto);
			printf("iteração: %i - posição match: %i - 	palavra	: %s\n", i, posicao+1, palavra_aux);
			//sleep(1);
		}

		

		// remove ultimo caractere
		palavra_aux[(strlen(palavra_aux)-1)] = '\0';
	}

	

	//sleep(2);
	posicao = busca_subsequencia(texto, "ta");
	printf("\n                   	texto	: %s\n", texto);
	printf("posição match: %i -	palavra	: ta\n\n", posicao+1);
	





	//============= busca força bruta ===============


	//============= busca por divisão e conquista ===============
	int tam_texto = strlen(texto);
	int tam_palavra = strlen(palavra);
	printf("O tamanho da maior subsequencia comum eh: %i\n", tam_maior_subsequencia(texto, palavra, tam_texto, tam_palavra));
	printf("A maior subsequencia eh: [não implementado]\n");
	//============= busca por divisão e conquista ===============

	return 0;
}

// função divisão e conquista
int tam_maior_subsequencia( char *texto, char *palavra, int tam_texto, int tam_palavra ){
    if (tam_texto == 0 || tam_palavra == 0) return 0;
    if (texto[tam_texto-1] == palavra[tam_palavra-1]){
		return 1 + tam_maior_subsequencia(texto, palavra, tam_texto-1, tam_palavra-1);
	}else return max(tam_maior_subsequencia(texto, palavra, tam_texto, tam_palavra-1), tam_maior_subsequencia(texto, palavra, tam_texto-1, tam_palavra));
}

int max(int a, int b){ return (a > b)? a : b; }

// função força bruta (2 loops)
int busca_subsequencia(char *texto, char *palavra){
   	int c;
   	int posicao_match = 0;
   	char *x, *y;
   
   	x = texto;
   	y = palavra;

	// enquanto houver texto
	while(*texto){
		// verifica se caractere da palavra é igual ao do texto
      	while(*x == *y){
         	x++;
         	y++;
		 	// se o texto ou a palavra terminar, pare
         	if(*x == '\0' || *y == '\0') break;
      	}
      	if(*y == '\0') break;

      	texto++;
      	posicao_match++;
      	x = texto;
      	y = palavra;
   	}
   	if(*texto) return posicao_match;
   	else return -1;
}