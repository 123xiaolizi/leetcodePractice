class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int target = 0;
        for(int it : nums)
        {
            target += it;
        }
        if (target % 2 != 0) return false; 
        target = target / 2;
        int* dp = new int[target + 1]();//() 确保初始化为 0
        for(int i = 0; i < nums.size(); ++i)
        {
            for(int j = target; j >= nums[i]; --j)
            {
                dp[j] = max(dp[j], dp[j - nums[i]] + nums[i]);
                if(dp[j] == target)
                {
                    delete[] dp;
                    return true;
                }
            }
        }
        delete[] dp;
        return false;

    }
};