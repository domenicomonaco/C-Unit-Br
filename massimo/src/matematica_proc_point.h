/*
 ============================================================================
 Name        : matematica_proc_point.h
 Author      : Domenico Monaco & Michele Chiarello
 Version     :
 Copyright   : Copyright Domenico Monaco and Michele Chiarello 2011
 License     : GPLv2

 Description : Prototipi procedure matematiche con uso dei puntatori

 Feature:

**/

#ifndef _MATEMATICA_PROC_POINT_H_

#define _MATEMATICA_PROC_POINT_H_

#include <stdio.h>
#include <stdlib.h>
#include <math.h>


void inverti(int * a, int * b);
int* summ(int a, int b);
void summ_p(int *a, int *b, int *result);

//divisori di n
void divisori_p(int n, int *divisori[]);

#endif
