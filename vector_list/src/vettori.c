/*
 * @filename: vettori.c
 * @author: macbook
 * @rev: 0.1
 * @license: GPLV2
 * @date: 09/apr/2011
 * @desc: 
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 10

#define MAXWORD 1000

/*
 * Esercizio 2
 * Usare la typedef per creare un tipo vettore di interi di dimensione MAX (es MAX 10)
 *
 * Creare un array di tipo vettore e avvalorarlo con interi letti da tastiera
 * Dopodiche stampare a video il contenuto del vettore e la somma totale degli elementi
 * Realizzate il codice nel main senza invocare altre procedure o funzioni
 */

/*
 * Esercizio 2
 * Usare la typedef per creare un tipo vettore di interi di dimensione MAX (es MAX 10)
 */
void vector_init(char init) {
	//typedef vettore[MAX];
	int a[100];
	memset(a, '\0', MAX); //inizializza tutti gli elementi di a con simbolo vuoto
}

/*
 * @desc: inizializza un vettore ad interi di dimensione arbitraria
 */
int * vector_int_alloc(int dim) {
	int* vector = (int*) calloc(dim, sizeof(int));
	return vector;
}

/*
 * @desc: inizializza un vettore a float di dimensione arbitraria
 */
float * vector_f_alloc(int dim) {
	float* vector = (float*) calloc(dim, sizeof(float));
	return vector;
}

/*
 * @desc: inizializza un vettore ad char di dimensione arbitraria
 */
char * vector_c_alloc(int dim) {
	char* vector = (char*) calloc(dim, sizeof(char));
	return vector;
}

/*
 * Creare un array di tipo vettore e avvalorarlo con interi letti da tastiera
 */
void vector_scan() {
	int A[MAX];
	int i;
	for (i = 0; i < MAX; i++) {
		printf("Vettore A: Inserire %d-esimo numero = ", i);
		scanf("%d", &A[i]);
	}

	for (i = 0; i < MAX; i++) {
		printf("%d, ", A[i]);
	}

	int somma;
	for (i = 0; i < MAX; i++) {
		somma = somma + A[i];
	}
	printf("La somma dei %d  %d", MAX, somma);

}

/*
 * Esercizio 3
 * Scrivere un programma che:
 * definisca il tipo vettore di lunghezza massima 10 interi con una typedef
 * definisca due vettori A e B di 5 interi, avvalorati da tastiera, ancora con una typedef
 * definisca un vettore C di 10 interi che conterra gli elementi di A seguiti da quelli di B;
 * e stampi a video gli elementi del vettore C
 *
 * Realizzate il codice nel main senza invocare altre procedure o funzioni
 */
void vector_merge() {
	typedef vettore[MAX];
	vettore A, B;

	int C[(MAX + MAX)];

	int i;
	for (i = 0; i < MAX; i++) {
		printf("Vettore A: Inserire %d-esimo numero = ", i);
		scanf("%d", &A[i]);
	}

	for (i = 0; i < MAX; i++) {
		printf("Vettore B: Inserire %d-esimo numero = ", i);
		scanf("%d", &B[i]);
	}

	int i_bis = 0;
	for (i = 0; i < (MAX * 2); i++) {
		if (i < MAX) {
			C[i] = A[i];
		} else {
			C[i] = B[i_bis];
			i_bis++;
		}
	}
	for (i = 0; i < (MAX * 2); i++) {
		printf("%d, ", C[i]);
	}
}

/*
 * Esercizio 6 Ð per casa
 * Scrivere una funzione int conta_parole(const char* str) che conta le parole separate dagli spazi in una stringa
 * Come distinguere lo spazio dagli altri caratteri??? Ð Suggerimento: cercate nelle librerie standard del C
 * Dimostrarne la correttezza con un opportuno caso di test CUnit
 *
 */

/*
 * @desc: Conta le parole con l'uso di strtok
 * @param: const char *str = puntatore a stringa, in particolare necessita di un char a[X]
 *
 */
