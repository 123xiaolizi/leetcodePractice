#include <string>
#include <vector>
using namespace std;
class Solution {
public:
    string letterMap[10] = {
        "",
        "",
        "abc",
        "def",
        "ghi",
        "jkl",
        "mno",
        "pqrs",
        "tuv",
        "wxyz"
    };
    string s;
    vector<string> result;
    void backtracking(string digits, int startIndex)
    {
        if(startIndex == digits.size())
        {
            result.push_back(s);
            return;
        }
        int num = digits[startIndex] - '0';
        string temp = letterMap[num];
        for(int i = 0; i < temp.size(); ++i)
        {
            s.push_back(temp[i]);
            backtracking(digits, startIndex + 1);
            s.pop_back();
        }
        return;
    }
    vector<string> letterCombinations(string digits) {
        backtracking(digits, 0);
        return result;
    }
};