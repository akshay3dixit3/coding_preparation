#include <iostream>
#include <string>
#include <vector>
using namespace std;

class LPS {

public:
  int findLPSLength(const string &st) {
        cout<<st<<" ";
        int st_size = st.size();
        vector<vector<bool>> dp(st_size, vector<bool> (st_size, false));
        
        if(st_size == 0 || st_size == 1)                //base cases are covered
            return st_size;
        
        for(int i =0; i<st_size; i++)
            dp[i][i] = true;

        int answer = 1;
        for(int start_index = st.size()-1; start_index>=0; start_index--)
        {
            for(int end_index = start_index+1; end_index < st.size(); end_index++)
            {
                if(st[start_index] == st[end_index])
                {
                    if(end_index - start_index == 1 || dp[start_index+1][end_index-1])
                    {
                        dp[start_index][end_index] = true;
                        answer = max(answer, end_index - start_index + 1);
                    }
                }

            }
        }

    return answer;    
  }
};

int main(int argc, char *argv[]) {
  LPS *lps = new LPS();
  cout << lps->findLPSLength("abdbca") << endl;
  cout << lps->findLPSLength("cdpdd") << endl;
  cout << lps->findLPSLength("pqr") << endl;
  cout << lps->findLPSLength("madam") << endl;

  delete lps;
}
