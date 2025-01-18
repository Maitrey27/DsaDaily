class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int n = nums.size();

        for(int i=0; i<n; i++)
        {
            if(nums[i]%2==0)
            {
                nums[i]=0;
            }else{
                nums[i]=1;
            }
        }

        unordered_map<int,int> mp;
        int cnt =0;
        int prefSum =0;
        mp[0]= 1;

        for(int i =0; i<n; i++)
        {
            prefSum +=nums[i];

            int rem = prefSum -k;

            cnt+=mp[rem];

            mp[prefSum]+=1;
        }
        return cnt;
    }
};