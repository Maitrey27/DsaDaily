class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();

        unordered_map<int,int>mp;


        for(int i =0; i<n ; i++)
        {
            int x = nums[i];

            int rem = target-x;

            if(mp.find(rem)!=mp.end())
            {
                //rem exist (pair exist)
                return {i,mp[rem]};
            }

            mp[x]= i;
        }

        return {-1,-1};
    }
};