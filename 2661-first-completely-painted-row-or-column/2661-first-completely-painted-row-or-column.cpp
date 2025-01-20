class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();

        unordered_map<int,int>mp;

        for(int i =0; i<arr.size(); i++)
        {
            //reverse mapping we will store ind arr, take values from matrix and find ind from map
            int val = arr[i];
            mp[val] =i;
        }

        int minInd = INT_MAX;

        //check each row one by one

        for(int row = 0; row<m; row++)
        {
            int lastInd = INT_MIN; //last ind in arr when this row will be completely painted

            for(int col =0; col<n; col++)
            {
                int val = mat[row][col];
                int ind = mp[val];

                lastInd = max(lastInd,ind);
            }

            minInd = min(minInd,lastInd);
        }

        //check each col one by one

        for(int col = 0; col<n; col++)
        {
            int lastInd = INT_MIN; //last ind in arr when this col will be completely painted

            for(int row =0; row<m; row++)
            {
                int val = mat[row][col];
                int ind = mp[val];

                lastInd = max(lastInd,ind);
            }

            minInd = min(minInd,lastInd);
        }

        return minInd;
        
    }
};