/*
 ============================================================================
 Name        : test_matematica_function.c
 Author      : Domenico Monaco & Michele Chiarello
 Version     :
 Copyright   : Copyright Domenico Monaco and Michele Chiarello 2011
 License     : GPLv2

 Description : Implementzione procedure di test per le procedure matematiche_function.c

 **/

#include <stdio.h>
#include <stdlib.h>
#include "CUnit/basic.h"

#include "matematica_function.h"

//test per massimo()
void test_massimo(void) {
	CU_ASSERT_EQUAL(massimo(1, 2), 2);
	CU_ASSERT(massimo(0, -2) == 0);
	CU_TEST(massimo(2, 2) == 2);
}

void test_minimo(void) {
	CU_ASSERT_EQUAL(minimo(1, 10), 1); // DUE NUMERI POSITIVI

	CU_ASSERT(minimo(-234, -2) == -234); //due numero negativi
	CU_ASSERT(minimo(23, -4) == -4); //1 negativo e 1 positivo
	CU_ASSERT(minimo(-234, -2) == -234); //due numero negativi

	CU_TEST(minimo(0, -120) == -120); //zero e negativo
	CU_TEST(minimo(34, 0) == 0); //zero e positivo
	CU_TEST(minimo(0, 0) == 0); //zero e Zero
}

void test_fattoriale(void) {
	CU_ASSERT_EQUAL(fattoriale(0), 1); //caso con 0
	CU_ASSERT_EQUAL(fattoriale(1), 1); //caso particolare con 1

	CU_ASSERT_EQUAL(fattoriale(2), 2); //caso di numero intero con 2 ma nell'implementazione pu˜ essere un problema
	CU_ASSERT_EQUAL(fattoriale(3), 6); //Caso classico 13

	CU_ASSERT_EQUAL(fattoriale(-0), 1); //caso strano con -0 zero

	CU_ASSERT_EQUAL(fattoriale(-132), 0); //caso con numero negativo
}

void test_signof(void) {
	CU_ASSERT_EQUAL(signof(0), 1);
	CU_ASSERT_EQUAL(signof(-10), -1);
	CU_ASSERT_EQUAL(signof(-1), -1);
	CU_ASSERT_EQUAL(signof(343), 1);
	CU_ASSERT_EQUAL(signof(1), 1);
}

void test_prodotto(void) {
	CU_ASSERT_EQUAL(prodotto(34, 43), 1462);
	CU_ASSERT_EQUAL(prodotto(-13, 22), -286);
	CU_ASSERT_EQUAL(prodotto(-12, -20), 240);

	CU_ASSERT_EQUAL(prodotto(0, 0), 0);
	CU_ASSERT_EQUAL(prodotto(0, 1), 0);
	CU_ASSERT_EQUAL(prodotto(0, -1), -0);
	CU_ASSERT_EQUAL(prodotto(0, 22234), 0);

}

void test_divisione(void) {

	CU_ASSERT_EQUAL(divisione(1, 1), 1);
	CU_ASSERT_EQUAL(divisione(0, 1), 0);

	CU_ASSERT_EQUAL(divisione(15, 5), 3);
	CU_ASSERT_EQUAL(divisione(27, 3), 9);

	CU_ASSERT_EQUAL(divisione(45, 8), 5.625);

	CU_ASSERT(divisione(190, 23) >= 8.260869 && divisione(190, 23) <= 8.26087); //errore se ometto  && divisione(190,23) <= 8.26087
	CU_ASSERT(divisione(45, 254) >= 0.177165 && divisione(45, 254) <= 0.17717);

}

void test_somma(void) {
	CU_ASSERT_EQUAL(somma(1, 1), 2); //positivo + Positivo
	CU_ASSERT_EQUAL(somma(267, 324), 591); //positivo + positivo

	CU_ASSERT_EQUAL(somma(459, -47), 412); //positivo + negativo
	CU_ASSERT_EQUAL(somma(-37, 224), 187); //negativo + positivo
	CU_ASSERT_EQUAL(somma(-60, -94), -154); //negativo + negativo


	CU_ASSERT_EQUAL(somma(0, -48), -48); //0 + negativo
	CU_ASSERT_EQUAL(somma(-38, 0), -38); // negativo + 0

	CU_ASSERT_EQUAL(somma(0, 35), 35); //0 + positivo
	CU_ASSERT_EQUAL(somma(89, 0), 89); //positivo + 0

}

void test_sottrazione(void) {

	CU_ASSERT_EQUAL(sottrazione(1, 1), 0);
	CU_ASSERT_EQUAL(sottrazione(0, 1), -1);
	CU_ASSERT_EQUAL(sottrazione(1, 0), 1);
	CU_ASSERT_EQUAL(sottrazione(0, 0), 0);

	CU_ASSERT_EQUAL(sottrazione(120, 243), -123);
	CU_ASSERT_EQUAL(sottrazione(-24, 123), -147);
	CU_ASSERT_EQUAL(sottrazione(93, -32), 125);
	CU_ASSERT_EQUAL(sottrazione(-58, -38), -20);

	CU_ASSERT_EQUAL(sottrazione(0, 22), -22);
	CU_ASSERT_EQUAL(sottrazione(123, 0), 123);

	CU_ASSERT_EQUAL(sottrazione(0, -56), 56);
	CU_ASSERT_EQUAL(sottrazione(-47, 0), -47);

}
