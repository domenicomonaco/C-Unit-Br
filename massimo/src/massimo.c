/*
 ============================================================================
 Name        : massimo.c
 Author      : Domenico Monaco & Michele Chiarello
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style

 Feature:
  MASSIMO
  MINIMO
  SOMMA
  SOTRAZIONE
  FATTORIZAZIONE

 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "CUnit/basic.h"

int massimo(int a, int b);
int minimo(int a, int b);
int fattoriale(int a);

void test_massimo();
void test_minimo();
void test_fattoriale();

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
			{"test suite per le funzioni matematiche di base", suite_void_init, suite_void_cleanup, test_array_max, test_array_minimo, test_array_fattoriale },
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

int fattoriale(int input) {
	int fattoriale;

	if(input == 0){
		fattoriale = input;
	}else if(input < 0){
		fattoriale = 0;
	}else{
		int i;
		for(i=input; i > 2; i--){
			fattoriale = input * (i-1);
		}
	}
	return fattoriale;
}

int massimo(int a, int b) {
	int max = 0;
	if (a > b) {
		max = a;
	} else {
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
	int prodotto=0;
	//TODO
	return prodotto;
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
	CU_ASSERT_EQUAL(fattoriale(13), 6227020800); //caso classico con un numero grande come risultato

	CU_ASSERT_EQUAL(fattoriale(-0), 0); //caso strano con -0 zero
	CU_ASSERT_EQUAL(fattoriale(-132), 0); //caso con numero negativo
}
