// gcc main.c -o main

#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#define tam_seq 11	// <<---- indicar num. caracteres nos arquivos

// Considerações: seq"n" será o Texto, seq"n+1" será a Palavra a ser buscada no texto
// Em sua versão básica a complexidade é O(N*M), sendo N o tamanho da palavra e M o tamanho do texto

int maior_subsequencia( char *texto, char *palavra, int tam_texto, int tam_palavra );
int max(int a, int b);

int count = 0;

int main() {
	char *nome_seq1 = "seq1-10.txt";	// <<---- _ indicar nomes arquivos
	char *nome_seq2 = "seq2-10.txt";	// <<----			
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

	//============= busca por divisão e conquista ===============
	int tam_texto = strlen(texto);
	int tam_palavra = strlen(palavra);
	printf("O tamanho da maior subsequencia comum eh: %i\n", maior_subsequencia(texto, palavra, tam_texto, tam_palavra));
	printf("A maior subsequencia eh: [não implementado]\n");
	//============= busca por divisão e conquista ===============

	return 0;
}

// função divisão e conquista
int maior_subsequencia( char *texto, char *palavra, int tam_texto, int tam_palavra ){
    if (tam_texto == 0 || tam_palavra == 0) return 0;
    if (texto[tam_texto-1] == palavra[tam_palavra-1]){
		return 1 + maior_subsequencia(texto, palavra, tam_texto-1, tam_palavra-1);
	}else return max(maior_subsequencia(texto, palavra, tam_texto, tam_palavra-1), maior_subsequencia(texto, palavra, tam_texto-1, tam_palavra));
}

int max(int a, int b){ return (a > b)? a : b; }

// função força bruta (2 loops)