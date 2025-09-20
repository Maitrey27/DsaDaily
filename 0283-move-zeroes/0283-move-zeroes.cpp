class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n = nums.size();

        int zeros =0;
        int pos =0;
        for(int i =0; i<n; i++)
        {
            if(nums[i]!=0)
            {
                nums[pos]=nums[i];
                pos++;
            }

            zeros++;
        }

        while(zeros-- && pos<n)
        {
            nums[pos]=0;
            pos++;
        }

    }
};