class Solution {
public:

    vector<bool> checkIfPrerequisite(int num, vector<vector<int>>& prereq, vector<vector<int>>& queries) {
        unordered_map<int,list<int>>adj;

        for(auto it: prereq)
        {
            int u = it[0];
            int v = it[1];

            adj[u].push_back(v); //adjlist
        }

        //topo sort to check if student able to take num courses
          queue<int>q;

        vector<int>indegree(num,0);

        for(int i =0; i<num; i++)
        {
            for(auto it: adj[i])
            {
                indegree[it]++;
            }
        }

        //push the nodes with min indegree to queue
        //bcz topo sort says the nodes with less indegree will be first in linear ordering

        for(int i =0; i<num; i++)
        {
            if(indegree[i]==0)
            {
                q.push(i);
            }
        }

                    //node->{prereq}
        unordered_map<int,unordered_set<int>>mp;
        while(!q.empty())
        {
            int node = q.front();
            q.pop();

            for(auto nbr : adj[node])
            {
                mp[nbr].insert(node); //bcz we came to nbr from node i.e node->nbr

                //find preq of node as well bcz by transitivity they are prereq of nbr also

                for(auto &preq : mp[node])
                {
                    mp[nbr].insert(preq);
                }
                indegree[nbr]--;

                if(indegree[nbr]==0)
                {
                    q.push(nbr);
                }
            }
        }
        

        int n = queries.size();

        vector<bool>ans(n);

        for(int i =0; i<n; i++)
        {
            int src = queries[i][0];
            int dest = queries[i][1];

            bool reachable = mp[dest].contains(src); //does it contains the preq

            ans[i] = reachable;
        }

        return ans;


    }
};