class Solution {
public:


    void helper(int i, int j, vector<vector<char>>& grid) {
        
        if (0 <= i && i < grid.size() && 0 <= j && j < grid[0].size() && grid[i][j] == '1') {
            grid[i][j] = '0';
            helper(i + 1, j, grid);
            helper(i - 1, j, grid);
            helper(i, j + 1, grid);
            helper(i, j - 1, grid);
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        
        int count = 0;

        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == '1') {
                    helper(i, j, grid);
                    count++;
                }
                
            }
        }

        return count;
    }
};
