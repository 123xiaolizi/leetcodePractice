class Solution {
public:
    int change(int amount, vector<int>& coins) {
        uint64_t* dp = new uint64_t[amount+1]();//dp[i]表示装满容量为i的方式有dp[i]种
        dp[0] = 1;
        for(int i = 0; i < coins.size(); ++i)//物品
        {
            for(int j = coins[i]; j <= amount; ++j)//背包
            {
                dp[j] += dp[j - coins[i]];
            }
        }
        int resulet = dp[amount];
        delete[] dp;
        return resulet;
    }
};