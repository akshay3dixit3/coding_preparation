class Solution {
public:
    void dfs(vector<vector<int>>& edge, int node, vector<vector<int>>&res, vector<int>& pool) {
        pool.push_back(node);
        if(node==edge.size()-1) {
            res.push_back(pool);
        } else {
            for(auto c: edge[node]) {
                   dfs(edge, c, res, pool);
            }
        }        
        pool.pop_back();
        return;
    }
    
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>> res;
        vector<int> pool;
        dfs(graph, 0, res, pool);
        return res;
    }
};