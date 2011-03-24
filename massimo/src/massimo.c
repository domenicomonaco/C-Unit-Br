/*
 ============================================================================
 Name        : massimo.c
 Author      : Domenico Monaco & Michele Chiarello
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style

 Feature:

  MASSIMO 			OK
  MINIMO 			OK

  SOMMA
  SOTRAZIONE

  PRODOTTO 			OK
  SIGN 				OK

  FATTORIZAZIONE 	OK

 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "CUnit/basic.h"
#include <math.h>

//Declaration functions
int massimo(int a, int b);
int minimo(int a, int b);
int fattoriale(int a);
int signof(int a);
int prodotto(int a, int b);
int somma(int a, int b);
int sottrazione(int a, int b);

//Decalaration of Test Functions
void test_massimo();
void test_minimo();
void test_fattoriale();
void test_signof();
void test_prodotto(void);
void test_somma(void);
void test_sottrazione(void);

/**
 * Funzioni di inizializzazione e pulizia delle suite.
 * Di default sono funzioni vuote.
 */
int suite_void_init(void) {
	return 0;
}

int suite_void_cleanup(void) {
	return 0;
}

int main(void) {
	CU_ErrorCode error;

	//TEST ARRAY
	/* Test Arrays - NOTA – L’ORDINE E’ IMPORTANTE */
	CU_TestInfo test_array_somma[] = {
			{ "test di somma()", test_somma },
			CU_TEST_INFO_NULL, };
	//TEST ARRAY
	/* Test Arrays - NOTA – L’ORDINE E’ IMPORTANTE */
	CU_TestInfo test_array_sottrazione[] = {
			{ "test di sottrazione()", test_sottrazione },
			CU_TEST_INFO_NULL, };

	//TEST ARRAY
	/* Test Arrays - NOTA – L’ORDINE E’ IMPORTANTE */
	CU_TestInfo test_array_prodotto[] = {
			{ "test di prodotto()", test_prodotto },
			CU_TEST_INFO_NULL, };

	//TEST ARRAY
	/* Test Arrays - NOTA – L’ORDINE E’ IMPORTANTE */
	CU_TestInfo test_array_signof[] = {
			{ "test di signof()", test_signof },
			CU_TEST_INFO_NULL, };

	//TEST ARRAY
	/* Test Arrays - NOTA – L’ORDINE E’ IMPORTANTE */
	CU_TestInfo test_array_max[] = {
			{ "test di massimo()", test_massimo },
			CU_TEST_INFO_NULL, };

	//TEST Minimo
	/* Test Arrays - NOTA – L’ORDINE E’ IMPORTANTE */
	CU_TestInfo test_array_minimo[] = {
			{ "test di minimo()", test_minimo },
			CU_TEST_INFO_NULL, };

	//TEST Fattoriale
	/* Test Arrays - NOTA – L’ORDINE E’ IMPORTANTE */
	CU_TestInfo test_array_fattoriale[] = {
			{ "test di fattoriale()", test_fattoriale },
			CU_TEST_INFO_NULL, };

	// crea le suite e vi aggiunge i casi di test
	CU_SuiteInfo suites[] = {
			{
					"test suite Massimo",
					suite_void_init,
					suite_void_cleanup,
					test_array_max,
			},
			{
					"test suite Minimo",
					suite_void_init,
					suite_void_cleanup,
					test_array_minimo
			},
			{
					"test suite Fattoriale",
					suite_void_init,
					suite_void_cleanup,
					test_array_fattoriale
			},
			{
					"test suite Signof",
					suite_void_init,
					suite_void_cleanup,
					test_array_signof
			},
			{
					"test suite Prodotto",
					suite_void_init,
					suite_void_cleanup,
					test_array_prodotto
			},
			{
					"test suite Somma",
					suite_void_init,
					suite_void_cleanup,
					test_array_somma
			},
			{
					"test suite Sottrazione",
					suite_void_init,
					suite_void_cleanup,
					test_array_sottrazione
			},
			CU_SUITE_INFO_NULL,
	};


	// dichiarazioni dei test array qui
	/* inizializza registro – e’ la prima istruzione */
	if (CUE_SUCCESS != CU_initialize_registry()) {
		error = CU_get_error();
		system("PAUSE");
		return -1;
	}

	// registra le suite nel registro
	error = CU_register_suites(suites);

	// verifica la presenza di errori nella registrazione
	if (CUE_SUCCESS != error) {
		CU_cleanup_registry(); // <- il registro va ripulito anche dopo errore CU_get_error(); system("PAUSE"); return -1;
	}

	/* modo “verboso” mostra a video tutte le informazioni */
	CU_basic_set_mode(CU_BRM_VERBOSE);
	CU_basic_run_tests();

	return EXIT_SUCCESS;
}

