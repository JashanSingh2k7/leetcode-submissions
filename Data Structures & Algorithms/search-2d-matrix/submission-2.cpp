class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        //search a 3d matrix
        int start = 0;
        int end = matrix.size() * matrix[0].size() -1;

        while (end >= start) {
            int middle = start + (end - start) / 2;

            if ( target < matrix[middle / matrix[0].size()][middle % matrix[0].size()] ) {
                end = middle - 1;

            } else if (target > matrix[middle / matrix[0].size()][middle % matrix[0].size()]) {
                start = middle + 1;

            } else {
                return true;
            }

        }

        return false;

    }
};
