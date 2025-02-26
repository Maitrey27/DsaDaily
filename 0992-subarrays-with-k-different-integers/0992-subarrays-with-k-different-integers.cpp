class Solution {
public:
    int solve(vector<int>&nums,int k)
    {
        int n = nums.size();
        int l =0;
        int r =0;
        unordered_map<int,int>mp;
        int cnt =0;

        while(r<n)
        {
            mp[nums[r]]++;

            while(mp.size()>k && l<=r)
            {
                //we got more than k distinct elements

                //slide the window
                mp[nums[l]]--;

                //if while decreasing the count of element its count =0 
                if(mp[nums[l]]==0)
                {
                    mp.erase(nums[l]);
                }
                l++;
            }

            cnt+=r-l+1;
            r++;
        }
        return cnt;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        // Subtracting the count of subarrays with at most ( k-1 ) distinct elements 
        //from the count of subarrays with at most ( k ) distinct elements gives us the count of subarrays with exactly ( k ) distinct elements.
        cout<<solve(nums,k)<<endl;
        cout<<solve(nums,k-1)<<endl;

        return solve(nums,k) - solve(nums,k-1);
    }
};