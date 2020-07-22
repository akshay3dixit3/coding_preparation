class Solution {
public:
    string reverseWords(string s) {
        stringstream ss(s);
        string res, str;
        
        while(ss >> str)
        {
            // cout<<str<<endl;
            res = res.empty() ? str : str+' '+res;
            // cout<<res<<endl;
            
        }
        return res;
        
    }
};