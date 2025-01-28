class Solution {
public:
     void solve(int ind,int n, vector<int>&nums, set<vector<int>>&st)
    {
        if(ind>=n)
        {
            st.insert(nums);
            return;
        }
        
        for(int j = ind; j<n; j++)
        {
            swap(nums[ind],nums[j]);
            
            solve(ind+1,n,nums,st);
            
            //backtrack
            swap(nums[ind],nums[j]);
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
         int n = nums.size();
        set<vector<int>>st;
        
        solve(0,n,nums,st);
        vector<vector<int>>result(st.begin(),st.end());
        
        return result;
    }
};