//https://kennyzhuang.gitbooks.io/algorithms-collection/content/buy_and_sell_stock_with_cooldown.html
class Solution {
public:
    int maxProfit(vector<int>& prices) {
    if(prices.size() == 0 || prices.size() <= 1) return 0;

    int b0 = -prices[0], b1 = b0;
    int s0 = 0, s1 = 0, s2 = 0;

    for(int i = 1; i < prices.size(); i++) {
        b0 = max(b1, s2 - prices[i]);
        s0 = max(s1, b1 + prices[i]);
        b1 = b0; s2 = s1; s1 = s0; 
    }
    return s0;
}
};