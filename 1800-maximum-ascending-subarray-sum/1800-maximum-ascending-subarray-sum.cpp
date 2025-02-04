class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        int n = nums.size();

        int maxSum = INT_MIN;

        for(int i =0; i<n; i++)
        {
            int sum = nums[i];

            for(int j = i+1; j<n && nums[j]>nums[j-1];j++)
            {
                sum+=nums[j];
                
            }
            maxSum  = max(maxSum,sum);
        }
        return maxSum;
    }
};