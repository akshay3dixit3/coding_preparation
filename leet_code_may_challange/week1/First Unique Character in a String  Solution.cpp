class Solution {
public:
    int firstUniqChar(string s) {
        
       int min_index = INT_MAX;
        unordered_map<char, pair<int, int> > mapper;
        for(int i =0; i<s.size(); i++)
        {
            if(mapper.find(s[i]) == mapper.end())
            {
                auto tmp_pair = make_pair(1, i);
                mapper[s[i]] = tmp_pair;
            }
            
            else
            {
                mapper[s[i]].first++;

            }
        }
        for(auto c: mapper)
        {
            cout<<c.second.first<<"  "<<c.second.second<<endl;
            if(c.second.first == 1)
            {
                if(c.second.second < min_index)
                {
                    min_index = c.second.second;
                }
            }
        }
        return min_index == INT_MAX ? -1 : min_index;
        
    }
};