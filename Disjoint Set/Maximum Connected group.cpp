https://practice.geeksforgeeks.org/problems/maximum-connected-group/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=maximum-connected-group

class DisjointSet{
    public :
        vector<int>rank, parent, size;
    
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
  
    int MaxConnection(vector<vector<int>>& grid) {
        // code here
        
        int n = grid.size();
        DisjointSet ds(n*n);
        int delr[] = {0 , 1, 0 ,-1};
        int delc[] = {1 , 0, -1 ,0};
        
        // step 1 -> connecting components
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == 0)
                    continue;
                
                for(int k = 0; k < 4; k++){
                    int newr = delr[k]+i;
                    int newc = delc[k]+j;
                    
                    if(newr >= 0 && newr < n && newc >= 0 && newc < n && grid[newr][newc] == 1){
                        int nodeNo = i*n+j;
                        int adjNodeNo = newr*n+newc;
                        ds.unionBySize(nodeNo, adjNodeNo);
                    }
                }
            }
        }
        
        int count = 0;
        
        // step 2
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == 1)
                    continue;
                
                set<int>st;
                
                for(int k = 0; k < 4; k++){
                    int newr = delr[k]+i;
                    int newc = delc[k]+j;
                    
                    if(newr >= 0 && newr < n && newc >= 0 && newc < n){
                        if(grid[newr][newc] == 1){
                            int adjNodeNo = newr*n+newc;
                            st.insert(ds.findParent(adjNodeNo));
                        }
                    }
                }
                
                int temp = 0;
                
                for(auto it : st)
                    temp += ds.size[it];
                
                count = max(count, temp+1);
            }
        }
        
        for(int i = 0; i < n*n; i++)
            count = max(count, ds.size[ds.findParent(i)]);
        
        return count;
    }
