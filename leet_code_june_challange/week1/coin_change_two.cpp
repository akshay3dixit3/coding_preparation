class Solution {
public:
    unordered_map<string,int> lookup;
    // int count = 0;
    int count(vector<int>& S,int n,int N)
    {
        // if total is 0, return 1 (solution found)
	if (N == 0)
		return 1;

	// return 0 (solution do not exist) if total become negative or
	// no elements are left
	if (N < 0 || n < 0)
		return 0;

	// construct an unique map key from dynamic elements of the input
	string key = to_string(n) + "|" + to_string(N);

	// if sub-problem is seen for the first time, solve it and
	// store its result in a map
	if (lookup.find(key) == lookup.end())
	{
		// Case 1. include current coin S[n] in solution and recur
		// with remaining change (N - S[n]) with same number of coins
		int include = count(S, n, N - S[n]);

		// Case 2. exclude current coin S[n] from solution and recur
		// for remaining coins (n - 1)
		int exclude = count(S, n - 1, N);

		// assign total ways by including or excluding current coin
		lookup[key] = include + exclude;
	}

	// return solution to current sub-problem
	return lookup[key];
        
    }
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        
        int count_ans  = count(coins, n-1, amount);
        return count_ans;
    }
};