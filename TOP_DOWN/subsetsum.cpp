#include <bits/stdc++.h>
using namespace std;
vector<vector<int> > dp;

int subset_sum(vector<int> subset, int sum, int index, vector<vector<int> > &dp)
{
    if(index >= subset.size() || sum < 0)
    {
        return 0;
    }
    
    if(sum - subset[index] == 0)
    {
        // cout<<index<<" ";
        return 1;
    }
        
    
    if(dp[index][sum] != -1)
        return dp[index][sum];
    
    int tmp = subset_sum(subset, sum, index+1, dp) || 
               subset_sum(subset, sum - subset[index], index+1, dp);
             
    dp[index][sum] = tmp;
    
    return tmp;
}

int main()
{
    vector<int> subset = {1, 1,4,8};
    int sum = -1;
    vector<vector<int> > dp(subset.size(), vector<int> (sum+1, -1));
    int ans =  subset_sum(subset, sum, 0, dp);
    cout<<ans;
    return 0;
}
