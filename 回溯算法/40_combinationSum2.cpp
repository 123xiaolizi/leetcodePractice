class Solution {
public:
    vector<int> path;
    vector<vector<int>> result;
    void backtracking(vector<int>& candidates, int target, int sum, int startIndex, vector<int> usred)
    {
        if(sum > target) return;
        if(sum == target)
        {
            result.push_back(path);
            return;
        }
        for(int i = startIndex; i < candidates.size(); ++i)
        {
            if(i > 0 && candidates[i] == candidates[i - 1] && usred[i - 1] == false) continue;
            usred[i] = true;
            sum += candidates[i];
            path.push_back(candidates[i]);
            backtracking(candidates, target, sum, i + 1, usred);
            usred[i] = false;
            sum -= candidates[i];
            path.pop_back();            
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        path.clear();
        result.clear();
        std::sort(candidates.begin(), candidates.end());
        vector<int> usred(candidates.size(), false);
        backtracking(candidates, target, 0, 0, usred);
        return result;
    }
};