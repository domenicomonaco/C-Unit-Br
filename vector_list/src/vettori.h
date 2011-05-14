/*
 * @filename: vettori.h
 * @author: macbook
 * @rev: 0.1
 * @license: GPLV2
 * @date: 09/apr/2011
 * @desc: Funzioni e Procedure per effettuare operazioni comuni su vettori
 */



#ifndef VETTORI_H_
#define VETTORI_H_

int* vector_int_alloc(int dim);
float* vector_f_alloc(int dim);
char* vector_c_alloc(int dim);

void vector_init(char init);

void vector_scan();
void vector_merge();

void inputarray(int* a, const int dim);
void outputarray(int* a, const int dim);

int conta_parole(const char* str);
int conta_parole_bis(const char *str);

char* nomecognome();

void array_somma(const int* input, int* output, const int dim);

int array_max(const int* input, int dim);
int array_min(const int* input, int dim);

#endif /* VETTORI_H_ */
