https://leetcode.com/problems/minimum-score-of-a-path-between-two-cities/description/

// Just do simple BFS, and instead of adding the edge weights, keep updating the minimum edge weight and that's our answer.

int bfs(vector<pair<int,int>>adj[], int start, int n){
        vector<int>vis(n, 0);
        int ans = INT_MAX;
        queue<int>pq;

        vis[start] = 1;
        pq.push(start);

        while(!pq.empty()){
            auto it = pq.front();
            int node = it;

            pq.pop();

            for(auto i : adj[node]){
                int adjNode = i.first;
                int adjWeight = i.second;

                if(!vis[adjNode]){
                    vis[adjNode] = 1;
                    pq.push(adjNode);
                    ans =  min(ans, adjWeight);
                }
                else
                    ans = min(ans, adjWeight);
            }
        }

        return ans;
    }

    int minScore(int n, vector<vector<int>>& roads) {
        vector<pair<int,int>>adj[n];

        for(auto i : roads){
            int u = i[0], v = i[1], wt = i[2];
            u--; v--;

            adj[u].push_back({v, wt});
            adj[v].push_back({u, wt});
        }

        int ans = bfs(adj, 0, n);

        return ans;
    }
