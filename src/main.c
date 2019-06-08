// gcc main.c header.h functions.c -o main

#include <stdio.h>
#include <string.h>

int main() {
	char *nome_seq1 = "seq1.txt";
	char *nome_seq2 = "seq2.txt";
	int tam_seq = 1001;

	//============= carrega sequencia 1 ===============
	FILE *file1;
    file1 = fopen(nome_seq1, "r");
    
    if(file1 == NULL) printf("Arquivo inexistente\n");

	char seq1[tam_seq];

    fscanf(file1, "%s", seq1);

	printf("%s\n", seq1);
	//============= carrega sequencia 1 ===============

	//============= carrega sequencia 2 ===============
	FILE *file2;
    file2 = fopen(nome_seq2, "r");
    
    if(file2 == NULL) printf("Arquivo inexistente\n");

	char seq2[tam_seq];

    fscanf(file2, "%s", seq2);

	printf("%s\n", seq2);
	//============= carrega sequencia 2 ===============

	//search(pat, txt);

	return 0;
}