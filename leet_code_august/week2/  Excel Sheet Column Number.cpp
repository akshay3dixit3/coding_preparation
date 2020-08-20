class Solution {
public:
    int titleToNumber(string s) {
        long long int ans = 0;
        
        for(int i=0; i<s.size(); i++)
        {
            int tmp = s[i] - 'A';
            ans = ans + (tmp+1)*pow(26, s.size() - (i+1));
            cout<<tmp+1<<" "<< s.size() - (i+1)<<" ";
            cout<<ans<<endl;
        }
        return ans;
        
    }
};