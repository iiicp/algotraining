#include <string>
#include <unordered_map>
#include <iostream>
#include <bitset>
using namespace std;

bool isUnique(string input) {
	bitset<256> hashtable;
	for (int i = 0; i < input.size(); ++i)
		if (hashtable[(int)input[i]]) {
			return false;
		}else {
			hashtable[(int)input[i]] = 1;
		}
	return true;
}

int main() {
	std::cout <<"abceda: " << isUnique("abceda") << std::endl;
	std::cout <<"abced:  " << isUnique("abced") << std::endl;
	return 0;
}
