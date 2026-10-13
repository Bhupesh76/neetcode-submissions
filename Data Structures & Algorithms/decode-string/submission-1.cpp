class Solution {
public:
    string decodeString(string s) 
    {
        stack<int> numst;
        stack<string> strst;

        string curr = "";
        int num = 0;

        for(char c : s)
        {
            if(isdigit(c))
            {
                num = num*10 + (c-'0');
            }
            else if(c == '[')
            {
                numst.push(num);
                strst.push(curr);
                num = 0;
                curr = "";
                continue;
            }
            else if(c == ']')
            {
                int k = numst.top(); numst.pop();
                string prev = strst.top(); strst.pop();

                string temp = "";

                for(int i=0; i<k; i++)
                {
                    temp += curr;
                }

                curr = prev + temp;
            }
            else
            {
                curr += c;
            }
        }
        return curr;
    }
};