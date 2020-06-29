class Solution {
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        
        map<string, multiset<string>> adj;
        vector<string> ans;
        stack<string> st;
        
        for (int i=0; i<tickets.size(); i++)
        {
            adj[tickets[i][0]].insert(tickets[i][1]);
        }
        
        st.push("JFK");
        
        while(!st.empty())
        {
            string src = st.top();
            
            if(adj[src].size() == 0)
            {
                ans.push_back(src);
                st.pop();
            }
            
            else
            {
                auto dest = adj[src].begin();
                st.push(*dest);
                adj[src].erase(dest);
            }
        }
        reverse(ans.begin(), ans.end());
        return ans;
        
    }
};