int conta_parole_bis(const char *str) {
	char* w;

	w = strtok(str, " ,.:;-_#*-+@!£$%&/|\()=?'<>");

	int countword = 0;

	while (w != NULL) {
		printf("parola %s \n ", w);
		// Usa la stessa stringa di prima
		w = strtok(NULL, " ,.:;-_#*-+@!£$%&/|\()=?'<>");
		countword++;
	}

	return countword;
}

int conta_parole(const char *str) {
	int i = 1;

	int spaces = 0;

	while (i != 0) {
		//printf("%c", *(str+i-1));
		i++;

		if (i > 1 && *(str + i - 1) == ' ' && *(str + i) != '\0') {
			spaces++;
		} else if (i > 1 && *(str + i - 2) != ' ' && *(str + i - 1) == '\0') {
			spaces++;
		}

		if (*(str + i - 1) == '\0') {
			i = 0;
		} else {
			i++;
		}

	}

	return spaces;
}

/**
 * @param:
 * 	a: puntatore a interi
 * 	dim: dimensione del vettore da popolare
 *
 * @desc: popola un array di interi con valori da tastiera
 */
void inputarray(int* a, const int dim) {
	int i;
	printf("Inserisci i valori dell'array: \n");
	for (i = 0; i < dim; i++) {
		printf("a[%d]=", i);
		scanf("%d", (a + i));
	}
	printf("\nGrazie! Abbiamo finito di inserire valori.\n");
}

void outputarray(const int* a, const int dim) {
	int i;
	printf("\nI valori dell'array sono \n");
	for (i = 0; i < dim; i++) {
		printf("a[%d]=%d \n", i, *(a + i));
	}
}

/**
 * Esercizio
 *
 * @desc: Funzione che fa uso di strcat
 * 	prende da tastiera nome e cognome separatamente
 *
 * @output: restituise un puntatore/array carattere
 * 	come risilutato da le due parole concatenate e separate da spazio
 *
 * @example:
 * char* output = nomecognome();
 * printf("%s",output);
 *
 */

char* nomecognome() {
	char nome[MAX * 5];
	char cognome[MAX * 2];

	printf("Inserisci il nome: ");
	scanf("%s", nome);

	printf("Inserisci il cognome: ");
	scanf("%s", cognome);

	strcat ( nome, " ");
	strcat ( nome, cognome);

	return nome;
}

/*
 * @param:
 * 	@input pointer int array
 *	@output pointer int var
 *	@dim of input array
 *
 * @output:
 * 	@output pointer to int of SUM
 */

void array_somma(int* input, int * output, int dim) {
	*(output) = *(input - 1);

	while (dim > 0) {
		*(output) = *(output) + *(input + (dim - 1));
		dim--;
	}
}

/**
 * @param:
 * 	input puntatore ad interi - vettore di dimensione "dim"
 *	dim dimensione del vettore precedente
 *
 * @output:
 * 	max = valore massimo dell'array
 */
int array_max(const int* input, int dim) {

	//inizializza Min con il primo valore dell'array
	//Se l'array input  dim=1, sarˆ l'unico valore
	int max = *(input);

	while (dim > 0) {
		if (*(input + (dim - 1)) >= max) {
			max = *(input + (dim - 1));
		}
		dim--;
	}
	return max;
}

/**
 * @param:
 * 	input puntatore ad interi - vettore di dimensione "dim"
 *	dim dimensione del vettore precedente
 *
 * @output:
 * 	min = valore minimo dell'array
 */
int array_min(const int* input, int dim) {

	//inizializza Min con il primo valore dell'array
	//Se l'array input  dim=1, sarˆ l'unico valore
	int min = *(input);

	//loop su *input con indice dim
	//usa dim come indice per iterare, quindi parte dalla fine dell'array
	while (dim > 0) {
		if (*(input + (dim - 1)) <= min) {
			min = *(input + (dim - 1));
		}
		dim--;
	}
	return min;
}
