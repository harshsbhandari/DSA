https://leetcode.com/problems/find-if-path-exists-in-graph/description/

/*
  Check whether 'source' and the 'destination' belong to the same connected component. If yes, than 'destination' is reachable from 'source', else not.
*/

void bfs(vector<int>edges[], int source, vector<int>& vis){
        vis[source] = 1;
        queue<int>q;
        
        q.push(source);

        while(!q.empty()){
            int node = q.front();
            q.pop();

            for(auto it : edges[node]){
                if(!vis[it]){
                    vis[it] = 1;
                    q.push(it);
                }
            }
        }

        return ;
    }
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<int>vis(n+1, 0);
        vector<int>arr[n+1];

        for(auto i : edges){
            arr[i[0]].push_back(i[1]);
            arr[i[1]].push_back(i[0]);
        }
        

        bfs(arr, source, vis);

        if(vis[destination] == 0)
            return false;
        
        return  true;
    }
