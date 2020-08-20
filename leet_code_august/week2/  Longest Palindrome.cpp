class Solution {
public:
    int longestPalindrome(string s) {
        vector<int> freq(60, 0);
        int total_count = 0, odd_counter = 0;
        for(auto c:s)
        {
            freq[c - 'A']++;
        }  
        for(auto c : freq)
        {
            if(c%2)
            {
                if(!odd_counter)
                {
                    odd_counter++;
                }
                if(c > 2)
                {
                    total_count = total_count + (c-1);
                }
            }
            else
            {
                total_count = total_count + c;
            }
            
        }
        return total_count + odd_counter;
    }
};