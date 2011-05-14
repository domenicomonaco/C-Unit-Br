/*
 * @filename: persona.h
 * @author: macbook
 * @rev: 0.1
 * @license: GPLV2
 * @date: 09/mag/2011
 * @desc: 
 */



#ifndef PERSONA_H_
#define PERSONA_H_

#define DIM 25

typedef struct {
	char *nome;
	char *cognome;
	char *genere;
	char *datadinascita;
	char *cf;
} persona;

void scrivi_persone_righe(persona* persone, FILE *fp, int n_righe);

void leggi_persone_righe(persona* persone, FILE *fp, int n_righe);

void stampa_persone_righe(persona* persone, int n_righe);

#endif /* PERSONA_H_ */
