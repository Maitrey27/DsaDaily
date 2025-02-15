class Solution {
public:
    // int dp[]
    bool check(int ind,int currSum, string &s, int num)
    {
        if(ind==s.length())
        {
            return currSum==num;
        }

        if(currSum>num)
        {
            return false;   
        }

        bool possible = false;

        for(int j = ind; j<s.length(); j++)
        {
            string temp = s.substr(ind,j-ind+1);

            int val = stoi(temp);

            possible = possible || check(j+1,currSum+val,s,num);

            if(possible==true)
            {
                return true;
            }
        }

        return possible;
    }
    int punishmentNumber(int n) {
        int punish =0;

        for(int num=1; num<=n; num++)
        {
            int sq=  num*num;

            string s= to_string(sq);

            if(check(0,0,s,num)==true)
            {
                punish+=sq;
            }
        }

        return punish;
    }
};