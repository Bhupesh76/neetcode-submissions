class Solution {
public:
    int calPoints(vector<string>& op) 
    {
        vector<int> rec;

        for(int i=0; i<op.size(); i++)
        {
            if(op[i] == "+")
            {
                int n = rec.size();
                rec.push_back(rec[n-1]+rec[n-2]);
            }
            else if(op[i] == "D")
            {
                rec.push_back(rec.back()*2);
            }
            else if(op[i] == "C")
            {
                rec.pop_back();
            }
            else
            {
                rec.push_back(stoi(op[i]));
            }
        }
        int sum = 0;
        for(int x:rec)
        {
            sum += x;
        }
        return sum;
    }
};