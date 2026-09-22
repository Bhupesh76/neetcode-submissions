class Solution {
public:
    vector<int> sortArray(vector<int>& arr) 
    {
        
        for(int i=arr.size()-1; i>=1; i--)
        {
            int swap = 0;
            for(int j=0; j<i; j++)
            {
                if(arr[j] > arr[j+1])
                {
                    int temp = arr[j];
                    arr[j] = arr[j+1];
                    arr[j+1] = temp;
                    swap = 1;
                }
            }
            if(swap == 0) break;
        }
        return arr;
    }
};