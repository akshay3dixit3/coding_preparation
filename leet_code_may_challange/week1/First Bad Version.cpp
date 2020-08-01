// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int start = 1;
        int end = n;
        
        while(start < end)
        {
            int mid = (start+((end - start)/2));
            bool state = isBadVersion(mid);
            
            if(!state)
            {
                start = mid + 1;
            }
            else
            {
                end = mid;
            }
        }
        return start;
        
    }
};