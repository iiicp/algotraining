#include <string>
#include <unordered_map>
#include <iostream>

using namespace std;

bool isPermutionstr(string stringA, string stringB)
{
	int lenA = stringA.size(), lenB = stringB.size();
	if (lenA != lenB)
		return false;

	unordered_map<char, int> hashstrA, hashstrB;

	for (int i = 0; i < lenA; ++i) {
		hashstrA[stringA[i]]++;
		hashstrB[stringB[i]]++;
	}

	if (hashstrA.size() != hashstrB.size())
		return false;

	for (unordered_map<char, int>::iterator it = hashstrA.begin(); it != hashstrA.end(); it++) {
		if (it->second != hashstrB[it->first]) 
			return false;
	}
	return true;
}

int main() {
	
	std::cout << isPermutionstr("caipeng", "cpengia") << std::endl;
	std::cout << isPermutionstr("cpenai", "apenip") << std::endl;

	return 0;
}
