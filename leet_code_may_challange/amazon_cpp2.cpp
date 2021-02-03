#include<vector>
#include<iostream>
#include <algorithm>

using namespace std;
bool isvalid(int row, int col, int row_size, int col_size)
{
    return row>=0 && row<row_size && col>=0 && col<col_size;
}
// int min (int left, int right)
// {
//     return left < right ? left : right;
// }

int dfs(vector<vector<int>> arr, int row, int col, int row_size, int col_size, vector<vector<int>> &visited, int depth)
{
    // visited[row][col] = 1;

    if(arr[row][col] == 0)
        return INT_MAX;
    
    if(arr[row][col] == 9)
        return depth;
    depth++;
    
    if(arr[row][col] == 1)
    {
        int left = INT_MAX, right = INT_MAX, up = INT_MAX, down = INT_MAX;
        if(isvalid(row+1, col, row_size, col_size) && !visited[row+1][col])
            left = dfs(arr, row+1, col, row_size, col_size, visited, depth);
        
        if(isvalid(row-1, col, row_size, col_size) && !visited[row-1][col])
            right = dfs(arr, row-1, col, row_size, col_size, visited, depth);
        
        if(isvalid(row, col+1, row_size, col_size) && !visited[row][col+1])
            up = dfs(arr, row, col+1, row_size, col_size, visited, depth);
        
        if(isvalid(row, col-1, row_size, col_size) && !visited[row][col-1])
            down = dfs(arr, row, col-1, row_size, col_size, visited, depth);
        
        int minimum_depth  =  min(left, min(right, min(up, down)));
        return minimum_depth;
    }
    return 0;

}
int main()
{
    vector<vector<int>> arr = { {1, 1, 0},
                                {1, 9, 1},
                                {1, 1, 0},
                                {1, 0, 1} };
    int row_size = arr.size();
    int col_size = arr[0].size();
    vector<vector<int>> visited(row_size, vector<int> (col_size, 0));
    int answer = dfs(arr, 0, 0, row_size, col_size, visited, 0);
    cout<<answer;
    return answer;
}