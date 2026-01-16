class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        int count = 0;
        int index = g.size() - 1;
        for (int i = s.size() - 1; i >= 0; --i)
        {
            while(index >= 0)
            {
                if( s[i] >= g[index])
                {
                    ++count;
                    --index;
                    break;
                }
                --index;
            }
        }
        return count;
    }
};