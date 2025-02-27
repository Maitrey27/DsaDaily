class Solution {
public:
    int dp[998][998];
    int solve(int j, int k, vector<int>&arr, unordered_map<int,int>&mp)
    {
        //i<j<k for fibonnaci arr[k] = arr[i]+arr[j] 
        if(dp[j][k]!=-1)
        {
            return dp[j][k];
        }
        int prev = arr[k]-arr[j]; //prev->arr[i]

        //check if this prev exist in map or not and check i<j
        if(mp.find(prev)!=mp.end() && mp[prev]<j)
        {   int i = mp[prev];
            return dp[j][k] = solve(i,j,arr,mp) +1; //1 for prev (fib) char found
        }

        return dp[j][k] = 2; //if (i,j) not able to find prev char then nums[i]&nums[j]=2


    }
    int lenLongestFibSubseq(vector<int>& arr) {
        int n = arr.size();
        unordered_map<int,int>mp;
        memset(dp,-1,sizeof(dp));
        for(int i =0; i<n; i++)
        {
            //store ind for every element for fast lookup
            mp[arr[i]] =i;
        }

        int maxLen = 0;
        
        for(int j = 1; j<n; j++)
        {
            for(int k = j+1; k<n; k++)
            {
                int length = solve(j,k,arr,mp);

                if(length>=3)
                {
                    //now for fibonacci it should have atleast 3 elements its given
                    maxLen = max(maxLen,length);
                }
            }
        }

        return maxLen;
    }
};