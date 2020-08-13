class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> input(26, 0);
        vector<int> cur(26, 0);
        vector<int> ans;
        
        for(auto c: p)
            input[c - 'a']++;
        
        for(int i = 0; i<s.size(); i++)
        {
            cur[s[i] - 'a']++;
            if(i>= p.size())
            {
                cur[s[i- p.size()] - 'a']--;
            }
            if(input == cur)
                ans.push_back(i - p.size() + 1);
        }
        
        return ans;
    }
};