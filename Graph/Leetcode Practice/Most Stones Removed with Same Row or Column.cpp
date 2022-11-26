https://leetcode.com/problems/most-stones-removed-with-same-row-or-column/description/

/*
  Stones whose row or column number is equal are considered to be in the same component, and from each component we remove all the nodes except one node.
*/

void dfs(int node, vector<int>&vis, vector<vector<int>>& stones, int n){
        vis[node] = 1;

        for(int i = 0; i < n; i++){
          
            // Checking which all nodes belong to current node's component, and making them a single component 
            if(!vis[i] && ((stones[i][0] == stones[node][0]) || (stones[i][1] == stones[node][1])) )
                dfs(i, vis, stones, n);
        }
    }
    int removeStones(vector<vector<int>>& stones) {
        int n = stones.size();

        int count = 0;
        vector<int>vis(n, 0);

        for(int i = 0; i < n; i++){
            if(!vis[i]){
                count++;
                dfs(i, vis, stones, n);
            }
        }

        return n-count;
    }
