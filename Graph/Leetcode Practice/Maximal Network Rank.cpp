https://leetcode.com/problems/maximal-network-rank/description/

int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        vector<int>adj[n];

        for(auto i : roads){
            adj[i[0]].push_back(i[1]);
            adj[i[1]].push_back(i[0]);
        }

        int ans = 0;

        for(int i = 0; i < n-1; i++){

            for(int j = i+1; j < n; j++){
                int temp = adj[i].size()+adj[j].size();
              
                // Reducing 'temp' only when the edge 'i' to 'j' and 'j' to 'i', both are counted
                for(auto k : adj[j]){
                    if(k == i)
                        temp--;
                }

                ans = max(ans, temp);
            }
        }

        return ans;
    }
