// Comando para compilação:
// gcc greedy_lcs.c -o g_lcs
// Comando para rodar:
// ./g_lcs

#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>
#define tam_seq 31	// <<---- indicar num. caracteres nos arquivos (+1 para o caractere de fim de string)

// Considerações: seq"n" será o Texto, seq"n+1" será a Palavra a ser buscada no texto
// Em sua versão básica a complexidade é O(N*M), sendo N o tamanho da palavra e M o tamanho do texto

int busca_subsequencia(char *, char *palavra);

//int count = 0;

int main() {
	// contagem do tempo
	clock_t tInicio, tFim, tDecorrido;
	tInicio = clock();

	char *nome_seq1 = "seq1-10.txt";	// <<---- _ indicar nomes arquivos
	char *nome_seq2 = "seq2-10.txt";	// <<----			
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
	
	
	//============= busca gulosa ===============
	strcpy(palavra_aux, palavra);

	// tenta combinações diminuindo a palavra a partir do fim
    printf("Rodando com diminuição decrecente da segunda sequencia:\n\n");
	for(int i = 1; i < tam_seq; i++){
		posicao = busca_subsequencia(texto, palavra_aux);
		if(posicao != -1){
			//printf("---------------------------------	Texto	: %s\n", texto);
			printf("Iteração: %i - Posição do match: %i -	Palavra	: %s\n", i, posicao+1, palavra_aux);
		}
		// remove ultimo caractere
		palavra_aux[(strlen(palavra_aux)-1)] = '\0';
	}
	printf("\n");

    printf("Rodando com diminuição decrecente da segunda sequencia:\n\n");

	// tenta combinações invertendo as sequencias, diminuindo o texto a partir do fim
	strcpy(palavra_aux, texto);
	char texto_aux[tam_seq];
	strcpy(texto_aux, palavra);

	// tenta combinações com seq1 sendo a palavra
	for(int i = 1; i < tam_seq; i++){
		posicao = busca_subsequencia(texto_aux, palavra_aux);
		
		if(posicao != -1){
			//printf("---------------------------------	Texto	: %s\n", texto);    // descomentar se quizer comparar texto e palavra
			printf("Iteração: %i - Posição do match: %i -	Palavra	: %s\n", i, posicao+1, palavra_aux);
		}
		// remove ultimo caractere
		palavra_aux[(strlen(palavra_aux)-1)] = '\0';
	}
	//============= busca gulosa ===============
	

	tFim = clock();
	tDecorrido = ((tFim - tInicio) / (CLOCKS_PER_SEC / 1000));
	printf("\n\nDuração da execução: %ld ms\n", tDecorrido);

	return 0;
}

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