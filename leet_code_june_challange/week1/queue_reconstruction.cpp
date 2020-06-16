
class Solution {
public:
   
    static bool comp (vector<int> &a, vector<int> &b)
    {
    // print()
    if(a[0] == b[0]) 
        return a[1] < b[1];
    return a[0] > b[0];
       
    }
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        
    sort(people.begin(), people.end(), comp);
    vector<vector<int>> ans;
    // ans.push_back(people[0]);
    
    for(int i=0; i<people.size(); i++)
    {
        ans.insert(ans.begin() + people[i][1], people[i]);
    }
        return ans;
    }
};