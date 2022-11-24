https://leetcode.com/problems/maximum-total-importance-of-roads/description/

/*
  Node with highest degree is assigned largest weight, and so on.
*/

long long maximumImportance(int n, vector<vector<int>>& roads) {
        vector<int>adj[n];

        for(auto it : roads){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }

        vector<pair<int, int>>v;

        for(int i = 0; i < n; i++){
            int size = adj[i].size();
            v.push_back({size, i});
        }

        sort(v.begin(), v.end());
        reverse(v.begin(), v.end());

        int temp = n;
        map<int,int>mp;

        for(auto i : v){
            mp[i.second] = temp;
            temp--;
        }

        long long int count = 0;
        
        for(auto i : roads){
            int x = i[0], y = i[1];

            count += (mp[x]+mp[y]);
        }

        return count;
    }
