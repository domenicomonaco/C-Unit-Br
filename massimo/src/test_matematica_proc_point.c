/*
 ============================================================================
 Name        : matematica_proc_point.c
 Author      : Domenico Monaco & Michele Chiarello
 Version     :
 Copyright   : Copyright Domenico Monaco and Michele Chiarello 2011
 License     : GPLv2

 Description : Implementzione procedure di test per le procedure matematiche_proc_point

**/
#include <stdio.h>
#include <stdlib.h>
#include "CUnit/basic.h"

#include "matematica_proc_point.h"

void test_inverti(void) {
	int a, b;

	a = 9;
	b = 33;

	int c, d;

	c = b;
	d = a;
	inverti(&a, &b);

	CU_ASSERT((a == c && b == d));
}

void test_summ_p(void) {
	int *a = (int*) malloc(sizeof(int));
	int *b = (int*) malloc(sizeof(int));
	int *sum = (int*) malloc(sizeof(int));

	*a = 4;
	*b = 9;
	summ_p(a, b, sum);
	CU_ASSERT((*sum == 13));

	*a = 0;
	*b = 1;
	summ_p(a, b, sum);
	CU_ASSERT((*sum == 1));

	*a = -10;
	*b = 5;
	summ_p(a, b, sum);
	CU_ASSERT((*sum == -5));

	*a = -10;
	*b = -20;
	summ_p(a, b, sum);
	CU_ASSERT((*sum == -30));

	*a = 230;
	*b = -20;
	summ_p(a, b, sum);
	CU_ASSERT((*sum == 210));

	*a = -230;
	*b = -20;
	summ_p(a, b, sum);
	CU_ASSERT((*sum == -250));

	free(sum);
	free(a);
	free(b);
}
