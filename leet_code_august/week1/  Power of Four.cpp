class Solution {
public:
    
    bool isPowerOfFour(int num) {
        
        if(num==1){return true;}
        
        if(num&1){return false;}
        
        for(int i=0;i<=30;i=i+2){
          if((1<<i)==num){return true;}            
        }
        
    return false;
        
    }
};