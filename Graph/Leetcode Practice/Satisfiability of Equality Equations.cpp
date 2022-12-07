https://leetcode.com/problems/satisfiability-of-equality-equations/description/

// There will be 26 node in the Disjoint Set data structure.

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
    bool equationsPossible(vector<string>& equations) {
        // 26 nodes in Disjoint Set
        DisjointSet ds(26);

        for(auto i : equations){
            int u = i[0]-'a';
            int v = i[3]-'a';

            if(i[1] == '=')
                ds.unionBySize(u, v);
        }

        for(auto i : equations){
            if(i[1] == '!'){
                int u = i[0]-'a';
                int v = i[3]-'a';

                if(ds.findParent(v) == ds.findParent(u))
                    return false;
            }
        }

        return true;
    }
