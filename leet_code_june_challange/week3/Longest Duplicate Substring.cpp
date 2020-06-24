class Solution {
public:
    string longestDupSubstring(string S) {
        string_view ans;
        unordered_set<string_view> set;
        int beg = 0;
        int end = S.size() - 1;
        
        while(beg <= end)
        {
            auto len = beg + (end - beg) / 2;
            bool found = false;
            for(int i =0; i != S.size() - len + 1; i++)
            {
                auto [it, inserted] = set.emplace(S.data() + i, len);
                if (!inserted)
                {
                    found = true;
                    ans = *it;
                    break;   
                }
            }
            
            if (found)
                beg = len + 1;
            else
                end = len - 1;
            
            set.clear();   
        }
        return {ans.begin(), ans.end()};
    }
};