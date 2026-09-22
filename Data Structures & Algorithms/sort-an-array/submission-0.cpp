class Solution {
public:
    vector<int> sortArray(vector<int>& arr) 
    {
        for(int i=0; i<arr.size()-1; i++)
        {
            int mini = i;
            for(int j=i; j<arr.size(); j++)
            {
                if(arr[j] < arr[mini])
                {
                    mini = j;
                }
            }
            int temp = arr[mini];
            arr[mini] = arr[i];
            arr[i] = temp;
        }
        return arr;
    }
};