class Solution {
public:

    unordered_map<int,list<int>>adj;
    unordered_map<int,int>bobMap;
    int aliceIncome;

    bool DFSBob(int curr, int dest,int time,vector<bool>&vis)
    {
        vis[curr]=true;
        bobMap[curr]=time;

        if(curr==dest)
        {
            //reached 0
            return true;
        }

        for(auto nbr: adj[curr])
        {
            if(vis[nbr]==false)
            {
                if(DFSBob(nbr,dest,time+1,vis)==true)
                {
                    return true;
                }
            }
        }

        //if not got 0 node (dest) explore another path
        bobMap.erase(curr);
        return false;
    }

    void DFSAlice(int curr, int time, int income, vector<bool>&vis,vector<int>&amount)
    {
        vis[curr]=true;

        if(bobMap.find(curr)==bobMap.end() || time < bobMap[curr])
        {
            //check if bob has never reached this particular node
            //if bob  not reached then open gate so  reward/gate fee

            //or alice reached earlier to that node than bob reached

             income+=amount[curr];
        }
        else if(time==bobMap[curr])
        {
            //both alice and bob reach to curr node at same time

            income+= (amount[curr]/2); //reward/fee will be half half
        }

        //if alice reaced leaf node check for optimal income
        if(adj[curr].size()==1 && curr!=0)
        {
            //leaf node will not have any nbr
            aliceIncome = max(aliceIncome,income);
        }


        for(auto nbr : adj[curr])
        {
            if(vis[nbr]==false)
            {
                DFSAlice(nbr,time+1,income,vis,amount);
            }
        }

    }
    int mostProfitablePath(vector<vector<int>>& edges, int bob, vector<int>& amount) {
        int n = amount.size();


        for(auto it: edges)
        {
            int u = it[0];
            int v = it[1];

            adj[u].push_back(v);
            adj[v].push_back(u); //tree

        }

        aliceIncome = INT_MIN;

        //step 1 : dfs on bob for finding time to reach  node till 0
        int dest =0;
        int time =0;
        vector<bool>vis(n,false);
        DFSBob(bob,dest,time,vis);

        //step 2: dfs on alice for finding the income to reach optimal leaf node
        int income =0;
        vector<bool>vis2(n,false);

        DFSAlice(0,0,income,vis2,amount);

        return aliceIncome;

    }
};