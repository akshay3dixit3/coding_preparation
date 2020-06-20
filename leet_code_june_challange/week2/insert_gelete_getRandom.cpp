class RandomizedSet {
public:
    bool insert(int val) {
        auto it = data.find(val);
        if (it == data.end())
        {
            data.emplace_hint(it, val);
            return true;
        }
        return false;
    }

    bool remove(int val) {
        auto it = data.find(val);
        if (it != data.end())
        {
            data.erase(it);
            return true;
        }
        return false;
    }
    
    int getRandom() {
        int shift = rand() % data.size();
        auto res = data.begin();
        advance(res, shift);
        return *res;
    }
private:
    unordered_set<int> data;
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */

// class RandomizedSet {
//     unordered_map<int, int> index; // map of num to its index in nums array
//     vector<int> nums; // storing the actual numbers inserted
//     int size;
    
// public:
//     /** Initialize your data structure here. */
//     RandomizedSet() : size(0) {
//         /* initialize random seed: */
//         srand (time(NULL));
//     }
    
//     /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
//     bool insert(int val) {
//         if (index.find(val) != index.end())
//             return false;
            
//         nums.push_back(val);
//         index[val] = size ++;
//         return true;
//     }
    
//     /** Removes a value from the set. Returns true if the set contained the specified element. */
//     bool remove(int val) {
//         if (index.find(val) == index.end())
//             return false;
        
//         int back = nums.back();
//         int backIdx = index[back];
        
//         int delIdx = index[val];
        
//         swap(nums[backIdx], nums[delIdx]); // swap with last element in nums
//         nums.pop_back();
        
//         index[back] = delIdx; // update last element's index in map
//         index.erase(val); // erase val entry from map
        
//         size --;
        
//         return true;
//     }
    
//     /** Get a random element from the set. */
//     int getRandom() {
//         if (size <= 0) return -1; // should be an exception
        
//         /* generate secret number between 0 and size - 1: */
//         int randIdx = rand() % size;
        
//         return nums[randIdx];
//     }
// };

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */