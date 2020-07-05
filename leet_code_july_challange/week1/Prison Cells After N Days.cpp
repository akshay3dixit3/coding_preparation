class Solution {
public:
  vector<int> prisonAfterNDays(vector<int>& c, int N) {
    
  vector<int> first_combination, next_combination(c.size(), 0);
    
  for (int mod_value = 0; N-- > 0; c = next_combination, ++mod_value) {
    for (auto i = 1; i < c.size() - 1; ++i) 
       next_combination[i] = c[i - 1] == c[i + 1];
    
    if (mod_value == 0) first_combination = next_combination;
    else if (next_combination == first_combination) N %= mod_value;
  
  }
  return c;
    
}
};
