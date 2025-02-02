class Solution {
public:
    bool check(vector<int>& nums) {
        int rotate_point = 0;
        int n = nums.size();
        vector<int> rotArray(n);
        //first find in the array the point where rotation occurs
        // i.e the point where array is not in non decreasing order
        for(int i =1; i<n; i++)
        {
            if(nums[i]<nums[i-1])
            {
                rotate_point = i;
                break;
            }
        }

    for(int i = 0; i < n - rotate_point; i++) {
        rotArray[i] = nums[i + rotate_point];
    }
    for(int i = n - rotate_point; i < n; i++) {
        rotArray[i] = nums[i - n + rotate_point];
    }

        sort(nums.begin(),nums.end());
        return rotArray ==nums;
    }
};