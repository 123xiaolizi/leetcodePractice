class Solution {
public:
    /*
    核心转换思路：
    把"目标和"问题转化为"组合总和"问题：
    设所有添加 '+' 的数字和为 P
    设所有添加 '-' 的数字和为 N
    数组总和为 sum = P + N
    目标和为 S = P - N  // S 为target
    由此推导：
    P + N = sum
    P - N = S
    两式相加：2P = sum + S
    所以：P = (sum + S) / 2
    为什么 if ((S + sum) % 2) return 0？
    因为 P = (sum + S) / 2 必须是整数：
    如果 (sum + S) 是奇数，除以 2 会得到小数
    但 P 必须是整数（它是某些数字的和）
    所以如果 (sum + S) 是奇数，立即返回 0（无解）
    为什么 if (S > sum) return 0？
    P 至少为 0，所以 (sum + S) / 2 ≥ 0
    即 sum + S ≥ 0，也就是 S ≥ -sum
    同理，N 至少为 0，推导出 S ≤ sum
    所以如果 |S| > sum，无解
    数学转换的正确性证明：
    每个目标为 S 的表达式，唯一对应一个和为 P = (sum + S) / 2 的子集：
    "+" 号的数字集合就是该子集
    "-" 号的数字是补集
    */
    int findTargetSumWays(vector<int>& nums, int target) {
        int sum = 0;
        for (int it : nums)
            sum += it;
        if (abs(target) > sum)
            return 0;
        if ((target + sum) % 2 == 1)
            return 0;
        int bagSize = (target + sum) / 2;
        int* dp = new int[bagSize + 1]();
        dp[0] = 1;
        for (int i = 0; i < nums.size(); ++i) {
            for (int j = bagSize; j >= nums[i]; --j) {
                dp[j] += dp[j - nums[i]];
            }
        }
        return dp[bagSize];
    }
};