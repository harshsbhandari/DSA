https://leetcode.com/problems/reorder-routes-to-make-all-paths-lead-to-the-city-zero/description/

/*
  Here we need to count the number of edges need to be reversed.
*/

int minReorder(int n, vector<vector<int>>& edges) {
        vector<int>adj[n], other[n];
        vector<int>vis(n, 0);

        for(auto i : edges){
            int x = i[0];
            int y = i[1];

            adj[x].push_back(y);
            other[y].push_back(x);
        }

        int ans = 0;
        queue<int>q;

        q.push(0);
        vis[0] = 1;

        while(!q.empty()){
            int node = q.front();
            q.pop();

            for(auto i : adj[node]){
                if(!vis[i]){
                    vis[i] = 1;
                    q.push(i);

                    // directions of these nodes need to be changed
                    ans++;
                }
            }
            /*
              This is to check whether all the nodes that point towards the destination(here - '0') are visited, no more nodes are left.
            */
            for(auto i : other[node]){
                if(!vis[i]){
                    vis[i] = 1;
                    q.push(i); 
                }
            }
        }

        return ans;
    }
