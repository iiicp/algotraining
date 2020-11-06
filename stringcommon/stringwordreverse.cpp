#include <string>
#include <cstring>
#include <cctype>
#include <iostream>

using namespace std;

void reverse(std::string &reverse) {
	int i = 0, j = (int)reverse.size() - 1;

	while (i < j) {
		char t = reverse[i];
		reverse[i] = reverse[j];
		reverse[j] = t;
		i++;
		j--;
	}
}

void stringwordreverse(std::string &str){
	char *pbegin = (char *)str.c_str();
	char *p = pbegin;
	while (*p) {
		while (isspace(*p) || isdigit(*p)) {
			p++;
			continue;
		}

		char *tmp = p;
		while (isalpha(*tmp)){
			tmp++;
		}

		if (tmp > p) {
			int start = p - pbegin;
			int len = tmp - p;
			std::string subs = str.substr(start, len);
			reverse(subs);
			for (int i = 0; i < len; ++i)
				str[start + i] = subs[i];
			p = tmp;
		}
	}
}

int main() {

	std::string test(" I have a 99 dream ddsa ec ab");
	stringwordreverse(test);
	std::cout << test << std::endl;

	return 0;
}