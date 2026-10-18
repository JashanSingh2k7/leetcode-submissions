
class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        // Create two matrices, one for Atlantic and one for Pacific
        // BFS solution

        if (heights.empty() || heights[0].empty()) {
            return {};
        }

        vector<vector<int>> atlantic(heights.size(), vector<int>(heights[0].size(), 0));
        vector<vector<int>> pacific(heights.size(), vector<int>(heights[0].size(), 0));

        queue<pair<int, int>> aq;
        queue<pair<int, int>> pq;

        // Atlantic: bottom row
        for (int i = 0; i < heights[0].size(); i++) {
            aq.push({(int)heights.size() - 1, i});
            atlantic[heights.size() - 1][i] = 1;
        }

        // Atlantic: right column
        for (int i = 0; i < heights.size(); i++) {
            if (atlantic[i][heights[0].size() - 1] == 0) {
                aq.push({i, (int)heights[0].size() - 1});
                atlantic[i][heights[0].size() - 1] = 1;
            }
        }

        while (!aq.empty()) {
            auto [col, row] = aq.front();
            aq.pop();

            vector<pair<int, int>> coor = {
                {1, 0}, {0, 1}, {-1, 0}, {0, -1}
            };

            for (int i = 0; i < coor.size(); i++) {
                auto [dcol, drow] = coor[i];

                int new_col = dcol + col;
                int new_row = drow + row;

                if (new_col < heights.size() && new_col >= 0 &&
                    new_row >= 0 && new_row < heights[0].size()) {

                    if (atlantic[new_col][new_row] == 0 &&
                        heights[new_col][new_row] >= heights[col][row]) {

                        atlantic[new_col][new_row] = 1;
                        aq.push({new_col, new_row});
                    }
                }
            }
        }

        // Pacific: top row
        for (int i = 0; i < heights[0].size(); i++) {
            pq.push({0, i});
            pacific[0][i] = 1;
        }

        // Pacific: left column
        for (int i = 0; i < heights.size(); i++) {
            if (pacific[i][0] == 0) {
                pq.push({i, 0});
                pacific[i][0] = 1;
            }
        }

        while (!pq.empty()) {
            auto [col, row] = pq.front();
            pq.pop();

            vector<pair<int, int>> coor = {
                {1, 0}, {0, 1}, {-1, 0}, {0, -1}
            };

            for (int i = 0; i < coor.size(); i++) {
                auto [dcol, drow] = coor[i];

                int new_col = dcol + col;
                int new_row = drow + row;

                if (new_col < heights.size() && new_col >= 0 &&
                    new_row >= 0 && new_row < heights[0].size()) {

                    if (pacific[new_col][new_row] == 0 &&
                        heights[new_col][new_row] >= heights[col][row]) {

                        pacific[new_col][new_row] = 1;
                        pq.push({new_col, new_row});
                    }
                }
            }
        }

        vector<vector<int>> soln;

        for (int i = 0; i < heights.size(); i++) {
            for (int j = 0; j < heights[0].size(); j++) {
                if (pacific[i][j] == 1 && atlantic[i][j] == 1) {
                    soln.push_back({i, j});
                }
            }
        }

        return soln;
    }
};
