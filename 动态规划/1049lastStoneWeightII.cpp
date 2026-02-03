class Solution {
public:
    int lastStoneWeightII(vector<int>& stones) {
        int target = 0;
        int sum = 0;
        for(int it : stones)
        {
            sum += it;
        }
        target = sum / 2;
        int* dp = new int[target + 1]();//() 确保初始化为 0
        for(int i = 0; i < stones.size(); ++i)
        {
            for(int j = target; j >= stones[i]; --j)
            {
                dp[j] = max(dp[j], dp[j - stones[i]] + stones[i]); 
            }
        }
        int result = sum - (dp[target] * 2);
        delete[] dp;
        return result;
    }
};