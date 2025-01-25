class Solution {
public:

    void dfs(int i, int j, int n, int m, vector<vector<int>>&grid,int &cnt)
    {
        grid[i][j] =0;//vis

        cnt++;

        int delRow[] = {-1,0,1,0};
        int delCol[] = {0,1,0,-1};

        for(int dir =0; dir<4; dir++)
        {
            int newR = i+delRow[dir];
            int newC = j+delCol[dir];

            if(newR>=0 && newR<n && newC>=0 && newC<m && grid[newR][newC]==1)
            {
                dfs(newR,newC,n,m,grid,cnt);
            }
        }
    }
    int countServers(vector<vector<int>>& grid) {

       int n = grid.size();
       int m = grid[0].size();

       int totalServers =0;

       for(int i =0; i<n; i++)
       {
            for(int j =0;j<m; j++)
            {
                if(grid[i][j]==1)
                {
                    int cnt =0;
                    dfs(i,j,n,m,grid,cnt);

                    if(cnt>1)
                    {
                        //servers are connected to each other so >1
                        totalServers+=cnt;
                    }
                }
            }
       } 

       return totalServers;
    }
};