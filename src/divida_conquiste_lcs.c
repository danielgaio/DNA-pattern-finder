// Comando para compilação:
// gcc divida_conquiste_lcs.c -o dc_lcs
// Comando para rodar:
// ./dc_lcs

#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>
#define tam_seq 31	// <<---- indicar num. caracteres nos arquivos (+1 para o caractere de fim de string)

// Considerações: seq"n" será o Texto, seq"n+1" será a Palavra a ser buscada no texto
// Em sua versão básica a complexidade é O(N*M), sendo N o tamanho da palavra e M o tamanho do texto

int max(int a, int b);
int tam_maior_subsequencia( char *texto, char *palavra, int tam_texto, int tam_palavra );

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
	

	//============= busca por divisão e conquista ===============
	int tam_texto = strlen(texto);
	int tam_palavra = strlen(palavra);
	printf("\n\nO tamanho da maior subsequencia comum eh: %i\n", tam_maior_subsequencia(texto, palavra, tam_texto, tam_palavra));
	printf("A maior subsequencia eh: [não implementado]\n");
	//============= busca por divisão e conquista ===============
	

	tFim = clock();
	tDecorrido = ((tFim - tInicio) / (CLOCKS_PER_SEC / 1000));
	printf("\n\nDuração da execução: %ld ms\n", tDecorrido);

	return 0;
}

// função divisão e conquista
int tam_maior_subsequencia( char *texto, char *palavra, int tam_texto, int tam_palavra ){
	// base de recurção
    if (tam_texto == 0 || tam_palavra == 0){
		return 0;
	}
    if (texto[tam_texto-1] == palavra[tam_palavra-1]){
		return 1 + tam_maior_subsequencia(texto, palavra, tam_texto-1, tam_palavra-1);
	}else return max(tam_maior_subsequencia(texto, palavra, tam_texto, tam_palavra-1), tam_maior_subsequencia(texto, palavra, tam_texto-1, tam_palavra));
}

int max(int a, int b){ return (a > b)? a : b; }