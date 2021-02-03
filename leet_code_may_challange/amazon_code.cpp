#include<vector>
#include<iostream>

using namespace std;

int main()
{
    vector<vector<int>> arr = { {1, 1, 0},
                                {1, 0, 0},
                                {1, 1, 1},
                                {1, 0, 9} };
    int row_size = arr.size();
    int col_size = arr[0].size();

    vector<vector<int>> dp(row_size+2, vector<int> (col_size +2, INT_MAX));
    dp[1][1] = 1;
    int dest_x, dest_y;
    for(int i=0; i<row_size; i++)
    {
        for(int j=0; j<col_size; j++)
        {
            int x = i+1;
            int y = j+1;
            if(arr[i][j] == 0)
                continue;
            
            if(arr[i][j] == 9)
            {
                // dp[x][y] = 1 + min(dp[x][y], min(dp[x-1][y], min(dp[x+1][y], min(dp[x][y-1], dp[x][y+1]))));
                // cout<<dp[i+1][j+1] - 2;
                // break;       
                dest_x = x;
                dest_y = y;
                continue; 
            }
            
            // int x = i+1;
            
            dp[x][y] = 1 + min(dp[x][y], min(dp[x-1][y], min(dp[x+1][y], min(dp[x][y-1], dp[x][y+1]))));

        }
    }
    cout<<min(dp[dest_x][dest_y], min(dp[dest_x-1][dest_y], min(dp[dest_x+1][dest_y], min(dp[dest_x][dest_y-1], dp[dest_x][dest_y+1]))))-1;

    return 0;
}