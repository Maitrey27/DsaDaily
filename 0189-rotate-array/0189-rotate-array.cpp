class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k = k%n;

        //reverse n-k element [4,3,2,1,5,6,7]
        reverse(nums.begin(),nums.begin()+n-k);
        //reverse k elements [4,3,2,1,7,6,5]
        reverse(nums.begin()+n-k,nums.end());

        //now reverse entire [5,6,7,1,2,3,4]
        reverse(nums.begin(),nums.end());

    }
};