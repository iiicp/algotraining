#include <iostream>
#include <vector>

using namespace std;

int removeDuplicates(vector<int> &nums){
    if (nums.size() <= 1) {
        return nums.size();
    }

    int p = 0, q = 1;

    while (q < nums.size()) {
        if (nums[p] != nums[q]) {
            nums[++p] = nums[q];
        }
        q++;
    }

    return p+1;
}

int main() {
    vector<int> nums = {1,2,3,5,5,5,6,6,7};
    int res = removeDuplicates(nums);
    for (int i = 0; i < res; ++i)
        std::cout << nums[i] << " ";
    std::cout << std::endl;
    return 0;
}
