#include <string>
#include <unordered_map>
#include <iostream>

using namespace std;

bool canCompose(string newspaper, string message)
{
	if (newspaper.size() < message.size())
		return false;

	unordered_map<char, int> hashtable;
	
	for (int i = 0; i < newspaper.size(); ++i)
		hashtable[newspaper[i]]++;
	
	for (int i = 0; i < message.size(); ++i) {
		if (hashtable.count(message[i]) == 0)
			return false;
		if (--hashtable[message[i]] < 0) 
			return false;
	}
	return true;
}

int main() {
	std::cout << canCompose("abcedfe", "cfe") << std::endl;
	std::cout << canCompose("abcedfe", "cfeee") << std::endl;
	return 0;
}
