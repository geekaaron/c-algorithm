
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

void quick_sort(void *base, int left, int right, size_t size, \
	int (*compar)(const void *a, const void *b))
{
	if (left >= right) return;		// -->

	int i = left, j = right;

	while (j > i)
	{
		while (j > i && compar(base+left*size, base+j*size) <= 0) j--;
		while (j > i && compar(base+left*size, base+i*size) >= 0) i++;
		if (j > i) swap(base+i*size, base+j*size);
	}

	swap(base+left*size, base+i*size);
	quick_sort(base, left, i-1, size, compar);
	quick_sort(base, i+1, right, size, compar);
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

	quick_sort(array, 0, n-1, sizeof(int), compare);
	print_array(array, n);

	return 0;
}
