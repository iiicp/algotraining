#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void calc_next(char pattern[], int next[], int n)
{
	int i = 1;
	int curnval = 0;
	next[0] = 0;

	while (i < n) {
		if (pattern[i] == pattern[curnval]) {
			curnval++;
			next[i] = curnval;
			i++;
		}else {
			if (curnval > 0) {
				curnval = next[curnval - 1];
			}else {
				next[i] = curnval;
				i++;
			}
		}
	}
}

void move_next(int next[], int n)
{
	for (int i = n - 1; i > 0; --i)
		next[i] = next[i-1];
	next[0] = -1;
}

int kmp_search(char text[], char pattern[])
{
	int n = strlen(text);
	int m = strlen(pattern);
	
	int *next = (int *)malloc(sizeof(int) * m);

	calc_next(pattern, next, m);
	move_next(next, m);

	int i = 0, j = 0;

	while (i < n) {
		if (text[i] == pattern[j]) {
			i++;
			j++;
			if (j == m) {
				free(next);
				return i - j;
			}
		}else {
			j = next[j];
			if (j == -1)
			{
				i++;
				j++;
			}
		}
	}
	free(next);
	return -1;
}

char* mystrstr(const char *s1, const char *s2) {

	int len = strlen(s2);

	while (*s1) {
		char *p = (char *)s1;
		char *q = (char *)s2;
		int tlen = len;
		while (tlen >0 && *p == *q) {
			p++;
			q++;
			tlen--;
		}
		
		if (tlen == 0)
			return (char *)s1;
		s1++;
	}
	return NULL;
}

int main() {

	char *s = mystrstr("hello, world, caipeng", "peng");
	if (s) {
		printf("%s\n", s);
	}else {
		printf("not found");
	}
	char text[] = "hello, world, caipeng";
	char pattern[] = "peng";
	int index = kmp_search(text, pattern);
	printf("index = %d\n", index);
#if 0	
	calc_next(pattern, next, n);
	move_next(next, n);
	for (int i = 0; i < n; ++i)
		printf("%d ", next[i]);

	printf("\n");
#endif
	return 0;
}
