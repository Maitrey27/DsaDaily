class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();

        //terminal node is node with outdegree=0

        //we will use topo sort with reversing the edges (push the node having less outdegree)
       
        /*

        3
        ^  \
        |   >
        0<--1
        ^  ^
        | /
        2<--5<--4  6


        according to  indegree now safenodes array will contain only nodes that are neither 
        part of cycle neither of there edge leads to any cycle


        */


        queue<int>q;

        vector<vector<int>>reverseAdj(n);


        for(int u =0; u<n; u++)
        {
            for(auto v : graph[u])
            {
                reverseAdj[v].push_back(u);
            }
        }

        vector<int>indegree(n,0);

        for(int i =0; i<n; i++)
        {
            for(auto it: reverseAdj[i])
            {
                indegree[it]++;
            }
        }

        for(int i =0; i<n; i++)
        {
            if(indegree[i]==0)
            {
                q.push(i);
            }
        }

        vector<bool>isSafe(n,false);

        while(!q.empty())
        {
            int node = q.front();
            q.pop();

            isSafe[node]=true;

            for(auto nbr: reverseAdj[node])
            {
                indegree[nbr]--;

                if(indegree[nbr]==0)
                {
                    q.push(nbr);
                }
            }
        }

        vector<int>safeNodes;

        for(int i =0; i<n; i++)
        {
            if(isSafe[i]==true)
            {
                safeNodes.push_back(i);
            }
        }

        return safeNodes;
        
    }
};