https://leetcode.com/problems/flower-planting-with-no-adjacent/description/

// For each node, firstly check which color has been used to color the adjacent node of the current node.
// Than color the current node with the color that has not been used by any adjcant node

vector<int> gardenNoAdj(int n, vector<vector<int>>& paths) {
        vector<int>adj[n+1];

        for(auto i : paths){
            int u = i[0], v = i[1];
            u--; v--;
        
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<int>color(n, 0);
        
        for(int i = 0; i < n; i++){
            vector<bool>usedColor(5);

            for(auto j : adj[i])
                usedColor[color[j]] = true;
            
            for(int k = 1; k <= 4; k++){
                if(!usedColor[k])
                    color[i] = k;
            }
        }

        return color;
    }
