class CombinationIterator {
public:
   vector<string> temp;
    int i;
    CombinationIterator(string characters, int combinationlength):i(0) {        
        backtrack(characters,combinationlength,0,"");
    }
    
    void backtrack(const string& characters,int combinationlength,int idx,string ans){        
        for(int i=idx;i<characters.size() && ans.size()<combinationlength;i++)            
            backtrack(characters,combinationlength,i+1,ans + characters[i]);            
        if(ans.size()==combinationlength) temp.push_back(ans);
    }
    
    string next() 
    {
        return temp[i++];    
    }    
    bool hasNext()
    {
        return i<temp.size() ;
    }    
};

/**
 * Your CombinationIterator object will be instantiated and called as such:
 * CombinationIterator* obj = new CombinationIterator(characters, combinationLength);
 * string param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */