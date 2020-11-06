#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* mystrstr(const char *s1, const char *s2) {
	char c;
	c = *s2++;
	if (c == '\0')
		return (char *)s1;

	while (*s1) {
		if (*s1 != c) {
			s1++;
		}
	}
}

int main() {

	char *s = mystrstr("hello, world, caipeng", "xpeng");
	printf("%s\n", s);

	return 0;
}