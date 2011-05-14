/*
 ============================================================================
 Name        : principale.c
 Author      : Domenico Monaco & Michele Chiarello
 Version     :
 Copyright   :
 Description :
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

#include "vettori.h"

int main(int argc, char *argv[]) {
	/* prints !!!Hello World!!! */
	puts("## Welcome to Monaco Script ##");

	int in = 'n';
	char i;
	while (in != 's') {
		if (in == 's' || in == 'n') {
			puts("Proseguire? [s/n]"); //stampa su righe diverse, quindi con \n finale invece di \0.
			i++;
			scanf("%1c", &in);
			if (in == 'n') {
				printf(
						"Peccato hai selezionato: %c durante l'%d -esima volta \n",
						in, i);
			}
		}
	}

	printf("Grazie %c" ", %d \n", in, i);

float mat[4][3] = {
					{1, 0, 0},
					{0, 1, 0},
					{0, 0, 1},
					{0, 0, 0}
				};

	int matrix[][4] = { {1, 0, 0, 0}, {0, 1, 0, 0}, {0, 0, 1, 0}, {0, 0,
			0, 1}};





	return EXIT_SUCCESS;
}
