class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& coordinates) {
        int y2_y1, x2_x1, x1, y1, x, y, i;
        y2_y1 = coordinates[1][1] - coordinates[0][1];
        x2_x1 = coordinates[1][0] - coordinates[0][0];
        x1 = coordinates[0][0];
        y1 = coordinates[0][1];
        for(i = 2; i < coordinates.size(); i++){
            y = coordinates[i][1];
            x = coordinates[i][0];
            if(x2_x1 * (y - y1) != y2_y1 * (x - x1)){
                return false;
            }
        }
        return true;
    }
};