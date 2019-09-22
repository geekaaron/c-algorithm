
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

void heapadjust(void *base, size_t n, size_t size, size_t root, \
	int (*compar)(const void *a, const void *b))
{
	for (size_t i = 2*root+1; i <= n; i = i*2+1)
	{
		if (i < n && compar(base+i*size, base+(i+1)*size) < 0) i++;
		if (compar(base+i*size, base+root*size) < 0) return;		// -->
		swap(base+root*size, base+i*size);
		root = i;
	}
}

void heapsort(void *base, size_t nmemb, size_t size, \
	int (*compar)(const void *a, const void *b))
{
	for (int i = nmemb/2-1; i >= 0; i--)
		heapadjust(base, nmemb-1, size, i, compar);

	for (int i = nmemb-1; i > 0; i--)
	{
		swap(base, base+i*size);
		heapadjust(base, i-1, size, 0, compar);
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

	heapsort(array, n, sizeof(int), compare);
	print_array(array, n);

	return 0;
}
