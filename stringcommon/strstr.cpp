#include <string>
#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    int strStr(string haystack, string needle) {
    	int textlen = haystack.length(), patternlen = needle.length();

    	if (textlen < patternlen) {
    		return -1;
    	}

    	if (patternlen == 0) {
    		return 0;
    	}

    	vector<int> next(patternlen, 0);
    	getnext(needle, next);
    	movenext(next);

    	int i = 0, j = 0;
    	while (i < textlen) {
    		if (haystack[i] == needle[j]) {
    			i++;
    			j++;
    			if (j == patternlen) {
    				return i - j;
    			}
    		}else {
    			j = next[j];
    			if (j == -1) {
    				j++;
    				i++;
    			}
    		}
    	}
    	return -1;
    }
public:
	void getnext(string &pattern, vector<int> &next)
	{
		next[0] = 0;
		int cur_next_val = 0;
		int i = 1;
		int len = pattern.length();

		while (i < len) {
			if (pattern[i] == pattern[cur_next_val]) {
				cur_next_val++;
				next[i] = cur_next_val;
				i++;
			}else {
				if (cur_next_val > 0) {
					cur_next_val = next[cur_next_val - 1];
				}
				else {
					next[i] = cur_next_val;
					i++;
				}
			}
		}
	}

	void movenext(vector<int> &next) {
		int len = next.size();
		for (int i = len - 1; i > 0; --i)
			next[i] = next[i-1];
		next[0] = -1;
	}
};

int main()
{
	string haystack = "i love c++ program";
	string need = "++";

	int res = Solution().strStr(haystack, need);
	std::cout << res << std::endl;
	return 0;
}