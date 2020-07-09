class Solution {
public:
   vector<vector<int>> threeSum(vector<int>& num) {
     if (num.size() < 2) { return {}; }
        sort(num.begin(), num.end());
        vector<vector<int> > result; 
        int i = 0;
        while (i < num.size() - 2) {
            int target = -num[i];
            int j = i + 1, k = num.size() - 1;
            while (j < k) {
                int value = num[j] + num[k];
                if (value == target) {
                   result.emplace_back(vector<int>{num[i], num[j], num[k]});
                   do { j++; } while (j < k && num[j] == num[j - 1]);
                   do { k--; } while (j < k && num[k] == num[k + 1]);
                } else if (value < target) {
                   do { j++; } while (j < k && num[j] == num[j - 1]);
                } else {
                   do { k--; } while (j < k && num[k] == num[k + 1]);
                }
            }
            do { i++; } while (i < num.size() - 2 && num[i] == num[i - 1]);
        }
        return result;
}
};