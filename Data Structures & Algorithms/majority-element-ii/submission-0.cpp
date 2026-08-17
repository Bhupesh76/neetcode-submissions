class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) 
    {
        vector<int> ans;

        int n = nums.size();

        unordered_map<int,int> mpp;
        for(int i=0; i<n; i++)
        {
            mpp[nums[i]]++;
            if(mpp[nums[i]] > (n/3))
            {
                if(find(ans.begin(), ans.end(), nums[i]) == ans.end())
                {
                    ans.push_back(nums[i]);
                }
            }
        }

        // for(int i=0; i<n; i++)
        // {
        //     if(mpp[nums[i]] > (n/3))
        //     {
        //         ans.push_back(nums[i]);
        //     }
        // }
        return ans;
    }
};