#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

struct Range{
    int l;
    int h;

    Range(int low=0, int high=0) {
        l = low;
        h = high;
    }
};

int longestConsecutive(vector<int> &nums)
{
    if (nums.size() == 0)
        return 0;

    int maxlen = 0;
    unordered_map<int, Range> hashtable;

    for (int i = 0; i < nums.size(); ++i) {
        int cur = nums[i];
        
        if (hashtable.count(cur)) 
            continue;
       
        int low = cur, high = cur;

        if (hashtable.count(cur-1))
            low = hashtable[cur-1].l;
        if (hashtable.count(cur+1))
            high = hashtable[cur+1].h;

        hashtable[high].l = hashtable[cur].l = low;
        hashtable[low].h = hashtable[cur].h = high;
        maxlen = high - low + 1 > maxlen ? high - low + 1 : maxlen;
    }

    return maxlen;
}

int main(){
    
    vector<int> nums{31,6,32,1,3,2};
    int r = longestConsecutive(nums);
    std::cout << r << std::endl;
    return 0;
}
