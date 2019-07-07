// Comando para compilação:
// gcc divida_conquiste_lcs.c -o dc_lcs
// Comando para rodar:
// ./dc_lcs

#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>

// Assinaturas das funções
int max(int a, int b);
int tam_maior_subsequencia( char *texto, char *palavra, int tam_texto, int tam_palavra );

int main() {
	// contagem do tempo
	clock_t tInicio, tFim, tDecorrido;
	tInicio = clock();
	// temporaria para contagem de caracteres
	char ch;

	// Coleta dos nomes das sequencias que serão comparadas
	printf("Digite o numero de caracteres da sequencia 1: ");
	int tam_seq1 = 0;
	scanf("%d", &tam_seq1);
	printf("Digite o nome do arquivo da sequencia 1: ");
	char nome_seq1[tam_seq1];
	scanf("%s", nome_seq1);

	printf("Digite o numero de caracteres da sequencia 2: ");
	int tam_seq2 = 0;
	scanf("%d", &tam_seq2);
	printf("Digite o nome do arquivo da sequencia 2: ");
	char nome_seq2[tam_seq2];
	scanf("%s", nome_seq2);

	// Exibição dos nomes dos arquivos
	printf("Seq 1: %s - %d\n", nome_seq1, tam_seq1);
	printf("Seq 2: %s - %d\n", nome_seq2, tam_seq2);

	//============= carrega sequencia 1 ===============
	FILE *file1;
    file1 = fopen(nome_seq1, "r");
    
	// Checar se arquivo foi aberto
    if(file1 == NULL) printf("Arquivo inexistente\n");

	// Nota: Estava implementando a contagem automatica de caracteres, mas deixei manual pra focar no que mais importa
	// Contagem de caracteres do arquivo
	/*ch = fgetc(file1);
	while(ch != EOF){
		tam_seq1++;
		ch = fgetc(file1);
		printf("%c\n", ch);
	}
	printf("Num caracteres arq 1: %i\n", tam_seq1);*/

	char seq1[tam_seq1];

    fscanf(file1, "%s", seq1);
	printf("Seq 1: %s\n", seq1);
	fclose(file1);
	//============= carrega sequencia 1 ===============

	//============= carrega sequencia 2 ===============
	FILE *file2;
    file2 = fopen(nome_seq2, "r");
    
    if(file2 == NULL) printf("Arquivo inexistente\n");

	char seq2[tam_seq2];

    fscanf(file2, "%s", seq2);
	printf("Seq 2: %s\n\n", seq2);

	fclose(file2);
	//============= carrega sequencia 2 ===============

	//============= busca por divisão e conquista ===============
	printf("\n\nTamanho da maior subsequencia: %i\n", tam_maior_subsequencia(seq1, seq2, tam_seq1, tam_seq2));
	printf("Maior subsequencia: [não implementado]\n");
	//============= busca por divisão e conquista ===============
	
	// Encerramento do algoritmo
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





// Balde de lixo do código
/*
// Considerações: seq"n" será o Texto, seq"n+1" será a Palavra a ser buscada no texto
// Em sua versão básica a complexidade é O(N*M), sendo N o tamanho da palavra e M o tamanho do texto

 */