class Solution {
public:
    bool check(int row, int col, vector<vector<int>>& grid)
    {
        return col >= 0 && col<grid[0].size() && row >= 0 && row <grid.size();
    }
    int islandPerimeter(vector<vector<int>>& grid) {
        int sum = 0;
        for(int i=0; i<grid.size(); i++)
        {
            for(int j=0; j<grid[0].size(); j++)
            {
                int tmp =4;
                if(grid[i][j] == 1)
                {
                    if(check(i-1,j, grid) && grid[i-1][j])
                    {
                        tmp--;
                    }
                    if(check(i+1,j, grid) && grid[i+1][j])
                    {
                        tmp--;
                    }
                    if(check(i,j-1, grid) && grid[i][j-1])
                    {
                        tmp--;
                    }
                    if(check(i,j+1, grid) && grid[i][j+1])
                    {
                        tmp--;
                    }
                     sum = sum + tmp;   
                }
            }
        }
        return sum;
    }
};