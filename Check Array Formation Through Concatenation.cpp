class Solution {
public:
    bool canFormArray(vector<int>& arr, vector<vector<int>>& pieces) {
        
        for(auto c: pieces)
        {
            int start  = -1;
            for(auto num : c)
            {
                auto itr = find(arr.begin(), arr.end(), num);
                
                if(itr == arr.end())
                {
                    return false;
                }
                
                int index = itr - arr.begin();
                
                if(start == -1)
                {
                    start = index;
                    continue;
                }
                
                // cout<<num<<" "<<index<<" "<<start<<endl;
    
                if(start != -1 && index != start+1)
                    return false;
                
                start = start+1;
                
            }
        }
        return true;
        
    }
};