https://www.interviewbit.com/problems/0-1-knapsack/

Memoised - 

const int D = 1005;
int t[D][D]; // DP matrix

int Knapsack(vector<int>wt, vector<int>val, int W, int n) {
    // base case
    if (n == 0 || W == 0)
        return 0;

    // if already calculated
    if (t[n][W] != -1)
        return t[n][W];
        
    // else calculate
    else {
        if (wt[n - 1] <= W)
            t[n][W] = max(val[n - 1] + Knapsack(wt, val, W - wt[n - 1], n - 1), Knapsack(wt, val, W, n - 1));
            
        else if (wt[n - 1] > W)
            t[n][W] = Knapsack(wt, val, W, n - 1);

        return t[n][W];
    }
}

int Solution::solve(vector<int> &val, vector<int> &wt, int w) {
    int n = wt.size();
    
    for(int i = 0; i <= n; i++){
        for(int j = 0; j <= w; j++)
            t[i][j] = -1;
    }
    
    int ans = Knapsack(wt, val, w, n);
    return ans;
}

Top - Down - 
  
 int Solution::solve(vector<int> &val, vector<int> &wt, int w) {
    int n = val.size();
    int t[n+1][w+1];

    for(int i = 0; i < n+1; i++){
        for(int j = 0; j < w+1; j++){
            if(i == 0 || j == 0)
                t[i][j] = 0;
        }
    }

    for(int i = 1; i < n+1; i++){
        for(int j = 1; j < w+1; j++){
            if(wt[i-1] <= j)
                t[i][j] = max(val[i-1]+t[i-1][j-wt[i-1]], t[i-1][j]);

            else
                t[i][j] = t[i-1][j];
        }
    }

    return t[n][w];
}
