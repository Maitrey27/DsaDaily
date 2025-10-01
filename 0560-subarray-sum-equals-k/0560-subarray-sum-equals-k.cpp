class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();

        unordered_map<int,int> mp;

        //initially
        mp[0]=1;

        int prefSum = 0, cnt = 0;

        for(int i = 0; i< n ; i++)
        {
            prefSum = prefSum + nums[i];
            int remove = prefSum - k;

            //add the no of subarrays to be removed as the number of subarrays to be removed is equal to the no of subarrays with sum k
            // cout<<mp[remove]<<" ";
            if(mp.find(remove)!=mp.end())
            {
                cnt = cnt + mp[remove];
            }

            mp[prefSum]+=1;
        }

        for(auto it: mp)
        {
            cout<<it.first<<"->"<<it.second<<endl;
        }

        return cnt;
    }
};