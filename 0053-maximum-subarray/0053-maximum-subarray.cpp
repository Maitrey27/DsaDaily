class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxSum = INT_MIN;
        int sum  = 0;
        for(int i = 0; i<nums.size(); i++)
        {
            sum +=nums[i];
            if(sum>maxSum)
            {
                maxSum = sum;
            }
            if(sum<0)
            {
                //we will not consider the negative element as they will reduce the maxsum
                sum =0;
            }


            // //if overall maxSum = negative then return sum =0;
            // if(maxSum<0)
            // {
            //     maxSum = 0;
            // }
        }
        return maxSum;
    }
};