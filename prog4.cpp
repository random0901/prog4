#include<stdio.h>
#include<omp.h>
int fib(int n)
{
	if (n < 2) return n;
	else return fib(n - 1) + fib(n - 2);
}
int main()
{
	int fibnumber[100], i, j, n;
	printf("please enter the series limit\n");
	scanf_s("%d", &n);
#pragma omp parallel num_threads(2)
	{
		if (omp_get_thread_num() == 0)
		{
			printf("there are %d threads\n", omp_get_num_threads());
			printf("Threads %d generating numbers..\n", omp_get_thread_num());
			for (i = 0; i < n; i++)
				fibnumber[i] = fib(i);
		}
		if (omp_get_thread_num() == 1) {
			printf("Threads %d Printing numbers..\n", omp_get_thread_num());

			for (j = 0; j < n; j++)
				printf("%d\t", fibnumber[j]);
		}
	}
}