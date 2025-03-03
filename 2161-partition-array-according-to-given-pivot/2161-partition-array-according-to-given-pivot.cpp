class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        int n = nums.size();

        int lessThanPivotCnt =0;
        int equalToPivotCnt =0;

        for(int i =0; i<n; i++)
        {
            if(nums[i]<pivot)
            {
                lessThanPivotCnt++;
            }
            else if(nums[i]==pivot)
            {
                equalToPivotCnt++;
            }
        }

        //now point the indexes
        int i = 0;
        int j = lessThanPivotCnt;
        int k = lessThanPivotCnt + equalToPivotCnt;

        vector<int>ans(n);
        for(auto  num : nums)
        {
            if(num<pivot)
            {
                ans[i]=num;
                i++;
            }
            else if(num==pivot)
            {
                ans[j]=num;
                j++;
            }
            else{
                
                    ans[k]=num;
                    k++;
                
            }
        }

        return ans;
    }
};