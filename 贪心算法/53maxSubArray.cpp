class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int max = nums[0];
        int sum = nums[0];
        for (int i = 1; i < nums.size(); ++i)
        {
            if(sum > 0)
            {
                sum += nums[i];
                max = max < sum ? sum : max;
            }
            else
            {
                sum = nums[i];
                max = max < sum ? sum : max;
            }
        }
        return max;
    }
};