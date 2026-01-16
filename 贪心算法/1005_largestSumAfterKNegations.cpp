class Solution {
public:
    int largestSumAfterKNegations(vector<int>& nums, int k) {
        
        priority_queue<int,vector<int>, std::greater<int>> queue;
        for (int n : nums)
        {
           queue.push(n);
        }
        for (int i = 0; i < k; ++i)
        {
            int temp = queue.top();
            queue.pop();
            queue.push(temp * (-1));
        }
        int result = 0;
        while(!queue.empty())
        {
            result += queue.top();
            queue.pop();
        }
        return result;
    }
};