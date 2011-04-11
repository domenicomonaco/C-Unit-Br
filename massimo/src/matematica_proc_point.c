/*
 ============================================================================
 Name        : matematica_proc_point.c
 Author      : Domenico Monaco & Michele Chiarello
 Version     :
 Copyright   : Copyright Domenico Monaco and Michele Chiarello 2011
 License     : GPLv2

 Description : Implementazione procedure matematiche con uso dei puntatori

 Feature:

 **/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void inverti(int * a, int * b) {
	int t = *a;

	*a = *b;
	*b = t;
}

int* summ(int a, int b) {
	int* sum = NULL;
	sum = (int*) malloc(sizeof(int));
	if (sum != NULL)
		*sum = a + b;
	return sum;
}

void summ_p(int const *a, int const *b, int *result) {
	*result = *a + *b;
}

void divisori_p(int n, int *divisori) {

	int i;
	long double c; //variabile di appoggio
	for (i = 2; i <= n; i++) {
		if (divisori[i] != i) {
			c = n / i;
			if (c == (int) c) {

				//*divisori[i] = i;
				//*divisori[(int) c] = (int) c;
			}
		}else{
			i=n;
		}
	}
}
