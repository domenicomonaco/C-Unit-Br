/*
 ============================================================================
 Name        : massimo.c
 Author      : Domenico Monaco & Michele Chiarello
 Version     :
 Copyright   : Copyright Domenico Monaco and Michele Chiarello 2011
 License     : GPLv2

 Description :

 Feature:

 MASSIMO 			OK
 MINIMO 			OK

 SOMMA				OK
 SOTRAZIONE			OK

 PRODOTTO 			OK
 DIVISIONE			DA TESTARE

 SIGN 				OK

 FATTORIZAZIONE 	OK

 //
 DIVISORI di N
 FATTORI PRIMI di N

 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

#include <string.h>
#include "CUnit/basic.h"

#include "matematica_function.h"
#include "test_matematica_function.h"

#include "matematica_proc_point.h"
#include "test_matematica_proc_point.h"

#define MAXARRAY 10

/**
 *
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


	//matematica_proc_point
	CU_TestInfo test_array_summ_p[] =
		{
			{ "test di summ_p()", test_summ_p }, CU_TEST_INFO_NULL, };

	CU_TestInfo test_array_inverti[] =
		{
			{ "test di inverti()", test_inverti }, CU_TEST_INFO_NULL, };


	//matematica_function
	/*
	 CU_TestInfo test_array_somma[] =
	 {
	 { "test di somma()", test_somma }, CU_TEST_INFO_NULL, };

	 CU_TestInfo test_array_divisione[] =
	 {
	 { "test di divisione()", test_divisione }, CU_TEST_INFO_NULL, };

	 CU_TestInfo test_array_sottrazione[] =
	 {
	 { "test di sottrazione()", test_sottrazione }, CU_TEST_INFO_NULL, };

	 CU_TestInfo test_array_prodotto[] =
	 {
	 { "test di prodotto()", test_prodotto }, CU_TEST_INFO_NULL, };

	 CU_TestInfo test_array_signof[] =
	 {
	 { "test di signof()", test_signof }, CU_TEST_INFO_NULL, };

	 CU_TestInfo test_array_max[] =
	 {
	 { "test di massimo()", test_massimo }, CU_TEST_INFO_NULL, };

	 CU_TestInfo test_array_minimo[] =
	 {
	 { "test di minimo()", test_minimo }, CU_TEST_INFO_NULL, };

	 CU_TestInfo test_array_fattoriale[] =
	 {
	 { "test di fattoriale()", test_fattoriale }, CU_TEST_INFO_NULL, };
	 */

	// crea le suite e vi aggiunge i casi di test
	CU_SuiteInfo suites[] =
		{
		/*{
		 "test suite Massimo",
		 suite_void_init,
		 suite_void_cleanup,
		 test_array_max, },
		 {
		 "test suite Minimo",
		 suite_void_init,
		 suite_void_cleanup,
		 test_array_minimo },
		 {
		 "test suite Fattoriale",
		 suite_void_init,
		 suite_void_cleanup,
		 test_array_fattoriale },
		 {
		 "test suite Signof",
		 suite_void_init,
		 suite_void_cleanup,
		 test_array_signof },
		 {
		 "test suite Prodotto",
		 suite_void_init,
		 suite_void_cleanup,
		 test_array_prodotto },
		 {
		 "test suite Divisione",
		 suite_void_init,
		 suite_void_cleanup,
		 test_array_divisione },
		 {
		 "test suite Somma",
		 suite_void_init,
		 suite_void_cleanup,
		 test_array_somma },
		 {
		 "test suite Sottrazione",
		 suite_void_init,
		 suite_void_cleanup,
		 test_array_sottrazione },
		 */
			{
					"test suite Summ_P",
					suite_void_init,
					suite_void_cleanup,
					test_array_summ_p },
			{
					"test suite Inverti",
					suite_void_init,
					suite_void_cleanup,
					test_array_inverti },

		CU_SUITE_INFO_NULL, };


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

	typedef vettore[MAXARRAY];

	vettore A, B, C;
	/*
	 int i;
	 for (i = 0; i < MAXARRAY; i++) {
	 printf("Vettore A: Inserire %d-esimo numero = ", i);
	 scanf("%d", &A[i]);

	 printf("Vettore B: Inserire %d-esimo numero = ", i);
	 scanf("%d", &B[i]);
	 }

	 for(i=0;i<MAXARRAY;i++){
	 C[i] = A[i] + B[i];
	 printf("Risultato %i-esimo di %d + %d = %d \n", i, A[i], B[i], C[i]);
	 }
	 */
	int i;
	/*char nome[20] = "domenico monaco";

	 for (i = 0; i <= strlen(nome); i++) {
	 printf("%c di %d \n", nome[i], i);
	 }*/

	char testo[MAXARRAY];
	memset(testo, '\0', MAXARRAY);

	scanf("%s", testo);

	for (i = 0; i < MAXARRAY; i++) {
		if ((testo[i] == '\0')) {
			i=MAXARRAY;
		} else {
			printf("%c%c", testo[i], testo[i]);
		}
	}

	return EXIT_SUCCESS;
}

char* crea_stringa(char a, char b, char c){
	char* s = (char*) calloc(4, sizeof(char));

	*s = a;
	*(s+1) = b;
	*(s+2) = c;
	*(s+3) = '\0';

	return s;
}
