using namespace std;

#include <iostream>
#include <vector>

class Knapsack {
public:
  int solveKnapsack(const vector<int> &profits, const vector<int> &weights, int capacity) {
    // basic checks
    if (capacity <= 0 || profits.empty() || weights.size() != profits.size()) {
      return 0;
    }
    
    int n = profits.size();
    vector<vector<int>> dp(profits.size(), vector<int> (capacity+1, 0));
    
    
    for(int i = 0; i<n; i++)
    {
        dp[i][0] = 0; //capacity is zero so zero profits;
    }
    
    for(int i=0; i<=capacity; i++)
    {
        if(weights[0] <= i)
            dp[0][i] = profits[0];
    }
    
    for(int i=1; i<n; i++)
    {
        for(int c =1; c<=capacity; c++)
        {
            int profit1 = 0;
            if(weights[i] <= c)
                profit1 = profits[i] + dp[i-1][c- weights[i]];
            
            int profit2 = dp[i-1][c];
            
            dp[i][c] = max(profit2, profit1);
        }
    }
    printSelectedElements(dp, weights, profits, capacity);

    return dp[n-1][capacity];

  }


private:
  void printSelectedElements(vector<vector<int>> &dp, const vector<int> &weights,
                             const vector<int> &profits, int capacity) {
    cout << "Selected weights:";
    int totalProfit = dp[weights.size() - 1][capacity];
    for (int i = weights.size() - 1; i > 0; i--) {
      if (totalProfit != dp[i - 1][capacity]) {
        cout << " " << weights[i];
        capacity -= weights[i];
        totalProfit -= profits[i];
      }
    }

    if (totalProfit != 0) {
      cout << " " << weights[0];
    }
    cout << "" << endl;
  }
};

int main(int argc, char *argv[]) {
  Knapsack ks;
  vector<int> profits = {1, 6, 10, 16};
  vector<int> weights = {1, 2, 3, 5};
  int maxProfit = ks.solveKnapsack(profits, weights, 6);
  cout << "Total knapsack profit ---> " << maxProfit << endl;
  maxProfit = ks.solveKnapsack(profits, weights, 7);
  cout << "Total knapsack profit ---> " << maxProfit << endl;
}
