class Solution {
public:
    bool ispalindrome(string s)
    {
        string temp = "";
        for(int i=0; i<s.size(); i++)
        {
            if(s[i] == ' ' || !isalnum(s[i]))
            {
                continue;
            }
            temp += tolower(s[i]);
        }

        int i=0; 
        int j=temp.size()-1;

        while(i<j)
        {
            if(temp[i] == temp[j])
            {
                i++;
                j--;
            }
            else 
            {
                return false;
            }
        }
        return true;
    }
    bool validPalindrome(string s) 
    {
        if(ispalindrome(s)) return true;

        for(int i=0; i<s.size(); i++)
        {
            string str = "";
            for(int j=0; j<s.size(); j++)
            {
                if(i == j) continue;

                str += s[j];
            }
            if(ispalindrome(str)) return true;
        }
        return false;
    }
};