https://leetcode.com/problems/keys-and-rooms/description/

/*
  If the graph is in a single component - return 'true', else 'false'.
*/

void check(vector<vector<int>>& rooms, vector<int>& vis, int node){
        vis[node] = 1;

        for(auto i : rooms[node]){
            if(!vis[i])
                check(rooms, vis, i);
        }
    }
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();
        vector<int>vis(n, 0);
        
        check(rooms, vis, 0);

        for(auto i : vis){
            if(i == 0)
                return false;
        }

        return true;
    }
