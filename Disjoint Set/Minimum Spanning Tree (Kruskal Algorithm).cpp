https://practice.geeksforgeeks.org/problems/minimum-spanning-tree/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=minimum-spanning-tree

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
	
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int n, vector<vector<int>> adj[]){
        // code here
        
        DisjointSet ds(n);
        int sum = 0;
        
        vector<pair<int, pair<int,int>>>arr;
        
        for(int i = 0; i < n; i++){
            for(auto it : adj[i]){
                int wt = it[1];
                int u = i;
                int v = it[0];
                arr.push_back({wt, {u, v}});
            }
        }
        sort(arr.begin(), arr.end());
        
        for(auto i : arr){
            int wt = i.first;
            int u = i.second.first;
            int v = i.second.second;
            
            if(ds.findParent(u) != ds.findParent(v)){
                sum += wt;
                ds.unionBySize(u, v);
            }
        }
        
        return sum;
    }
