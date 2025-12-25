class Solution {
public:
    bool isValid(string &s, int left, int right)
    {
        if(left > right) return false;
        if(s[left] == '0' && left != right) return false;
        int num = 0;
        for (int i = left; i <= right; ++i)
        {
            if(s[i] > '9' || s[i] < '0') return false;
            num = num * 10 + (s[i] - '0');
            if(num > 255) return false;
        }
        return true;
    }
    vector <string> result;
    void backtracking(string &s, int pointNum, int startIndex)
    {
        if (pointNum == 3)
        {
            //判断最后一段是否合法
            if(isValid(s, startIndex , s.size() - 1))
            {
                result.push_back(s);
            }
            return;
        }
        for(int i = startIndex; i < s.size(); ++i)
        {
            if(isValid(s, startIndex , i))//合法就添加'.'
            {
                s.insert(s.begin()+ i + 1, '.');
                ++pointNum;
                backtracking(s, pointNum, i + 2); // 因为加了'.'所以这里变为＋2
                s.erase(s.begin()+ i + 1);
                --pointNum;
            }
            else break; // 不合法，直接结束本层循环
        }
    }
    vector<string> restoreIpAddresses(string s) {
        result.clear();
        backtracking(s, 0, 0);
        return result;
    }
};