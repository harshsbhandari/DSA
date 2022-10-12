https://practice.geeksforgeeks.org/problems/minimum-multiplications-to-reach-end/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=minimum-multiplications-to-reach-end

int minimumMultiplications(vector<int>& arr, int src, int end) {
        // code here
        queue<pair<int,int>>q;
        vector<int>dist(100000, INT_MAX);
        int mod = 1e5;
        
        dist[src] = 0;
        q.push({src, 0});
        
        while(!q.empty()){
            auto it = q.front();
            int node = it.first;
            int steps = it.second;
            q.pop();
            
            for(auto i : arr){
                int newnode = (node*i) % mod;
                int newsteps = steps+1;
                
                if(newsteps < dist[newnode]){
                    dist[newnode] = newsteps;
                    
                    if(end == newnode)
                        return newsteps;
                        
                    q.push({newnode, newsteps});
                }
            }
        }
        
        return -1;
    }
