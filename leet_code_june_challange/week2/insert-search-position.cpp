class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int lo =0;
        int hi = nums.size()-1;
        int mid;
        while(lo<=hi)
        {
            
             mid = (lo + hi)/2;
            // cout<<mid<<" ";
            if(nums[mid] == target)
            {
                return mid;
            }
            if(nums[mid] < target)
            {
                lo = mid + 1;
            }
            else
            {
                hi = mid - 1;
            }
        }
        // 
        return lo;
    }
};