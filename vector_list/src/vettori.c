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
	typedef vettore[MAX];

	vettore a; //alloca vettore di tipo "vettore" con nome a
	memset(a, '\0', MAX); //inizializza tutti gli elementi di a con simbolo vuoto
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

