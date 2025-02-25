class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        int n = arr.size();

        long long even =0;

        int prefSum =0;
        int k = 2;
        unordered_map<int,int>mp;
        mp[0]=1;

        for(int i  = 0; i<n; i++)
        {
            prefSum+=arr[i];

            int rem = (prefSum%k+k)%k;

            if(mp.find(rem)!=mp.end())
            {
                even+=mp[rem];
            }

            mp[rem]++;
        }

        return (((long long )(n*(long long)(n+1)/2) - even)%(1000000007));
    }
};