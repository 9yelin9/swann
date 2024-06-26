#define N 3

#include "swann.h"

int main() {
	int i, j;
	lapack_int n=N;
	double ev[N];
	lapack_complex_double es[N*N]={
		1 + 0*I, 0 + 1*I, 0 + 2*I,
		0 - 1*I, 2 + 0*I, 0 + 0*I,
		0 - 2*I, 0 + 0*I, 3 + 0*I
	};

	printf("LAPACK_zheev() eigensolver test\n\n");
	printf("Target mat (complex):\n");
	for(i=0; i<N; i++) {
		for(j=0; j<N; j++) {
			printf("%6.2f%6.2f\t", creal(es[N*i + j]), cimag(es[N*i + j]));
		}
		printf("\n");
	}
	printf("\n");

	CalcEigen(n, es, ev);

	printf("Eigenvals:\n");
	for(i=0; i<N; i++) printf("%f\t", ev[i]);
	printf("\n");

	return 0;
}
