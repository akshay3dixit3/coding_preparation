class Solution {
public:
    int hammingDistance(int x, int y) {
        int i =1;
        int count=0;

        while(x>0 && y>0)
        {
            
            if(((x&1) ^ (y&1))) //get last bit and xor them with each other.
            {
                count++; //increase count if true
            }
            x= x>>1; //right shift 
            y= y>>1;
        }

        while(x > 0) //if y is smaller than zero then x may be left to be processed.
        {

            if(x & 1) //cause y =0 so wherever x has set bit we increase
                count++;
            x= x>>1;
        }
        while(y > 0)
        {

            if(y & 1) //same logic as that for x
                count++;
            y=y>>1;
        }
        return count;
    }
};