class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        
        // Guard against empty matrices to prevent segfaults
        if (matrix.empty() || matrix[0].empty()) return {};

        vector<int> solution;

        int up = matrix.size();
        int down = matrix.size();
        int left = matrix[0].size();
        int right = matrix[0].size();

        vector<string> direc= {"right", "down", "left", "up"};

        int row = 0;    
        int col = 0;

        solution.push_back(matrix[row][col]);

        string path;
        int count = 1;
        int phase = 0;
        
        while(count < matrix[0].size() * matrix.size()) {

            path = direc[phase % 4];
            
            if (path == "right") {
                for (int i = 1; i < right; i++) {
                    col++;
                    solution.push_back(matrix[row][col]);
                    count++;
                }
                // First pass loses only the top row. Inner passes lose both sides.
                up -= (phase == 0) ? 1 : 2;
            }

            if (path == "down") {
                for (int i = 0; i < down - 1; i++) {
                    row++;
                    solution.push_back(matrix[row][col]);
                    count++;
                }
                // First pass loses only the right col. Inner passes lose both sides.
                right -= (phase == 1) ? 1 : 2;
            }

            if (path == "left") {
                for (int i = 0; i < left - 1; i++) {
                    col--;
                    solution.push_back(matrix[row][col]);
                    count++;
                }
                // Left is always an inner pass, bounded by right and left columns
                down -= 2;
            }

            if (path == "up") {
                for (int i = 0; i < up - 1; i++) {
                    row--;
                    solution.push_back(matrix[row][col]);
                    count++;
                }
                // Up is always an inner pass, bounded by top and bottom rows
                left -= 2;
            }

            phase++;
        }

        return solution;                                                                                                                                                                                                                     
    }
};