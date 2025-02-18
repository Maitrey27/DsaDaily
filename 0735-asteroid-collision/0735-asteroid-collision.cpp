class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        int n = asteroids.size();
        
        stack<int>st;

        for(int i =0; i<n; i++)
        {
            if(asteroids[i]>0)
            {
                //+ve asteroids
                st.push(asteroids[i]);
            }else{
                //-ve asteroids
                
                while(!st.empty() && st.top()>0 && abs(asteroids[i])>st.top())
                {
                    st.pop();
                }

                if(!st.empty() && st.top()==abs(asteroids[i]))
                {
                    //+ve asteroid is equaL to the  -ve asteroid'
                    st.pop(); //collide both

                }else{
                    if(st.empty() || st.top()<0)
                    {
                        //empty
                        st.push(asteroids[i]);
                    }
                }



            }

        }

        vector<int>ans;

        while(!st.empty())
        {
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};