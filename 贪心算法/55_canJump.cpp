class Solution {
public:
    bool canJump(vector<int>& nums) {
        if (nums.size() == 1) return true;
        int coverIndex = 0;
        for (int i = 0; i <= coverIndex; ++i)
        {
            if ((nums[i] + i) > coverIndex)
            {
                coverIndex = nums[i] + i;
            }
            // 如果已经能覆盖到最后一个位置，提前返回
            if (coverIndex >= nums.size() - 1) 
            {
                return true;
            }
        }
        return coverIndex == nums.size()-1;

    }
};