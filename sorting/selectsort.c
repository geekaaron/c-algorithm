
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

void select_sort(void *base, size_t nmemb, size_t size, \
	int (*compar)(const void *a, const void *b))
{
	void *select;
	size_t index;

	for (size_t i = 0; i < nmemb; i++)
	{
		index = i;
		select = base + i*size;
		for (size_t j = i+1; j < nmemb; j++)
			if (compar(select, base+j*size) > 0)
			{
				select = base + j*size;
				index = j;
			}
		swap(base+i*size, base+index*size);
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

	select_sort(array, n, sizeof(int), compare);
	print_array(array, n);

	return 0;
}
