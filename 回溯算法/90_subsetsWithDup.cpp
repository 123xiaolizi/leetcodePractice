class Solution {
public:

    vector<int> path;
    vector<vector<int>> result;

    void backtracking(vector<int> &nums, int startIndex, vector<bool> &used)
    {
        result.push_back(path);
        if(startIndex >= nums.size()) return;
        for(int i = startIndex; i < nums.size(); ++i)
        {
            if (i > 0 && nums[i] == nums[i - 1] && used[i - 1] == false)
            {
                continue;
            }
            path.push_back(nums[i]);
            used[i] = true;
            backtracking(nums, i + 1, used);
            path.pop_back();
            used[i] = false;
        }
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        std::sort(nums.begin(), nums.end());
        vector<bool> used(nums.size(), false);
        result.clear();
        path.clear();
        backtracking(nums, 0, used);
        return result;
    }
};