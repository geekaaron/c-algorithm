
#include <stdio.h>
#include <string.h>

int getnext(char *str, int next[])
{
	int i, j;

	i = -1, j = 0;
	next[0] = -1;
	while (str[j] != '\0')
	{
		if (i == -1 || str[i] == str[j])
			next[++j] = ++i;
		else
			i = next[i];
	}

	return 0;
}

int kmp(const char *str, const char *substr, int next[])
{
	int i, j, len, sublen;

	i = 0, j = 0;
	len = strlen(str);
	sublen = strlen(substr);
	while (i < len && j < sublen)
	{
		if (j == -1 || str[i] == substr[j])
			i++, j++;
		else
			j = next[j];
	}

	return substr[j] == '\0'? i - sublen: -1;
}

int main(int argc, char *argv[])
{
	int next[100];
	int index;

	getnext(argv[2], next);
	index = kmp(argv[1], argv[2], next);
	printf("Find substr %s in str %s at %d\n", argv[2], argv[1], index);

	return 0;
}
