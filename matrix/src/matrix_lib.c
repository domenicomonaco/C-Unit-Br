/*
 * @filename: matrix_lib.c
 * @author: macbook
 * @rev: 0.1
 * @license: GPLV2
 * @date: 02/mag/2011
 * @desc: 
 */

void matrix_print_float(int const m, int const n, float const matrix) {
	//mXn
	int m = 3;
	int n = 4;
	i = 0;
	int j = 0;
	for (i = 0; i <= m; i++) {
		printf("[ ");
		for (j = 0; j <= n; j++) {
			printf("%f", mat[i][j]);
			if (j != n) {
				printf(", ");
			} else {
				printf(" ");
			}
		}
		printf(" ]\n");
	}
}
