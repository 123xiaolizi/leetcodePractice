#include <string>
#include <vector>
using namespace std;
class Solution {
public:
    vector<vector<int>> result;
    vector<int> temp;
    int sum() {
        int sum = 0;
        for(const auto it : temp) {
            sum += it;
        }
        return sum;
    }
    void backtracking(int n, int k, int startIndex) {
        if(temp.size() == k && sum()== n)
        {
            result.push_back(temp);
        }
        for(int i = startIndex; i <= 9; ++i)
        {
            temp.push_back(i);
            backtracking(n, k, i + 1);
            temp.pop_back();
        }
        return;
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        backtracking(n, k, 1);
        return result;
    }
};