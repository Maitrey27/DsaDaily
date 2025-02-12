class Solution {
public:

    int toDigit(int num)
    {
        int digitSum =0;

        while(num>0)
        {
            digitSum+= num%10;
            num=num/10;
        }

        return digitSum;
    }
    int maximumSum(vector<int>& nums) {
        int n = nums.size();

        vector<int>arr(82,0);  //max digit sum 9+9+9+9+9+9+9+9+9
       // ind->digitSum and value->nums[i]
        
        int result = -1;

        for(int i =0; i<n; i++)
        {
            int digitSum = toDigit(nums[i]);

            if(arr[digitSum]>0)
            {
                //then digitSum already found for some nums[i] prev
                result = max(result,nums[i]+arr[digitSum]);
            }

            arr[digitSum] = max(nums[i],arr[digitSum]);
        }

        return result;
    }
};