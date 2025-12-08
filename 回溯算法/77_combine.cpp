#include <string>
#include <vector>
using namespace std;
class Solution {
public:
    vector<vector<int>> result;
    vector<int> temp;
    void backtracking(int n, int k, int startIndex) {
        if(temp.size() == k)
        {
            result.push_back(temp);
        }
        for(int i = startIndex; i <= n; ++i)
        {
            temp.push_back(i);
            backtracking(n, k, i + 1);
            temp.pop_back();
        }
        return;
    }
    
    vector<vector<int>> combine(int n, int k) {
        backtracking(n, k, 1);
        return result;
    }
};