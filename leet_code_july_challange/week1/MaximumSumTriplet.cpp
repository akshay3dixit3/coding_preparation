int getLowValue(set<int>& lowValue, int& n) 
{ 
    auto it = lowValue.lower_bound(n); 
    --it; 
  
    return (*it); 
} 

int Solution::solve(vector<int> &A) {
   
   int ans =0;
   vector<int> suffix(A.size()+1 , 0) ;
    if(A.size() < 3)
        return 0;
   suffix[A.size()] = 0;
   for (int i = A.size() - 1; i >= 0; --i) 
        suffix[i] = max(suffix[i + 1], A[i]); 
    set<int> lowValue; 

    lowValue.insert(INT_MIN); 
   
   for (int i = 0; i < A.size() - 1; ++i) { 
        if (suffix[i + 1] > A[i]) { 
            ans = max(ans, getLowValue(lowValue, 
                                       A[i]) 
                               + A[i] + suffix[i + 1]); 
  
            // Insert arr[i] in set<> for further 
            // processing 
            lowValue.insert(A[i]); 
        } 
    } 
   
    return ans;
}
