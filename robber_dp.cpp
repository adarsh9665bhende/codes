#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int robber(vector<int>& nums,vector<int>&dp, int n) {
        if(dp[n]!=-1){return dp[n];}
        if (n >= 0) {
            if (n == 0) {
                return dp[n]=nums[n];
            }
            if (n == 1) {
                return dp[n]=max(nums[n - 1], nums[n]);
            }
            return dp[n]=robber(nums,dp, n - 2) + nums[n];
        }
        return 0;
    }

    int rob(vector<int>& nums) {
        vector<int>dp = vector<int>(nums.size(),-1);
        int sum = 0;
        for (int i = nums.size()-1; i > 0; i--) {
            sum = max(sum, robber(nums,dp, i));
        }
        return sum;
    }
};

int main() {
    Solution solution;

    // Example usage
    vector<int> nums = {2, 1, 3,1,1,1,1,1,10};
    int result = solution.rob(nums);

    cout << "Maximum amount that can be robbed: " << result << endl;

    return 0;
}
