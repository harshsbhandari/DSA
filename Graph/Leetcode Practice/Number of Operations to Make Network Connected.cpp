https://leetcode.com/problems/number-of-operations-to-make-network-connected/description/

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
    int makeConnected(int n, vector<vector<int>>& connections) {
        DisjointSet ds(n);

        int extra = 0, count = 0;
        
        // Only 'extra' edges can be removed and placed somewhere else
        for(auto i : connections){
            int x = i[0], y = i[1];

            if(ds.findParent(x) == ds.findParent(y))
                extra++;
            else
                ds.unionBySize(x, y);
        }
        
        // Finding number of connected components
        for(int i = 0; i < n; i++){
            if(ds.findParent(i) == i)
                count++;
        }
        
        // Except one node in a component we can remove all the nodes
        int ans = count-1;

        if(extra >= ans)
            return ans;
        
        return -1;
    }
