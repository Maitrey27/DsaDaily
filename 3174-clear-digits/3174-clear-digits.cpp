class Solution {
public:
    string clearDigits(string s) {
        int n = s.length();
        string ans = "";
        for(int i =0; i<n; i++)
        {   char ch  = s[i];
            int digInd = 0;
            if(isdigit(ch))
            {
                digInd = i;
                s[i]= '#'; //mark to remove the digit
            }

            for(int j =digInd-1; j>=0;j--)
            {
                char ch = s[j];

                if(isalpha(ch))
                {
                    s[j]='#';
                    break;
                }
            }


        }

        for(auto ch: s)
        {
            if(ch!='#')
            {
                ans+=ch;
            }
        }

        return ans;
    }
};