class Solution {
public:
    bool hasAllCodes(string s, int k) {
        int n = s.length();

        int i =0;
        int j =0;

        unordered_set<string>st;
        string code = "";
        while(j<n)
        {
            code+=s[j];

            while(j-i+1>k)
            {
                code.erase(0,1);//remove the first char of window to slide the window
                i++;
            }

            if(j-i+1==k)
            {   
                //store the k size substr in set
                st.insert(code);
            }

            j++;
        }

        //every binary code substr is 2^k
        for(auto str : st)
        {
            cout<<str<<" ";
        }
        return st.size()==pow(2,k);
    }
};