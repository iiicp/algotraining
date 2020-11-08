#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

vector<int> twoSum(vector<int> &nums, int target)
{
    unordered_map<int, int> hashtable;

    for (int i = 0; i < nums.size(); ++i) {
        int other = target - nums[i];
        if (hashtable.count(other) == 0) {
            hashtable[nums[i]] = i;
            continue;
        }
        vector<int> res{hashtable[other], i};
        return res;
    }
    return vector<int>(2, -1);
}

int main()
{
    vector<int> nums = {3,5,1,9,13};
    vector<int> res = twoSum(nums, 14);
    std::cout << res[0] << ", " << res[1] << std::endl;

    return 0;
}
