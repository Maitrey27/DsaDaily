class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        unordered_map<int,list<pair<int,int>>>adj;

        for(auto it: times)
        {
            int u =it[0];
            int v =it[1];
            int wt= it[2];

            adj[u].push_back({v,wt});
        }

        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;

        pq.push({0,k});
        vector<int>dist(n+1,1e9);
        dist[k]=0;

        while(!pq.empty())
        {
            int time = pq.top().first;
            int node = pq.top().second;

            pq.pop();

            for(auto it: adj[node])
            {
                int adjNode = it.first;
                int adjTime = it.second;

                if(dist[node]+ adjTime < dist[adjNode])
                {
                    dist[adjNode]= dist[node]+ adjTime;
                    pq.push({dist[adjNode],adjNode});
                }
            }
        }

        int minTime = INT_MIN;

        for(int i =1; i<=n; i++)
        {
            if(dist[i]==1e9)
            {
                return -1;
            }else{
            //The time taken for all nodes to receive the signal is determined by the node that takes the longest time to receive it.
                minTime = max(minTime,dist[i]);
            }
        }

        return minTime;
    }
};