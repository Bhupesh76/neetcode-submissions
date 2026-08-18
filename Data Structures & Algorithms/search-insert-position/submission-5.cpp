class Solution {
public:
    int searchInsert(vector<int>& nums, int target) 
    {
        // if(target == 0) return 0;
        // if(nums.size() <= 1) return 0;
        int low = 0;
        int high = nums.size()-1;

        while(low <= high)
        {
            int mid = (low+high)/2;
            if(nums[mid] > target)
            {
                high = mid-1;
            }
            else if(nums[mid] < target)
            {
                low = mid+1;
            }
            else if(nums[mid] == target)
            {
                return mid;
            }
        }
        return low;
    }
};