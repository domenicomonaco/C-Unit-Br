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

/**
 * Aggiungere tutti i metodi di test per le funzioni da testare
 */
void test_xyz(void) {
	// TODO
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
	CU_TestInfo test_array_dummy[] = { { "test di xyz()", test_xyz },
			CU_TEST_INFO_NULL, };

	/**
	 * crea le suite e vi aggiunge i test array
	 * NOTA ? L?ORDINE DI INSERIMENTO E? IMPORTANTE
	 */
	CU_SuiteInfo suites[] = { { "test suite per ... ", suite_void_init,
			suite_void_cleanup, test_array_dummy },

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
	 */
	CU_cleanup_registry();
	//system("PAUSE");


	vector_init('\0');
	//vector_merge();
	//int c;
	//char* str="Dkhjh s sd";
	//c = conta_parole(str);
	//c = sizeof(*str);
	//printf("%d", c);

	int* a;
	int dim;

	printf("Che dimensione?");
	scanf("%d", &dim);

	a = (int *) calloc(dim, sizeof(int));

	inputarray(a, dim);

	output(a, dim);

	//	int i;
	//	for (i = 0; i < dim; i++) {
	//		printf("a[%d]=", i);
	//		scanf("%d", (a + i));
	//	}

	//	printf("i valori sono \n");
	//	for (i = 0; i < dim; i++) {
	//		printf("a[%d]=%d \n", i, *(a + i));
	//	}

	return error;
}

void inputarray(int* a, const int dim) {

	int i;
	for (i = 0; i < dim; i++) {
		printf("a[%d]=", i);
		scanf("%d", (a + i));

	}
}

void output(const int* a, const int dim) {
	int i;
	printf("i valori sono \n");
	for (i = 0; i < dim; i++) {
		printf("a[%d]=%d \n", i, *(a + i));
	}
}
