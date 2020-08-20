class Solution {
public:

    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
        multimap<long long int, vector<int>  > mapper;
        vector<vector<int>> ans;
        
        for(auto c: points)
        {
            vector<int> tmp = {c[0], c[1]};
            mapper.insert(make_pair(pow((c[0]), 2) +  pow((c[1]), 2) ,tmp));
        }
        
        for(auto c: mapper)
        {
            if(K--)
            {
                ans.push_back(c.second);
            }
            else
            {
                break;
            }
        }
        
        return ans;
    }
};