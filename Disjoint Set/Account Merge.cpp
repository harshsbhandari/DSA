https://practice.geeksforgeeks.org/problems/account-merge/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=account-merge

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
    vector<vector<string>> accountsMerge(vector<vector<string>> &accounts) {
        // code here
        vector<vector<string>>ans;
        int n = accounts.size();
        map<string, int>mapMailNode;
        DisjointSet ds(n);
        
        for(int i = 0; i < n; i++){
            for(int j = 1; j < accounts[i].size(); j++){
                string mail = accounts[i][j];
                
                if(mapMailNode.find(mail) == mapMailNode.end())
                    mapMailNode[mail] = i;
                else
                    ds.unionBySize(i, mapMailNode[mail]);
            }
        }
        
        vector<string>v[n];
        
        for(auto it : mapMailNode){
            string mail = it.first;
            int node = ds.findParent(it.second);
            
            v[node].push_back(mail);
        }
        
        for(int i = 0; i < n; i++){
            if(v[i].size() == 0)
                continue;
                
            sort(v[i].begin(), v[i].end());
            
            vector<string>temp;
            
            temp.push_back(accounts[i][0]);
            
            for(auto j : v[i])
                temp.push_back(j);
            
            ans.push_back(temp);
        }
        
        return ans;
    }
