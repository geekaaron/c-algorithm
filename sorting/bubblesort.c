
#include <stdio.h>

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

void bubble_sort(void *base, size_t nmemb, size_t size, \
	int (*compar)(const void *a, const void *b))
{
	int done = 0;

	for (size_t i = 0; i < nmemb & !done; i++)
	{
		done = 1;
		for (size_t j = 0; j < nmemb-i-1; j++)
			if (compar(base+j*size, base+(j+1)*size) > 0)
			{
				swap(base+j*size, base+(j+1)*size);
				done = 0;
			}
	}
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

	bubble_sort(array, n, sizeof(int), compare);
	print_array(array, n);

    return 0;
}
