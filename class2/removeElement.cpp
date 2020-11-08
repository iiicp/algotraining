#include <iostream>
#include <vector>

using namespace std;

int removeElement(vector<int> &nums, int value) {
    int len = nums.size();
    for (int i = 0; i < len; ++i) {
        if (nums[i] == value) {
            nums[i] = nums[--len];
            i--;
        }
    }
    return len;
}

int main() {
    
    vector<int> nums{0,0,4,0,4,2,0};

    int res = removeElement(nums, 0);
    std::cout << res << std::endl;

    for (int i = 0; i < res; ++i)
        std::cout << nums[i] << " ";
    std::cout << std::endl;
    return 0;
}
