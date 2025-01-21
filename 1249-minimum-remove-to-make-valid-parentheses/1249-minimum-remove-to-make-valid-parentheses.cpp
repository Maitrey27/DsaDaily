class Solution {
public:
    string minRemoveToMakeValid(string s) {
        int n = s.length();

        string ans = "";

        stack<pair<char,int>>st;

        for(int i = 0; i<n; i++)
        {
            char ch = s[i];
            if(ch=='(')
            {
                st.push({ch,i});
            }
            else if(ch==')')
            {
                if(!st.empty() && st.top().first=='(')
                {
                    //for every open ->close balanced
                    st.pop();
                }
                else{
                    st.push({ch,i});
                }
            }
        }
        unordered_set<int>invalid;

        while(!st.empty())
        {
            int ind = st.top().second;
            st.pop();
            invalid.insert(ind);
        }
        
        //now if stack has any parenthesis then we have inbalanced parenthesis
        for(int i =0; i<n; i++)
        {      
            if(invalid.find(i)==invalid.end())
            {
                ans+=s[i];
            }
        }

        return ans;
    }
};