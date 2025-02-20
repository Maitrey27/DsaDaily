class Solution {
public:
    string ans;
    bool found = false;
    void generateString(int n, string &currStr, unordered_set<string>&st)
    {
        if(currStr.size()==n)
        {
           if(st.find(currStr)==st.end())
           {
                ans = currStr;
                found = true;
           }
            return;
        }

        for(char ch = '0'; ch<='1'; ch++)
        {
            if(found)
            {
                return;
            }
            currStr.push_back(ch);
            cout<<currStr<<" ";

            generateString(n,currStr,st);

            currStr.pop_back();
        }


    }
    string findDifferentBinaryString(vector<string>& nums) {
        int n = nums.size();
        string currStr = "";
        unordered_set<string>st(nums.begin(),nums.end());

        generateString(n,currStr,st);
        
        return ans;

    }
};