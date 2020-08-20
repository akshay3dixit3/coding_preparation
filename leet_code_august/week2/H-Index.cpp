class Solution {
public:
    int hIndex(vector<int>& citations) {
        int i,j,n=citations.size();
        sort(citations.begin(),citations.end());
        
        if(n==0)
            return 0;
        // a lot of guys would recommend using binary search, but if if its isnt intutive to u. dont pani, cause already your time complexity jumped to nlogn when you sorted the array. 
        for(i=0;i<n;i++){
            if(n-i<=citations[i])
                return n-i;
        }
        return 0;
    }
};