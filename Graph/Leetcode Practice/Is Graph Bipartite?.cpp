https://leetcode.com/problems/is-graph-bipartite/description/

/*
  To check whether a graph is bipartite - Check whether the nodes can be colored '0' and '1' alternately. 
  If it is possible than a graph is bipartite, else not.
*/

DFS - 

bool dfs(vector<vector<int>>& graph, vector<int>&color, int node, int colors){
        color[node] = colors;

        for(auto i : graph[node]){
            if(color[i] == -1){
                if(!dfs(graph, color, i, !colors))
                    return false;
            }
            else{
                if(color[node] == color[i])
                    return false;
            }
        }

        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int>color(n, -1);

        for(int i = 0; i < n; i++){
            if(color[i] == -1){
                if(!dfs(graph, color, i, 0))
                    return false;
            }
        }

        return true;
    }

BFS - 

bool bfs(vector<vector<int>>& graph, vector<int>&color, int node, int colors){
        queue<int>q;
        q.push(node);
        color[node] = colors;

        while(!q.empty()){
            int x = q.front();
            q.pop();

            for(auto i : graph[x]){
                if(color[i] == -1){
                    color[i] = !color[x];
                    q.push(i);
                }
                else{
                    if(color[i] == color[x])
                        return false;
                }
            }
        }
        
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int>color(n, -1);

        for(int i = 0; i < n; i++){
            if(color[i] == -1){
                if(!bfs(graph, color, i, 0))
                    return false;
            }
        }

        return true;
    }

  
