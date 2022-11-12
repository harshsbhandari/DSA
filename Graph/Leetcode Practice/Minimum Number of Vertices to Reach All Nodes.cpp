https://leetcode.com/problems/minimum-number-of-vertices-to-reach-all-nodes/description/

/*
  Nodes with indegree is equal to 'zero', are our answer. Because there is no way to reach them.
*/

vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        vector<int>adj(n, 0);
        vector<int>ans;

        for(auto i : edges){
            int u = i[0];
            int v = i[1];

            adj[v]++;
        }

        for(int i = 0; i < n; i++){
            if(adj[i] == 0)
                ans.push_back(i);
        }
        
        return ans;
    }
