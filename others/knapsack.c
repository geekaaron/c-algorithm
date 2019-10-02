
#include <stdio.h>

#define MAXNUM 100

#define MAX(x, y) ( ((x) > (y))? (x): (y) )

int dp[MAXNUM][MAXNUM];
int weight[MAXNUM], value[MAXNUM];

void thepath(int num, int capacity)
{
	int j = capacity;

	for (int i = num; i > 1; i--)
	{
		printf("(%d, %d): %d\n", i, j, dp[i][j]);
		if (dp[i][j] != dp[i-1][j]) j -= weight[i];
	}
}

int knapsack(int num, int capacity)
{
	for (int i = 1; i <= num; i++)
	{
		for (int j = 1; j <= capacity; j++)
		{
			if (j < weight[i])
				dp[i][j] = dp[i-1][j];
			else
				dp[i][j] = MAX(dp[i-1][j], dp[i-1][j-weight[i]] + value[i]);
		}
	}

	return dp[num][capacity];
}

int main(void)
{
	int num, capacity;
	int best;

	printf("Input the number of data: ");
	scanf("%d", &num);
	printf("Input the capacity of package: ");
	scanf("%d", &capacity);
	printf("Input the %d data: eg. weight value\n", num);
	for (int i = 1; i <= num; i++)
	{
		scanf("%d%d", weight + i, value + i);
	}

	best = knapsack(num, capacity);
	printf("Best: %d\n", best);
	thepath(num, capacity);

	return 0;
}
