class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int n = nums.size();

        double maxSum =INT_MIN;
        double sum =0;

        int i =0;
        int j =0;

        while(j<n)
        {
            sum = sum+nums[j];

            if(j-i+1==k)
            {
                //window hit k size subarry found
                if(maxSum<sum)
                {
                    maxSum = sum;
                }

                //slide the window
                sum = sum-nums[i];
                i++;
            }
            j++;
        }

        return maxSum/(double)k;
    }
};