class Solution {
public:
    int jump(vector<int>& nums) {
        if (nums.size() == 1) return 0;
        int curCover = 0;//当前最大覆盖范围
        int nextCover = 0;//下一步最大覆盖范围
        int result = 0;

        for (int i = 0; i < nums.size(); ++i)
        {
            nextCover = max(nums[i] + i, nextCover); //记录下一步最大覆盖范围
            if (i == curCover)
            {
                ++result;//步数加一
                curCover = nextCover;
                nextCover = 0;
                if(curCover >= nums.size() - 1) return result;
            }
        }
        return result;
    }
};