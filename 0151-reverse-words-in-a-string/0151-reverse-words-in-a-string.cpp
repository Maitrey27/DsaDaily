class Solution {
public:
    string reverseWords(string s) {
        string word = "";
        int n = s.size();

        stack<string> st;
        int i =0 ;
        
        while(i<n)
        {
            //push the ch to word until space occurs
            if(s[i]!=' ')
            {
                word+=s[i];
            }
            else
            {
                //as soon as space occurs stop and push the word to stack
                while(!word.empty())
                {
                    st.push(word);
                    word="";
                }
            }
            i++;
        }

        //push the last word 
        if(!word.empty())
        {
            st.push(word);
        }

        // string ans;
        s="";
        //push the words back from the stack to a new string
        while(!st.empty())
        {
            string temp = st.top();
            s = s + temp + " ";
            st.pop();
        }

        //remove the last extra spaces
        if(!s.empty())
        {
            s.pop_back();
        }
        return s;



    }
};