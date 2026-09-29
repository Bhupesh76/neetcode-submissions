class Solution {
public:
    int shipWithinDays(vector<int>& nums, int days) 
    {
        int l = *max_element(nums.begin(),nums.end());

        int h = accumulate(nums.begin(),nums.end(),0);
        int ans = h;
        while(l<=h)
        {
            int mid = (l+h)/2;
            int cnt = 1;
            int sum = 0;

            for(int w : nums)
            {
                if(sum+w > mid)
                {
                    cnt++; 
                    sum = 0;
                }
                sum += w;
            }
            if(cnt <= days)
            {
                ans = mid; 
                h = mid-1;
            }
            else
            { 
                l = mid+1;
            }
        }
        return ans;
    }
};