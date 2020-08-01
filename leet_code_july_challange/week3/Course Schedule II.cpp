class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> G[numCourses], in(numCourses, 0), sol;
        int i, c;
        queue<int> q;
        
        for(auto p: prerequisites)
        {
            G[p[1]].push_back(p[0]);
            in[p[0]]++;
        }
        
        for(i=0;i<in.size();i++) 
            if(in[i]==0) 
                q.push(i);
        
        while(!q.empty())
        {
            c = q.front();
            q.pop();
            sol.push_back(c);
            for(auto u : G[c])
            {
                if(--in[u]==0)
                    q.push(u);
            }
        }
        
        for(i=0;i<in.size();i++) if(in[i]!=0){
            sol.clear();
            break;
        }
        
        return sol;
    }
};