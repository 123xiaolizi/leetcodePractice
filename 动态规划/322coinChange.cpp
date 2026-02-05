class Solution {
public:
    /*
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount+1,INT_MAX);
        dp[0] = 0;
        for(int i = 0; i < coins.size(); ++i)
        {
            for(int j = coins[i]; j <= amount; ++j)
            {
                if(dp[j - coins[i]] != INT_MAX)
                {
                    dp[j] = min(dp[j], dp[j - coins[i]]+ 1);
                }
            }
        }
        if (dp[amount] == INT_MAX) return -1;
        return dp[amount];
    }
    */
    int coinChange(vector<int>& coins, int amount)//用二维dp数组
    {
        //dp[i][j]表示 用前 i 种硬币凑出金额 j 的最少硬币数
        vector<vector<uint64_t>> dp(coins.size()+1, vector<uint64_t>(amount + 1, INT_MAX));
        dp[0][0] = 0;
        for(int i = 1; i <= coins.size(); ++i)
        {
            for(int j = 0; j <= amount; ++j)
            {
                //不选
                dp[i][j] = dp[i-1][j];
                //选
                if(j >= coins[i-1] && dp[i][j-coins[i-1]] != INT_MAX)
                {    
                    dp[i][j] = min(dp[i][j], dp[i][j - coins[i-1]] + 1);
                }
            }
        }
        if (dp[coins.size()][amount] == INT_MAX) return -1;
        return dp[coins.size()][amount];
    }
    
};