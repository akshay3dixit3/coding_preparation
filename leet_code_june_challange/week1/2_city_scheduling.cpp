//sorting is first thing that comes in mind. But here we need not to sort vector according to values but sort according to the differences in between them. Them we can have correct evaluaton.
class Solution {
public:
    int twoCitySchedCost(vector<vector<int>>& costs) {
        int n = costs.size();
        
        auto comp = [](const vector<int>&a,const vector<int>&b)
        {
            return (a[0]-a[1]) < (b[0]-b[1]);
        };
        sort(costs.begin(), costs.end(), comp);
        int sum = 0;
        for(int i=0; i<n/2; i++)
        {
            sum = sum + costs[i][0];
        }
        
        for(int i= n/2; i<n; i++)
        {
            sum = sum + costs[i][1];
        }
        
        return sum;
        
    }
};