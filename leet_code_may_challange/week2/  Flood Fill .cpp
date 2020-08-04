class Solution {
public:
    void floodFillUtil(vector<vector<int>>& image, int sr, int sc, int newColor, int prevColor,                                vector<vector<int>>& visited)
    {
        if(sr < 0 || sr >= image.size() || sc < 0 || sc >= image[0].size() || visited[sr][sc])
            return;
        
        if(image[sr][sc] == prevColor)
        {
            image[sr][sc] = newColor;
            visited[sr][sc] = 1;
            floodFillUtil(image, sr+1, sc, newColor, prevColor, visited);
            floodFillUtil(image, sr-1, sc, newColor, prevColor, visited);
            floodFillUtil(image, sr, sc+1, newColor, prevColor, visited);
            floodFillUtil(image, sr, sc-1, newColor, prevColor, visited);
        }
        return;
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        int prevColor = image[sr][sc];
        vector<vector<int> > visited( image.size() , vector<int> (image[0].size(), 0)); 
        floodFillUtil(image, sr, sc, newColor, prevColor, visited);
        return image;    
    }
};