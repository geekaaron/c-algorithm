
#include <stdio.h>
#include "headers.h"

#define LENGTH 100

void print_array(int array[], int n)
{
	for (int i = 0; i < n; i++)
		printf("%d ", array[i]);
	printf("\n");
}

void swap(void *a, void *b)
{
	int t;

	t = *(int *)a;
	*(int *)a = *(int *)b;
	*(int *)b = t;
}

int compare(const void *a, const void *b)
{
	return *(int *)b - *(int *)a;
}

void shell_sort(void *base, size_t nmemb, size_t size, \
	int (*compar)(const void *a, const void *b))
{
	for (size_t gap = nmemb/2; gap > 0; gap /= 2)
		for (size_t i = gap; i < nmemb; i++)
			for (size_t j = i; j >= gap; j -= gap)
				if (compar(base+(j-gap)*size, base+j*size) > 0)
					swap(base+j*size, base+(j-gap)*size);
}

int main(void)
{
	int array[LENGTH];
	int n;

	printf("Please input the number of datas: ");
	scanf("%d", &n);
	printf("Please input %d datas...\n", n);
	for (int i = 0; i < n; i++)
		scanf("%d", array + i);

	shell_sort(array, n, sizeof(int), compare);
	print_array(array, n);

	return 0;
}
