class Solution {
public:
    bool isArraySpecial(vector<int>& nums) {
        int n =nums.size(); 
        //parity -> even /odd

        if(n==1)
        {
            return true;
        }

        for(int i =0; i<=n-2; i++)
        {
            if(nums[i]%2==nums[i+1]%2)
            {
                //both odd
                return false;
            }
            if(nums[i]%2==0 && nums[i+1]%2==0)
            {
                //both even
                return false;
            }
        }

        //one odd one even or one even one odd
        return true;
    }
};