class Solution {
public:
    int partition(vector<int> &arr, int low, int high)
    {
        int pivot = arr[low];
        int i = low;
        int j = high;

        while(i<j)
        {
            while(i<high && arr[i] <= pivot)
            {
                i++;
            }

            while(j>low && arr[j] > pivot)
            {
                j--;
            }

            if(i<j) 
            {
                swap(arr[i],arr[j]);
            }
        }
        swap(arr[low],arr[j]);
        return j;
    }
    void qs(vector<int> &arr, int low, int high)
    {
        if(low < high)
        {
            int pIndex = partition(arr,low,high);
            qs(arr,low,pIndex-1);
            qs(arr,pIndex+1,high);
        }
    }
    vector<int> sortArray(vector<int>& arr) 
    {
        qs(arr,0,arr.size()-1);
        return arr;
    }
};