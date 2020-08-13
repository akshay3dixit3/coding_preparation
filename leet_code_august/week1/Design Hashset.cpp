class MyHashSet {
    vector<int> keys;
public:
    /** Initialize your data structure here. */
    MyHashSet() {}
    
    void add(int key) {
        int index = lower_bound(keys.begin(),keys.end(),key)-keys.begin();
        if(index < keys.size() && keys[index] == key)
            return;
        keys.insert(keys.begin()+index,key);
    }
    
    void remove(int key) {
        int index = lower_bound(keys.begin(),keys.end(),key)-keys.begin();
        if(index < keys.size() && keys[index] == key)
            keys.erase(keys.begin()+index);
    }
    
    /** Returns true if this set contains the specified element */
    bool contains(int key) {
        int index = lower_bound(keys.begin(),keys.end(),key)-keys.begin();
        if(index < keys.size() && keys[index] == key)
            return true;
        return false;
    }
};