https://leetcode.com/problems/find-the-town-judge/description/

int findJudge(int n, vector<vector<int>>& trust) {
        vector<int>in(n+1), out(n+1);

        for(auto i : trust){
            int x = i[0], y = i[1];
            in[y]++;
            out[x]++;
        }

        for(int i = 1; i < n+1; i++){
            if(in[i] == n-1 && out[i] == 0)
                return i;
        }

        return -1;
    }
