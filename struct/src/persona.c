/*
 * @filename: persona.c
 * @author: macbook
 * @rev: 0.1
 * @license: GPLV2
 * @date: 09/mag/2011
 * @desc: 
 */

#include <stdio.h>
#include <stdlib.h>
#include "persona.h"

void scrivi_persone_righe(persona* persone, FILE *fp, int n_righe) {

	if ((fp = fopen("persone.csv", "w")) == NULL) {
		printf("Errore in apertura del file!");
	} else {

		int i;
		for (i = 0; i < n_righe; i++) {

			fprintf(fp, "%s , %s , %s , %s , %s ; ",
					(persone + i)->nome,
					(persone + i)->cognome,
					(persone + i)->genere,
					(persone + i)->datadinascita,
					(persone + i)->cf);
		}
		fclose(fp);
	}
}

void leggi_persone_righe(persona* persone, FILE *fp, int n_righe) {

	if ((fp = fopen("persone.csv", "r")) == NULL) {
		printf("Errore in apertura del file!");
	} else {

		int i;
		for (i = 0; i < n_righe; i++) {
			fscanf(fp, "%s, %s, %s, %s, %s; ", (persone + i)->nome,
					(persone + i)->cognome, (persone + i)->genere,
					(persone + i)->datadinascita, (persone + i)->cf);
		}

		fclose(fp);
	}
}

void stampa_persone_righe(persona* persone, int n_righe) {
	int i;
	for (i = 0; i < n_righe; i++) {
		printf("## PERSONA %d ##\nNome: %s\nCognome: %s\nGenere: %s\nData di nascita: %s\nCodice Fiscale: %s\n\n",
				i,
				(persone + i)->nome,
				(persone + i)->cognome,
				(persone + i)->genere,
				(persone + i)->datadinascita,
				(persone + i)->cf
				);
	}
}