/**
 * Implementation of function to calculate Sign of integer
 * @param: int a
 * @output: -1 or 1
 */
int signof(int a){
	int sign;

	if(a<0){
		sign = -1;
	}else{
		sign = 1;
	}

	return sign;
}
int fattoriale(int input) {
	int fattoriale = input;

	if(fabs(input) == 0){
		fattoriale = 1;
	}else if(signof(input) == -1){
		fattoriale = 0;
	}else{
		int i;
		for(i=input; i != 1; i--){
			fattoriale = fattoriale * (i-1);
		}
	}
	return fattoriale;
}

int massimo(int a, int b) {

	int max = 0; //stage output variable

	//Check Max number betwen inputs
	if (a > b) {
		//assign a as max
		max = a;
	} else {
		//assign b as max
		max = b;
	}

	return max;
}

int minimo(int a, int b) {
	int min = 0;
	if (a < b) {
		min = a;
	} else {
		min = b;
	}
	return min;
}

int prodotto(int a, int b){
	int prodotto = fabs(a);

	int i;
	for(i=1;i!=fabs(b);i++){
		prodotto = prodotto + fabs(a);
	}

	int sign_a = signof(a);
	int sign_b = signof(b);
	prodotto = prodotto * (sign_a * sign_b);

	return prodotto;
}


int somma(int a, int b){
	int i;
	int somma = a;
	int sign_b = signof(b);

	for(i = fabs(b); i !=0; i--){
		if(sign_b==-1){
			somma--;
		}else{
			somma++;
		}
	}

	return somma;
}

int sottrazione(int a, int b){
	int i;
	int sottrazione = a;
	int sign_b = signof(b);

	for(i = fabs(b); i !=0; i--){
		if(sign_b==-1){
			sottrazione++;
		}else{
			sottrazione--;
		}
	}

	return sottrazione;
}


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

	CU_ASSERT_EQUAL(fattoriale(2), 2); //caso di numero intero con 2 ma nell'implementazione può essere un problema
	CU_ASSERT_EQUAL(fattoriale(3), 6); //Caso classico 13
	//Errore
	//CU_ASSERT_EQUAL(fattoriale(13), 6227020800); //caso classico con un numero grande come risultato
	//errore

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
	CU_ASSERT_EQUAL(prodotto(34,43), 1462);
	CU_ASSERT_EQUAL(prodotto(-13,22), -286);
	CU_ASSERT_EQUAL(prodotto(-12,-20), 240);

	CU_ASSERT_EQUAL(prodotto(0,0), 0);
	CU_ASSERT_EQUAL(prodotto(0,1), 0);
	CU_ASSERT_EQUAL(prodotto(0,-1), -0);
	CU_ASSERT_EQUAL(prodotto(0,22234), 0);

}


void test_somma(void) {
	CU_ASSERT_EQUAL(somma(1,1), 2); //positivo + Positivo
	CU_ASSERT_EQUAL(somma(267,324), 591); //positivo + positivo

	CU_ASSERT_EQUAL(somma(459,-47), 412); //positivo + negativo
	CU_ASSERT_EQUAL(somma(-37,224), 187); //negativo + positivo
	CU_ASSERT_EQUAL(somma(-60,-94), -154); //negativo + negativo


	CU_ASSERT_EQUAL(somma(0,-48), -48); //0 + negativo
	CU_ASSERT_EQUAL(somma(-38,0), -38); // negativo + 0

	CU_ASSERT_EQUAL(somma(0,35), 35); //0 + positivo
	CU_ASSERT_EQUAL(somma(89,0), 89); //positivo + 0

}

void test_sottrazione(void) {

	CU_ASSERT_EQUAL(sottrazione(1,1), 0); //
	CU_ASSERT_EQUAL(sottrazione(0,1), -1); //
	CU_ASSERT_EQUAL(sottrazione(1,0), 1); //
	CU_ASSERT_EQUAL(sottrazione(0,0), 0); //

	CU_ASSERT_EQUAL(sottrazione(120,243), -123); //
	CU_ASSERT_EQUAL(sottrazione(-24,123), -147); //
	CU_ASSERT_EQUAL(sottrazione(93,-32), 125); //
	CU_ASSERT_EQUAL(sottrazione(-58,-38), -20); //

	CU_ASSERT_EQUAL(sottrazione(0,22), -22); //
	CU_ASSERT_EQUAL(sottrazione(123,0), 123); //

	CU_ASSERT_EQUAL(sottrazione(0,-56), 56); //
	CU_ASSERT_EQUAL(sottrazione(-47,0), -47); //

}
