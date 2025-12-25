class Solution {
public:
    bool isPalindrome(string str, int left, int right)
    {
        while(left < right)
        {
            if(str[left++] != str[right--]) return false;   
        }
        return true;
    }
    vector<vector<string>> result;
    vector<string> path;
    void backtrackint(string s, int startIndex)
    {
        if(startIndex >= s.size())
        {
            result.push_back(path);
            return;
        }
        for (int i = startIndex; i < s.size(); ++i)
        {
            if(isPalindrome(s, startIndex, i))//回文子串
            {
                string str = s.substr(startIndex, i - startIndex + 1);
                path.push_back(str);
            }
            else continue;
            backtrackint(s, i + 1);
            path.pop_back();
        }
    }
    vector<vector<string>> partition(string s) {
        path.clear();
        result.clear();
        backtrackint(s, 0);
        return result;
    }
};