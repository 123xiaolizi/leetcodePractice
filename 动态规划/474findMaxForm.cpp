class Solution {
public:
    
    int findMaxForm(vector<string>& strs, int m, int n) {
        vector<vector<int>> dp(m+1,vector<int>(n+1,0));
        for(int h = 0; h < strs.size(); ++h)
        {
            int zeroNum =0;
            for(const char it : strs[h])
            {
                if(it == '0') ++zeroNum;
            }
            int oneNum = strs[h].size() - zeroNum;
            for(int i = m; i >= zeroNum; --i)
            {
                for(int j = n; j >= oneNum; --j)
                {
                    dp[i][j] = max(dp[i-zeroNum][j-oneNum] + 1, dp[i][j]);
                }
            }
        }
        return dp[m][n];
    }
};