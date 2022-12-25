// https://leetcode.com/problems/loud-and-rich/description/

int bfs(vector<int>adj[], int i, vector<int>& quiet, int n){
    queue<int>q;
    vector<int>vis(n, 0);
    int ansNode = i;
    int ansQuiet = quiet[i];

    q.push(i);
    vis[i] = 1;
    
    while(!q.empty()){
        int node = q.front();
        q.pop();
        
        for(auto it : adj[node]){
            int adjNode = it;
            int qVal = quiet[adjNode];

            if(!vis[adjNode]){
                q.push(adjNode);

                if(ansQuiet >= qVal){
                    ansNode = adjNode;
                    ansQuiet = qVal;
                }
                vis[adjNode] = 1;
            }
        }
    }

    return ansNode;
}
    vector<int> loudAndRich(vector<vector<int>>& richer, vector<int>& quiet) {
        int n = quiet.size();
        vector<int>adj[n];
        vector<int>v;

        for(auto i : richer)
            adj[i[1]].push_back(i[0]);
        
        for(int i = 0; i < n; i++){
            int node = i;
            int ans = bfs(adj, node, quiet, n);
            
            v.push_back(ans);
        }
        
        return v;
    }
