class Solution {
public:

    void dfs(int i, int j, int m, int n, vector<vector<int>>&grid)
    {
        if(i<0 || i>=m || j<0 || j>=n || grid[i][j]!=1)
        {
            //invalid
            return;
        }

        //now grid[i][j]=1 mark it as visited(along boundary land)
        grid[i][j]=2;

        dfs(i-1,j,m,n,grid);
        dfs(i+1,j,m,n,grid);
        dfs(i,j-1,m,n,grid);
        dfs(i,j+1,m,n,grid);

    }
    int numEnclaves(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        //first we will mark the landslides that are along the boundary

        for(int i =0; i<m; i++)
        {
            for(int j =0; j<n; j++)
            {
                if((i==m-1 || i==0 || j==0 || j==n-1) && grid[i][j]==1)
                {
                    //along the boundary landslides
                    dfs(i,j,m,n,grid);
                }
            }
        }

        //now we are left with landslides that are not along boundary
        //and lands we cannot even reach from boundary

        int cnt =0;

        for(int i =0; i<m; i++)
        {
            for(int j =0; j<n; j++)
            {
                if(grid[i][j]==1)
                {
                    cnt++;
                }
            }
        }

        return cnt;

    }
};