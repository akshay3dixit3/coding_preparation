class Solution {
public:
    int climbStairs(int n) {
        if (n == 0 || n == 1 || n==2)
            return n;
            
        int last_1 = 2;
        int last_2 = 1;
        int res;
        for(int i = 3; i<=n; i++)
        {
            res = last_2 + last_1;
            last_2 = last_1;
            last_1 = res;
        }
        return res;
        
    }
};