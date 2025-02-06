class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {
        int n = nums.size();

        sort(nums.begin(),nums.end()); //sorted and then find the value of a=b and c=d

        int tuples =0;


        for(int i =0; i<n; i++)
        {
            for(int j =n-1; j>i; j--)
            {
                int a_x_b = nums[i]*nums[j];
                unordered_set<int>st; //for every i and j
                
                for(int k = i+1; k<j; k++)
                {
                    //check for every value of k that (d) exist or not
                    int c_value = nums[k];
                    if(a_x_b % c_value ==0)
                    {
                        int d_value = a_x_b/c_value;

                        if(st.count(d_value))
                        {
                            //check if it already exist in set or not
                            tuples++;
                        }

                        st.insert(c_value);
                    }
                }
            }
        }

        return tuples*8; //bcz every tuple has permuation of 8 
    }
};