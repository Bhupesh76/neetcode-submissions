class Solution {
public:
    int search(vector<int>& nums, int target) 
    {
        // if(nums.size()<=1)
        // {
        //     if(nums[0] == target) return 0;
        //     else return -1;
        // }
        // int low=0;
        // int high=nums.size();

        // while(low<=high)
        // {
        //     int mid = (low+high)/2;

        //     if(nums[mid]<target)
        //     {
        //         low = mid+1;
        //     }
        //     else if(nums[mid] > target)
        //     {
        //         high = mid-1;
        //     }
        //     else if(nums[mid] == target)
        //     {
        //         return mid;
        //     }
        // }
        // return -1;
        int n = nums.size();
        for(int i=0;i<n;i++){
            if(nums[i]==target){
                return i;
                break;
            }
        }
        return -1;
    }
};
