
#include <iostream>
#include <vector>
using namespace std;
class LBS {
public:
  int findLBSLength(const vector<int> &nums) {
    int n = nums.size();
    vector<int> ltor (nums.size(), 1);
    vector<int> rtol (nums.size(), 1);

    for(int i=0 ; i<n ; i++)
    {
      for(int j=0; j<i; j++)
      {
        if(nums[i] > nums[j] && ltor[j] + 1 > ltor[i])
          ltor[i] = ltor[j] + 1;
      }
    }

    for(int i = n-1; i>=0; i--)
    {
      for(int j = n-1; j>i; j--)
      {
        if(nums[i] > nums[j] && rtol[j] + 1 > rtol[i])
          rtol[i] = rtol[j] + 1;
      }
    }

    int maxlen = 1;
    for(int i =0; i<n; i++)
    {
      maxlen = max(maxlen, rtol[i] + ltor[i] - 1);
    }
    return maxlen;
  }
};

int main(int argc, char *argv[]) {
  LBS *lbs = new LBS();
  vector<int> nums = {4, 2, 3, 6, 10, 1, 12};
  cout << lbs->findLBSLength(nums) << endl;
  nums = vector<int> {4, 2, 5, 9, 7, 6, 10, 3, 1};
  cout << lbs->findLBSLength(nums) << endl;

  delete lbs;
}