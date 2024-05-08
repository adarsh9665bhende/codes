#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int robber(vector<int>& nums, int n) {
        if (n > 0) {
            if (n == 1) {
                return nums[n - 1];
            }
            if (n == 2) {
                return max(nums[n - 1], nums[n - 2]);
            }
            return robber(nums, n - 2) + nums[n - 1];
        }
        return 0;
    }

    int rob(vector<int>& nums) {
        int sum = 0;
        for (int i = nums.size(); i > 0; i--) {
            sum = max(sum, robber(nums, i));
        }
        return sum;
    }
};

int main() {
    Solution solution;

    // Example usage
    vector<int> nums = {2, 1, 3,1,1,1,1,1, 10};
    int result = solution.rob(nums);

    cout << "Maximum amount that can be robbed: " << result << endl;

    return 0;
}
