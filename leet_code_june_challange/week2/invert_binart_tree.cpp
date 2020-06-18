class Solution {
public:
    bool isPowerOfTwo(int n) {
        // if (n<=0) return false;
        // if ((n & (n-1)) == 0) return true;
        // return false;
        
        if(n == 0) return false;
        return (floor(log2(n)) == ceil(log2(n)) ) ;
    }
};