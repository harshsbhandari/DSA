https://practice.geeksforgeeks.org/problems/number-of-provinces/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=number-of-provinces

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
  
    int numProvinces(vector<vector<int>> adj, int n) {
        // code here
        DisjointSet ds(n);
        int count = 0;
        
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(adj[i][j] == 1)
                    ds.unionByRank(i, j);
            }
        }
        
        for(int i = 0; i < n; i++){
            if(ds.findParent(i) == i)
                count++;
        }
        
        return count;
    }
