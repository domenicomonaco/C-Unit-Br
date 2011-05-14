/*
 ============================================================================
 Name        : struct.c
 Author      : Domenico Monaco & Michele Chiarello
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

#include "persona.h"

int main(void) {

	int n_persone;
	printf("Inserisci numero di persone del gruppo: ");
	scanf("%d", &n_persone);

	persona* gruppodilavoro = (persona*) calloc(n_persone, sizeof(persona));

	int i;
	for (i = 0; i < n_persone; i++) {

		(gruppodilavoro + i)->nome = (char*) calloc(25, sizeof(char));

		(gruppodilavoro + i)->cognome = (char*) calloc(25, sizeof(char));
		(gruppodilavoro + i)->genere = (char*) calloc(2, sizeof(char));
		(gruppodilavoro + i)->datadinascita = (char*) calloc(11, sizeof(char));
		(gruppodilavoro + i)->cf = (char*) calloc(17, sizeof(char));

		printf("\n Inserisci dati perosna %d \n", i);

		printf("\n Nome:");
		scanf("%s", (gruppodilavoro + i)->nome);

		printf("\n Cognome:");
		scanf("%s", (gruppodilavoro + i)->cognome);

		printf("\n Genere [m/f]:");
		scanf("%s", (gruppodilavoro + i)->genere);

		printf("\n Data di nascita [gg/mm/AAAA]:");
		scanf("%s", (gruppodilavoro + i)->datadinascita);

		printf("\n Codice Fiscale:");
		scanf("%s", (gruppodilavoro + i)->cf);

		printf("\n");

	}

	//Scrivi File

	FILE *fp;
	scrivi_persone_righe(gruppodilavoro, fp, n_persone);

	//printf("test");

	//persona* gruppodilavoro_controllo = (persona*) calloc(n_persone, sizeof(persona));

	//leggi_persone_righe(gruppodilavoro_controllo, fp, n_persone);

	//stampa_persone_righe(gruppodilavoro_controllo, n_persone);

	return EXIT_SUCCESS;
}

