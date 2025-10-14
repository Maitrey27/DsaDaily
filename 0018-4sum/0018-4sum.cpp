class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n = nums.size();
        vector<vector<int>>ans;
        sort(nums.begin(),nums.end());

        for(int i =0; i<n; i++)
        {
            //fix i pointer
            if(i>0 && nums[i]==nums[i-1])
            {
                //skip the duplicates
                continue;
            }

            for(int j = i+1; j<n; j++)
            {
                //fix the j pointer also 
                if(j>i+1 && nums[j]==nums[j-1])
                {
                    //skip the duplicates
                    continue;
                }

                //take two moving pointers
                int k = j+1;
                int l = n-1;

                while(k<l)
                {
                    long long sum  = nums[i] + nums[j];
                    sum+= nums[k];
                    sum+= nums[l];

                    if(sum<target)
                    {
                        //then increase the sum
                        k++; 
                    }else if(sum>target)
                    {
                        //then decrease the sum
                        l--;
                    }else{
                        //sum==target
                        vector<int>temp = {nums[i],nums[j],nums[k],nums[l]};
                        ans.push_back(temp);
                        k++;
                        l--;


                        //while moving k & l check if they do not encounter same element
                        while(k<l && nums[k]==nums[k-1]) k++;
                        while(k<l && nums[l]==nums[l+1]) l--;
                    }
                }
            }
        }

        return ans;

    }
};