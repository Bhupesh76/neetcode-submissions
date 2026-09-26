class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) 
    {
        int l = 1;
        int r = *max_element(piles.begin(), piles.end());
        int rate = r;

        while(l<=r)
        {
            int mid = l + (r-l) / 2;
            long long t = 0;
            for(int x:piles)
            {
                t += (x+mid-1)/mid;
                if(t>h) break;
            }

            if(t<=h)
            {
                rate = mid;
                r = mid-1;
            }
            else
            {
                l = mid+1;
            }
        }
        return rate;
    }
};
