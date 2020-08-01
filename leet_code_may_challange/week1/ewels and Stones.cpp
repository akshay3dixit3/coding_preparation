class Solution {
public:
    int numJewelsInStones(string J, string S) {
        unordered_map<char, int> jewel;
        int count = 0;
        for(auto c: J)
        {
            jewel[c]++;
        }
        
        for(auto c: S)
        {
            if(jewel.find(c) != jewel.end() )
            {
                count++;
            }
        }
        return count;
    }
};