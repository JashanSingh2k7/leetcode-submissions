class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_set<char> seen_row;
        unordered_set<char> seen_col;

        for (int i = 0; i < board.size(); i++) {
            seen_row.clear();
            seen_col.clear();

            for (int n = 0; n < board[i].size(); n++) {

                // rows
                if (board[i][n] != '.') {
                    if (!seen_row.contains(board[i][n])) {
                        seen_row.insert(board[i][n]);
                    } else {
                        return false;
                    }
                }

                // cols
                if (board[n][i] != '.') {
                    if (!seen_col.contains(board[n][i])) {
                        seen_col.insert(board[n][i]);
                    } else {
                        return false;
                    }
                }
            }
        }

        // need a way to interate through the 3x3 grid in the setup. 

        unordered_set<int> grid_seen;

        for (int i = 0; i < board.size(); i += 3) {
            for (int n = 0; n < board.size(); n += 3) {
                grid_seen.clear();

                for (int row = 0; row < 3; row++) {
                    for (int col = 0; col < 3; col++) {
                        

                        if (board[row + i][col + n] != '.') {
                            if (!grid_seen.contains(board[row + i][col + n])) {
                                grid_seen.insert(board[row + i][col + n]);
                            } else {
                                return false;
                            }
                        }


                    }
                }


            }
        }

        // (0, 0)
        // (0, 3)
        // (0, 6)

        // (3, 0)
        // (3, 3)
        // (3. 6)

        // (6, 0)
        // (6, 3)
        // (6, 6)

        return true;
    }
};
