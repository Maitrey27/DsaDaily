class Solution {
public:
    string removeOuterParentheses(string s) {
        int balance = 0;
        string res="";

        for(auto ch : s)
        {
            if(ch=='(')
            {
                if(balance>0)
                {
                    res=res+ch;
                }
                balance++;
            }
            else
            {
                balance--;
                if(balance>0)
                {
                    res=res+ch;
                }
            }
        }
            return res;
    }
};