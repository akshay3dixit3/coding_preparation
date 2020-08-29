class Solution {
    void dfs(int num,int n,vector<int> & result, int k){
        
        if(n==0){
            result.push_back(num);
        }
        else{
            int prev_digit= num%10;
            if(prev_digit+k <=9){
                dfs(num*10 + prev_digit + k , n-1, result,k);
            }
            if(k!=0 && prev_digit-k >=0){
                dfs(num*10 + prev_digit - k , n-1, result,k);
                
            }
        }
    }

public:
    vector<int> numsSameConsecDiff(int N, int K) {
         if(N==1)return {0,1,2,3,4,5,6,7,8,9};

        vector<int> result;
        for(int i=1;i<=9;i++){
            dfs(i,N-1,result,K);
        }
        return result;   
        
    }
};