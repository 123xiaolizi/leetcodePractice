class Solution {
public:
    int numSquares(int n) {
        vector<int> dp(n+1,INT_MAX);
        dp[0] = 0;
        for(int i = 0; i <= n; ++i)//背包
        {
            for(int j = 1; j*j <= i; ++j)
            {
                dp[i] = min(dp[i], dp[i - j*j ] + 1);
            }
        }
        if (dp[n] == INT_MAX) return -1;
        return dp[n];
    }
};