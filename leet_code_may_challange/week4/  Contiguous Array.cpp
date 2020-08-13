class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int index  = 0;
        int sum = 0;
        int ans = 0;
        map<int, int> mapper;
        mapper[0] = -1;
        if(nums.size() == 1)
            return 0;
        
        for(int i=0; i<nums.size(); i++)
        {
            if(nums[i] == 0)
            {
                sum--;
            }
            else
            {
                sum++;
            }
            if(mapper.find(sum) != mapper.end())
            {
                ans=max(ans,i-mapper[sum]);
            }
            else
            {
                mapper[sum] = i;
            }
        }
        
        return ans;        
    }
};