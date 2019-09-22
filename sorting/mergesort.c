
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

void merge(void *base, int left, int mid, int right, size_t size, \
	int (*compar)(const void *a, const void *b))
{
	void *tmp;

	if (!(tmp = (void *)malloc(sizeof(base))))
	{
		perror("malloc");
		exit(-1);
	}

	int i, j, k;

	i = k = left, j = mid + 1;
	while (i <= mid && j <= right)
	{
		if (compar(base+i*size, base+j*size) > 0)
			memcpy(tmp+k*size, base+(j++)*size, size);
		else
			memcpy(tmp+k*size, base+(i++)*size, size);
		k++;
	}

	while (i <= mid) memcpy(tmp+(k++)*size, base+(i++)*size, size);
	while (j <= right) memcpy(tmp+(k++)*size, base+(j++)*size, size);

	for (i = left; i <= right; i++)
		memcpy(base+i*size, tmp+i*size, size);
}

void merge_sort(void *base, int left, int right, size_t size, \
	int (*compar)(const void *a, const void *b))
{
	if (left >= right) return;			// -->

	int mid = (left + right) / 2;

	merge_sort(base, left, mid, size, compar);
	merge_sort(base, mid+1, right, size, compar);
	merge(base, left, mid, right, size, compar);
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

	merge_sort(array, 0, n-1, sizeof(int), compare);
	print_array(array, n);

	return 0;
}
