https://leetcode.com/problems/all-paths-from-source-to-target/description/

/*
   Rule of thumb is always use BFS for shortest path (DFS cannot give shortest path), 
   and use DFS when you have to visit all vertices or backtrack at some point.
*/

void dfs(vector<vector<int>>& graph, int node, vector<int>v, int desti, vector<vector<int>>& ans){
        v.push_back(node);
        
        // base case
        if(node == desti){
            ans.push_back(v);
            return ;
        }

        for(auto i : graph[node])
            dfs(graph, i, v, desti, ans);

    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>>ans;
        int n = graph.size();
        vector<int>v;
        int desti = n-1;

        dfs(graph, 0, v, desti, ans);

        return ans;
    }
