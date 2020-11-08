#include <ctype.h>
#include <limits.h>
#include <stdlib.h>
#include <stdio.h>

long long myatoll(const char *str) {
	long long n = 0, sign = 1;

	while (isspace(*str))
		str++;

	switch (*str) {
		case '-':
			sign = -1;
		case '+':
			str++;
	}

	for (n = 0; isdigit(*str); str++)
		n = n * 10 + *str - '0';

	return n * sign;
}

long myatol(const char *str) {
	long n = 0, sign = 1;
	
	while (isspace(*str))
		str++;

	switch (*str) {
		case '-':
			sign = -1;
		case '+':
			str++;
	}

	for (n = 0; isdigit(*str); str++)
		n = n * 10 + *str - '0';

	return n * sign;
}

int myatoi(const char *str) {
	int n = 0, sign = 1;

	while (isspace(*str))
		str++;

	switch (*str) {
		case '-':
			sign = -1;
		case '+':
			str++;
	}

	for (n = 0; isdigit(*str); str++)
		n = n * 10 + *str - '0';

	return n * sign;
}


int main() {
	printf("%d, %d\n", INT_MIN, INT_MAX);
	printf("%ld, %ld\n", LONG_MIN, LONG_MAX);
	printf("%lld, %lld\n", LLONG_MIN, LLONG_MAX);

	const char *str = "21474836460";
	int res1 = myatoi(str);
	int res2 = atoi(str);
	printf("res1 : %d, res2 : %d\n", res1, res2);

	long res3 = myatol(str);
	long res4 = atol(str);
	printf("res3 : %ld, res4 : %ld\n", res3, res4);

	long long res5 = myatoll(str);
	long long res6 = atoll(str);
	printf("res5 : %lld, res6 : %lld\n", res5, res6);


	return 0;
}
