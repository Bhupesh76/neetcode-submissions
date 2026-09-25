class Solution {
public:
    int mySqrt(int x) 
    {
        if(x<2) return x;
        int i = 1;
        int j = x/2;
        int ans = 0;
        while(i<=j)
        {
            int mid = (i+j)/2;
            long long sq = 1LL * mid*mid;
            if(sq == x)
            {   
                return mid;
            }
            else if(sq>x)
            {
                j = mid-1;
            }
            else
            {
                i = mid + 1;
                ans = mid;
            }
        }
        return ans;
    }
};