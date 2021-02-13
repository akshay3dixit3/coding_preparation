class Solution {
    // int lowest_price = -1;
public:
   // int lowest_price = INT_MAX;
    vector<vector<pair<int, int>>> adj;
    int sum = INT_MAX;
    int dest;
    
    void dfs(int src, int k, int weight = 0) {
         if(k < -1 || weight > sum) return;
         if(k >= -1 && src == dest) {
            sum = min(sum, weight);
            return;
        }
        for(auto it : adj[src]) 
            dfs(it.first, k - 1, weight + it.second);
    }
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int K) {
        
        // vector<bool> visited(n , false);
        adj = vector<vector<pair<int,int> > >(n);
        dest = dst;
        
        for(auto i : flights) 
            adj[i[0]].push_back({i[1], i[2]});
        
        dfs(src, K);
        
        
        return sum==INT_MAX?-1:sum;
    }
};