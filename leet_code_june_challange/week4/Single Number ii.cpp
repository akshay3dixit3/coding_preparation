//Complexity of solution is O(32*N)that is O(n)
class Solution {
public:
    int singleNumber(vector<int>& nums) {
    int k = 3, ans = 0;
        for(int i=0; i<32; i++)
        {
            int count =0;
            int mask =(1<<i); // to check the particular bit
            
            for(auto num: nums)
            {
                count = count + bool(num & mask); //check with each bit and increment the count 
            }
            
            if(count % k) //check if the bit is set number of times coimpletly divisible by 3 if not its in the answer.
            {
                ans = ans | mask; //make amendment to the answer.
            }
        }
        
        return ans;
    }
};