https://practice.geeksforgeeks.org/problems/number-of-islands/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=number-of-islands

class DisjointSet{
    vector<int>rank, parent, size;
    
    public :
        DisjointSet(int n){
            rank.resize(n+1, 0);
            parent.resize(n+1);
            size.resize(n+1);
            
            for(int i = 0; i <= n; i++){
                parent[i] = i;
                size[i] = 1;
            }
        }
        
        int findParent(int node){
            if(node == parent[node])
                return node;
            else
                return parent[node] = findParent(parent[node]);
        }
        
        void unionByRank(int u, int v){
            int ultiU = findParent(u);
            int ultiV = findParent(v);
            
            // Same component
            if(ultiU == ultiV)
                return ;
            
            if(rank[ultiU] < rank[ultiV])
                parent[ultiU] = ultiV;
            
            else if(rank[ultiV] < rank[ultiU])
                parent[ultiV] = ultiU;
            
            else{
                parent[ultiV] = ultiU;
                rank[ultiU]++;
            }
            
        }
        
        void unionBySize(int u, int v){
            int ultiU = findParent(u);
            int ultiV = findParent(v);
            
            // Same component
            if(ultiU == ultiV)
                return ;
            
            if(size[ultiU] < size[ultiV]){
                parent[ultiU] = ultiV;
                size[ultiV] += size[ultiU];
            }
            
            else{
                parent[ultiV] = ultiU;
                size[ultiU] += size[ultiV];
            }
            
        }
};
    vector<int> numOfIslands(int n, int m, vector<vector<int>> &ops) {
        // code here
        
        vector<vector<int>>vis(n, vector<int>(m, 0));
        DisjointSet ds(n*m);
        int count = 0;
        vector<int>ans;
        int delr[] = {0, 1, 0, -1};
        int delc[] = {1, 0, -1, 0};
        
        for(auto it : ops){
            int row = it[0];
            int col = it[1];
            
            if(vis[row][col] == 1){
                ans.push_back(count);
                continue;
            }
            
            vis[row][col] = 1;
            count++;
            
            for(int k = 0; k < 4; k++){
                int newr = row+delr[k];
                int newc = col+delc[k];
                
                if(newr >= 0 && newr < n && newc >= 0 && newc < m){
                    if(vis[newr][newc] == 1){
                        int nodeNo = row*m + col;
                        int adjNodeNo = newr*m + newc;
                        
                        if(ds.findParent(nodeNo) != ds.findParent(adjNodeNo)){
                            count--;
                            ds.unionBySize(nodeNo, adjNodeNo);
                        }
                    }
                }
            }
            ans.push_back(count);
        }
        return ans;
    }
