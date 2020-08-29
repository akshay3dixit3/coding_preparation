
class Solution {
public:
       static bool sorted(vector<int> &a, vector<int> &b)
    {
        return a[1] < b[1];
    }
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        if(intervals.size() == 0 || intervals.size() == 1)
        {
            return 0;
        }
        int answer = -1;
        sort(intervals.begin(), intervals.end(), sorted);
        vector<int> prev = intervals[0];
        for(auto c: intervals)
        {
            if(prev[1] > c[0])
            {
                answer++;
            }
            else
                prev = c;
        }
        
        return answer;
    }
};