class Solution {
public:
    int firstMissingPositive(vector<int>& nums) 
    {
        if(nums.empty()) return 1;

        sort(nums.begin(), nums.end());

        unordered_set<int> st(nums.begin(), nums.end());

        int n = nums.size();

        for(int i = 1; i < INT_MAX; i++)
        {
            if(st.find(i) == st.end())
                return i;
        }

        return nums[n-1] + 1;
    }
};