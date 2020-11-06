#include <stdlib.h>
#include <string.h>
#include <stdio.h>

int mymemcmp(const void *s1, const void *s2, size_t n) {
	char *ps1 = (char *)s1;
	char *ps2 = (char *)s2;

	while (n > 0 && *ps1 == *ps2) {
		n--;
		ps1++;
		ps2++;
	}
	return n == 0 ? 0 : *ps1 - *ps2;
}

void *mymemset(void *src, int val, size_t n) {
	char *s = (char *)src;
	while (n-- > 0) {
		printf("%d ", n);
		*s++ = val;
	}
	return src;
}

void *mymemcpy(void *dest, const void *src, size_t n) {
	char *d = (char *)dest;
	const char *s = (const char *)src;

	while (n-- > 0) {
		*d++ = *s++;
	}
	return dest;
}

void *mymemmove(void *dest, const void *src, size_t n) {
	char *d = (char *)dest;
	char *s = (char *)src;

	if (d < s) {
		while (n-- > 0) {
			*d++ = *s++;
		}
	}else {
		d += n-1; 
		s += n-1; 

		while (n-- > 0) {
			*d-- = *s--;
		}
	}

	return dest;
}

int main() {
	char dest[30] = {0};
	char dest_my[30] = {0};
	char src[] = "i love c program code";
	// memmove(dest, src, sizeof(src));
	mymemcpy(dest, src, sizeof(src));
	printf("%s\n", dest);

	char src2[] = "i love c program code1";
	mymemmove(dest_my, src2, sizeof(src2));
	printf("%s\n", dest_my);

	int res = mymemcmp(dest_my, dest, sizeof(dest));
	int res2 = memcmp(dest_my, dest, sizeof(dest));
	printf("res: %d, res2: %d\n", res, res2);

	#if 0
	mymemset(dest, 128, sizeof(dest));
	memset(dest_my, 128, sizeof(dest_my));

	for (int i = 0; i < 30; ++i)
		printf("%d ", dest[i]);
	printf("\n");
	for (int i = 0; i < 30; ++i)
		printf("%d ", dest_my[i]);
	printf("\n");
	#endif
	return 0;
}