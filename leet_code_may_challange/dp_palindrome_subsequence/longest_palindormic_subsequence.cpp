
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class LPS {

public:
    int findLPSLength(const string &st) {
        int st_size = st.size();
        vector<vector<int>> dp(st_size, vector<int> (st_size, -1));
        return findLPSLengthUtil(st, dp, 0, st_size-1);
  }
private:
    int findLPSLengthUtil(const string &st, vector<vector<int>> dp, int start_index, int end_index)
    {
        if(start_index > end_index)
            return 0;
        
        if(start_index == end_index)
            return 1;
        
        if(dp[start_index][end_index] == -1)
        {
            if(st[start_index] == st[end_index])
            {
                dp[start_index][end_index] = 2 + findLPSLengthUtil(st, dp, start_index+1, end_index - 1);
            }
            else
            {
                dp[start_index][end_index] = max(findLPSLengthUtil(st, dp, start_index+1, end_index),
                                                findLPSLengthUtil(st, dp, start_index, end_index - 1));
            }
            
        }
        return dp[start_index][end_index];
    }

};

int main(int argc, char *argv[]) {
  LPS *lps = new LPS();
  cout << lps->findLPSLength("abdbca") << endl;
  cout << lps->findLPSLength("cddpd") << endl;
  cout << lps->findLPSLength("pqr") << endl;

  delete lps;
}