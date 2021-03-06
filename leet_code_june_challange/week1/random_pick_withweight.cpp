class Solution {
public:
   public:
   int n;
   vector <int> v;
   Solution(vector<int>& w) {
      for(int i = 1; i < w.size(); i++){
         w[i] += w[i - 1]; //calculate a presum array.
      }
      v = w;
   }
   int pickIndex() {
      return upper_bound(v.begin(), v.end(), rand() % v.back()) - v.begin(); //read about upperbound.
                                                //using v.back() cause that will contain the sum of all the values.
   }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */