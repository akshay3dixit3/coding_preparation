
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class LCS {

public:
  int findLCSLength(const string &s1, const string &s2) {
    int maxLength = min(s1.length(), s2.length());
    vector<vector<vector<int> > > dp(s1.length(),
                                   vector<vector<int> >(s2.length(), vector<int>(maxLength, -1)));
    return findLCSLengthRecursive(dp, s1, s2, 0, 0, 0);
  }

private:
  int findLCSLengthRecursive(vector<vector<vector<int> > > &dp, const string &s1, const string &s2,
                             int i1, int i2, int count) {
    if (i1 == s1.length() || i2 == s2.length()) {
      return count;
    }

    if (dp[i1][i2][count] == -1) {
      int c1 = count;
      if (s1[i1] == s2[i2]) {
        c1 = findLCSLengthRecursive(dp, s1, s2, i1 + 1, i2 + 1, count + 1);
      }
      int c2 = findLCSLengthRecursive(dp, s1, s2, i1, i2 + 1, 0);
      int c3 = findLCSLengthRecursive(dp, s1, s2, i1 + 1, i2, 0);
      dp[i1][i2][count] = max(c1, max(c2, c3));
    }

    return dp[i1][i2][count];
  }
};

int main(int argc, char *argv[]) {
  LCS *lcs = new LCS();
  cout << lcs->findLCSLength("abdca", "cbda") << endl;
  cout << lcs->findLCSLength("passport", "ppsspt") << endl;

  delete lcs;
}