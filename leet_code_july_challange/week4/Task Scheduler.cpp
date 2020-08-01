class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char,int>mp;
        int fre = 0, ans = 0;
        //finding most frequent task;    
        for(auto e : tasks) fre = max(fre, ++mp[e]);

        //to keep count of how many task are there with freq as highest and equal.
        for(auto e : mp) if(e.second == fre) ans++;
        
        return max((int)tasks.size(), ans + (fre-1)*(n+1));
    }
};