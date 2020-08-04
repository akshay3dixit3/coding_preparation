class Solution {
public:
    int findJudge(int N, vector<vector<int>>& trust) {
        unordered_map<int, set<int> > trust_issues;
        set<int> trusters;
        for(auto c :trust)
        {
            trust_issues[c[1]].insert(c[0]);    
            trusters.insert(c[0]);
        }
        int missing = INT_MAX;
        int non_trusting_nums = 0;
        for(int i = 1; i<=N; i++)
        {
            if(trusters.find(i) == trusters.end())
            { 
                non_trusting_nums++;
                missing = i;   
            }
        }
        if( non_trusting_nums > 1 || missing == INT_MAX)
        {
            return -1;
        }
        if(trust_issues[missing].size() == N-1)
            return missing;
        
        return -1;
        
    }
};