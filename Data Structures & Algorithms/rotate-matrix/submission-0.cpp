class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int size = matrix.size();
        vector<vector<int>> new_matrix(size, vector<int>(size));

        int row = 0;

        for (int i = 0; i < size; i++) {
            for(int j = size - 1; j >= 0 ; j--) {
                
                new_matrix[row][size - 1 - j] = matrix[j][i];
               
            }

            row++;
        }

        // for (int i = 0; i < size; i++) {
        //     for (int j = 0; j < size; j++) {
        //         cout << new_matrix[i][j] << " ";
        //     }

        //     cout << endl;
        // }

        matrix = new_matrix;
    }
};
