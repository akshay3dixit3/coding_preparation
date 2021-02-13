using namespace std;

#include <iostream>
#include <string>
#include <vector>
class LRS {

public:
  int findLRSLength(const string &str) { 
      vector<vector<int> > dp(str.size(), vector<int> (str.size(), -1));
      return findLRSLengthRecursive(dp, str, 0, 0); 
    }

private:
  int findLRSLengthRecursive(vector<vector<int> > dp, const string &str, int i1, int i2) {
        if(i1 == str.size() || i2 == str.size())
            return 0;
        
        if(dp[i1][i2] == -1)
        {
            if(i2 != i1 && str[i2] ==  str[i1])
            dp[i1][i2] =  1 + findLRSLengthRecursive(dp, str, i1+1, i2+1);
        
            else
            {
                int count1 = findLRSLengthRecursive(dp, str, i1+1, i2);
                int count2 = findLRSLengthRecursive(dp, str, i1, i2+1);

                dp[i1][i2] = max(count1, count2);
            }
        }
        return dp[i1][i2];
    }
};

int main(int argc, char *argv[]) {
  LRS *lrs = new LRS();
  cout << lrs->findLRSLength("tomorrow") << endl;
  cout << lrs->findLRSLength("aabdbcec") << endl;
  cout << lrs->findLRSLength("fmff") << endl;

  delete lrs;
}
