/*
    nums[i]   = [4,1,3,3]
    nums[i]-i = [4,0,1.0];

    mp {4:1}
                      j
    for j->1 to n  [4,0,1,0]

    cntofnumsj => mp[nums[j]] = 0;  //is this element occured in map before
    totalNumsBeforeJ = 1

    badpairs = 1-0-> 1   cnt = 1
                                        j
    for j = 2      mp {4:0, 0:1}   [4,0,1,0]

    cntofnumsj => mp[nums[j]] = 0
    totalNumsBeforeJ = 2

    badpairs = 2-0 =2  , cnt = 1+2 = 3
                                           j
    for j = 3   mp{4:0. 0:1, 1:1}   [4,0.1.0]
    
    cntofnumsj => mp[nums[j]] = mp[0]->1  //bcz zero already present so it wontbe bad pair
    totalNumsBeforeJ = 3

    badpair = 3-1 =2    . cnt = 3+2 =>5 ans
    
*/


class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        int n = nums.size();

        //whenever we see equn which hs relation of position and value at that index
        //group the same family equn togetehr

        //so new equn becomes nums[i]-i!= nums[j]-j

        long long cnt =0;

        for(int i =0; i<n; i++)
        {
            nums[i] = nums[i]-i; 
        }

        unordered_map<int,int>mp;
        mp[nums[0]] = 1; 

        //now since we found out nums[i]-i now we will check if nums[j]-j not exist then bad pair

        for(int j = 1; j<n; j++)
        {
            int countOfNumsJ     = mp[nums[j]]; //jth ind ka element kitne bar dekliya phle

            int totalNumsBeforeJ = j; // elements before j

            int badPairs = totalNumsBeforeJ - countOfNumsJ;

            cnt+=badPairs;

            mp[nums[j]]++; //increase the cnt of curr element in nums
        }

        return cnt;
    }
};