/*
 * @filename: vector_list.c
 * @author: macbook
 * @rev: 0.1
 * @license: GPLV2
 * @date: 09/apr/2011
 * @desc: 
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "CUnit/Basic.h"

#include "vettori.h"

#define MAX 5

/**
 * Aggiungere tutti i metodi di test per le funzioni da testare
 */

/*
 * @desc: Test per "conta_parole_bis" che fa uso della funzione di splitting
 */
void test_conta_parole_bis(void) {
	char a[] = "Ciao";
	int b = conta_parole_bis(a);
	CU_ASSERT(b==1);

	char c[] = "ciao come va";
	b = conta_parole_bis(c);
	CU_ASSERT(b==3);

	char d[] = "ciao come va , # - * + @ ! £ $ % & / ( ) = ? ' ";
	b = conta_parole_bis(d);
	CU_ASSERT(b==3);

	char e[] = "ciao come va , # - * + @ ! £ $ %Domenico & / ( ) = ? ' ";
	b = conta_parole_bis(e);
	CU_ASSERT(b==4);

}

void test_array_max(void) {

}

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

int main(int argc, char *argv[]) {
	CU_ErrorCode error;

	/**
	 * Definizione dei test array
	 * NOTA ? L?ORDINE DI INSERIMENTO E? IMPORTANTE
	 */
	CU_TestInfo test_array_conta_parole_bis[] = { {
			"test di conta_parole_bis()", test_conta_parole_bis },
			CU_TEST_INFO_NULL, };

	/**
	 * crea le suite e vi aggiunge i test array
	 * NOTA ? L?ORDINE DI INSERIMENTO E? IMPORTANTE
	 */
	CU_SuiteInfo suites[] = { { "test suite per conta_parole_bis ",
			suite_void_init, suite_void_cleanup, test_array_conta_parole_bis },

	CU_SUITE_INFO_NULL, };

	/* inizializza registro ? e? la prima istruzione */
	if (CUE_SUCCESS != CU_initialize_registry()) {
		error = CU_get_error();
		system("PAUSE");
		return -1;
	}

	// add the suites to the registry
	error = CU_register_suites(suites);

	if (CUE_SUCCESS != error) {
		CU_cleanup_registry();
		error = CU_get_error();
		system("PAUSE");
		return -1;
	}

	/**
	 * Esegue tutti i casi di test con output sulla console
	 */
	CU_basic_set_mode(CU_BRM_VERBOSE);
	CU_basic_run_tests();

	/**
	 * Pulisce il registro e termina lo unit test
	 **/

	CU_cleanup_registry();

	//system("PAUSE");

	return error;
}
