class Solution {
public:
    vector<int> path;
    vector<vector<int>> result;

    void backtracking(vector<int>&nums, vector<bool> &used)
    {
        if(path.size() == nums.size())
        {
            result.push_back(path);
            return;
        }
        
        for (int i = 0; i < nums.size(); ++i)
        {
            if((i > 0 && nums[i-1] == nums[i] && used[i - 1] == false) || used[i] == true)continue;
            path.push_back(nums[i]);
            used[i] = true;
            backtracking(nums, used);
            path.pop_back();
            used[i] = false;
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        path.clear();
        result.clear();
        std::sort(nums.begin(), nums.end());
        vector<bool> used(nums.size(), false);
        backtracking(nums, used);
        return result;
    }
};