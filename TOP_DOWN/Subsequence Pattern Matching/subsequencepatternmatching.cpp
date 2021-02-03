using namespace std;

#include <iostream>
#include <string>
#include <vector>

class SPM {
public:
  int findSPMCount(const string &str, const string &pat) {
        vector<vector<int> > dp(str.size(), vector<int> (pat.size(), -1));
        return findSPMCountRecursive(dp, str, pat, 0, 0);
  }

private:
  int findSPMCountRecursive(vector<vector<int> > dp, const string &str, const string &pat, int strIndex, int patIndex) {
        if(patIndex == pat.size())
            return 1;

        if(strIndex == str.size())
            return 0;
        
        if(dp[strIndex][patIndex] == -1)
        {
            int count1 = 0;
            if(str[strIndex] ==  pat[patIndex])
            {
                count1 = findSPMCountRecursive(dp, str, pat, strIndex+1, patIndex +1);
            }
            int count2 =  findSPMCountRecursive(dp, str, pat, strIndex+1, patIndex);
    
            dp[strIndex][patIndex] = count2 + count1;
        }

    return dp[strIndex][patIndex];    
  }
};

int main(int argc, char *argv[]) {
  SPM *spm = new SPM();
  cout << spm->findSPMCount("baxmx", "ax") << endl;
  cout << spm->findSPMCount("tomorrow", "tor") << endl;

  delete spm;
}
