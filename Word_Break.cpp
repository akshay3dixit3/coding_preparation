 bool dfs(string s, set<string> set_dict, unordered_map<string, bool> &mapper)
    {
        
        if(s == "")
            return true;
        
        if(mapper.find(s) != mapper.end())
        {
           return mapper[s]; 
        }
        
        for(int i =1; i <= s.size(); i++)
        {
            if ( (set_dict.find(s.substr(0, i)) != set_dict.end() ) && dfs(s.substr(i, s.length() - i), set_dict, mapper))
            {
                mapper[s.substr(i, s.length() - i)] = true;
                return true;
            }
        }
        mapper[s] = false;
        return false;
        
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        
        set<string> set_dict; 
        unordered_map<string, bool> mapper;
        
        for(auto s: wordDict)
        {
            set_dict.insert(s);
        }
        
        return dfs(s, set_dict, mapper);       
    }