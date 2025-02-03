class Solution {
public:

    void dfs(int n,int room,vector<bool>&vis,vector<vector<int>>&rooms)
    {
        vis[room]=true; 

        for(auto adjRoom : rooms[room])
        {
            if(vis[adjRoom]==false)
            {
                dfs(n,adjRoom,vis,rooms);
            }
        }
    }
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();

        vector<bool>vis(n,false);

        dfs(n,0,vis,rooms);

        for(int i =0; i<n; i++)
        {
            if(vis[i]==false)
            {
                //we cannot visit room
                return false;
            }
        }

        return true; //all rooms visited
    }
};