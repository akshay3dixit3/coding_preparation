class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> ans = {1};
        
        if(rowIndex == 0)
        {
            return ans;
        }
        
        ans = {1, 1};
        
        if(rowIndex == 1)
        {
            return ans;        
        }
        rowIndex = rowIndex-1;
        while(rowIndex--)
        {
            vector<int> tmp;
            tmp.push_back(1);
            for(int i=1; i<ans.size(); i++)    
            {
               tmp.push_back(ans[i] + ans[i-1]); 
            }
            tmp.push_back(1);
            
            ans = tmp;
        }
        return ans;
        
        
        
    }
};