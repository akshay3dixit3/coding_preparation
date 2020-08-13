class Solution {
public:
    vector<int> findDuplicates(vector<int>& a) {
        int count =0;
        vector<int> ans;
        for(int i =0; i<a.size(); i++)
        {
            if(a[abs(a[i]) - 1] < 0)
            {
                ans.push_back(abs(a[i]));
            }
            else
            {
                a[abs(a[i])-1] = -(a[abs(a[i])-1]);
            }
        }
        return ans;
    }
};