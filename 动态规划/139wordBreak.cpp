class Solution {
public:
    /*
    dp[i] : 字符串长度为i的话，dp[i]为true，表示可以拆分为一个或多个在字典中出现的单词。

    确定递推公式
    如果确定dp[j] 是true，且 [j, i] 这个区间的子串出现在字典里，那么dp[i]一定是true。（j < i ）。

    所以递推公式是 if([j, i] 这个区间的子串出现在字典里 && dp[j]是true) 那么 dp[i] = true。

    dp数组如何初始化
    从递推公式中可以看出，dp[i] 的状态依靠 dp[j]是否为true，那么dp[0]就是递推的根基，dp[0]一定要为true，否则递推下去后面都都是false了。
    */
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> wordDict_set(wordDict.begin(), wordDict.end());
        vector<bool> dp(s.size()+1, false);
        dp[0] = true;
        // ----j-------i-----类似于这样切割
        for(int i = 1; i <= s.size(); ++i)//背包
        {
            for(int j = 0; j < i; ++j)
            {
                string temp = s.substr(j, i - j);
                if(wordDict_set.find(temp) != wordDict_set.end() && dp[j]== true)
                {
                    dp[i] = true;
                }

            }
        }
        return dp[s.size()];
    }
};