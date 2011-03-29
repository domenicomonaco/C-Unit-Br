/*
 * matematica.c
 *
 *  Created on: 24/mar/2011
 *      Author: Domenico Monaco
 *
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#include <math.h>

#define DECIMALEDIVISIONE 7

/**
 * Implementation of function to calculate Sign of integer
 * @param: int a
 * @output: -1 or 1
 */
int signof(int a) {
	int sign;

	if (a < 0) {
		sign = -1;
	} else {
		sign = 1;
	}

	return sign;
}

int fattoriale(int input) {
	int fattoriale = input;

	if (fabs(input) == 0) {
		fattoriale = 1;
	} else if (signof(input) == -1) {
		fattoriale = 0;
	} else {
		int i;
		for (i = input; i != 1; i--) {
			fattoriale = fattoriale * (i - 1);
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

int isinteger(float input) {
	int output;

	return output;
}

/**
 * if A is mul of B
 *
 */
int ismul(int a, int b) {
	float result;

	result = a / b;

	char str[] = "1033.4";

	int digit = isdigit(str[0]);

	return digit;

	//	return result;
}

float divisione(int dividendo, int divisore) {
	float quoziente = 0;
	int rest = 0;

	float decimale = 1;

	int i = 1;
	while (i >= 1) {

		if (divisore == dividendo) {
			//Caso divdendo/divisore = 1, con resto=0;
			//printf("Divis = divid");
			return quoziente = 1;

		} else if (divisore != dividendo) {

			//caso in cui b<a, b  contenuto almeno 1 volta in a
			//quoziente  > 1
			//r >= 0;

			int s = 1;
			while (s != 0) {

				if ((divisore * s) < dividendo) {
					s++;
				} else if (divisore * s == dividendo) {
					rest = 0;
					quoziente = quoziente + ((s) * decimale);

					s = 0;
				} else if ((divisore * s) > dividendo) {
					quoziente = quoziente + ((s - 1) * decimale);
					rest = dividendo - (divisore * (s - 1));

					s = 0;
				}
			}
		}

		if (rest == 0 || i >= DECIMALEDIVISIONE) {
			i = 0;
		} else {
			decimale = decimale * 0.1;
			dividendo = rest * 10;

			i++;
		}
	}

	return quoziente;
}

float primalita(int input) {
	//TODO
	// Non completa

	float isprim;

	// Il pi piccolo numero primo  2;
	// tutti gli altri sono dispari,
	// in quanto ogni numero pari  divisibile per 2

	// Un numero  primo se non  divisibile
	// Per nessun numero primo minore di se stesso

	// Analogamente, se si utilizza il metodo delle divisioni per dimostrare la primalitˆ di un numero X
	// si pu˜ evitare di controllare la divisibilitˆ di X per numeri maggiori della radice quadrata di X.

	float i = 2;
	float c;

	while (i != 0 && i > sqrt(input)) {

		c = input / i;

	}

	return isprim;
}

int prodotto(int a, int b) {
	int prodotto = fabs(a);

	int i;
	for (i = 1; i != fabs(b); i++) {
		prodotto = prodotto + fabs(a);
	}

	int sign_a = signof(a);
	int sign_b = signof(b);
	prodotto = prodotto * (sign_a * sign_b);

	return prodotto;
}

int somma(int a, int b) {
	int i;
	int somma = a;
	int sign_b = signof(b);

	for (i = fabs(b); i != 0; i--) {
		if (sign_b == -1) {
			somma--;
		} else {
			somma++;
		}
	}

	return somma;
}

int sottrazione(int a, int b) {
	int i;
	int sottrazione = a;
	int sign_b = signof(b);

	for (i = fabs(b); i != 0; i--) {
		if (sign_b == -1) {
			sottrazione++;
		} else {
			sottrazione--;
		}
	}

	return sottrazione;
}

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
