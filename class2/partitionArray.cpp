#include <iostream>
#include <vector>

using namespace std;

void partitionArray(vector<int> &nums, int k) {
    int i = 0, j = nums.size() - 1;

    while (i < j) {
        while (i < j && nums[i] < k)
            i++;
        while (i < j && nums[j] > k)
            j--;

        int temp = nums[i];
        nums[i] = nums[j];
        nums[j] = temp;
    }
}

int main() {
    vector<int> num{1,4,2,9,5,7};
    partitionArray(num, 5);

    for (auto &val : num)
        std::cout << val << " ";
    std::cout << std::endl;

    return 0;
}
