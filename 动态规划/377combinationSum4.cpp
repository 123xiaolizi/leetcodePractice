class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        //排列问题 ，先遍历背包，再遍历物品
        vector<uint64_t>dp(target+1,0);
        dp[0] = 1;
        for(int i = 0; i <= target; ++i)
        {
            for(int j = 0; j < nums.size(); ++j)
            {
                if(nums[j] <= i)
                {
                    dp[i] += dp[i-nums[j]];
                }
            }
        }
        return dp[target];
    }
};