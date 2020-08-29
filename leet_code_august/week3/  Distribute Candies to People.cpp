class Solution {
public:
    vector<int> distributeCandies(int candies, int num_people) {
        {
        vector<int> candiesDistributed(num_people, 0);
        int i = 0;
        
        //while there are still candies to give out
        while (candies > 0) 
        {
            //give every person according to his turn (incremented by one every turn)
            candiesDistributed[i % num_people] += i + 1;
            //update number of candies left
            candies -= i + 1;
            i++;
        }
        
        //incase we gave an extra candy to last person (so if there are less than 0 candies left we decrement last person's candies otherwise candies = 0 so nothing changes)
        candiesDistributed[(i - 1) % num_people] += candies;
        
        
        return candiesDistributed;
    }
        
    }
};