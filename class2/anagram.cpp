#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;
bool isAnagram(string s1, string s2)
{
    if (s1.size() != s2.size())
        return false;

    unordered_map<char, int> hts1, hts2;
    for (int i = 0; i < s1.size(); ++i) {
        hts1[s1[i]]++;
        hts2[s2[i]]++;
    }

    for (unordered_map<char, int>::iterator it = hts1.begin(); it != hts1.end(); it++){
        if (it->second != hts2[it->first])
            return false;
    }
    return true;
}

int main() {
    
    std::cout << isAnagram("abcd", "adbc") << std::endl;
    std::cout << isAnagram("abcd", "abbc") << std::endl;
    return 0;
}
