class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int, int>> que;

        bool contain_one = false;
        // added the initial rotten ones in
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == 2) {
                    que.push({i, j});
                }

                if (grid[i][j] == 1) {
                    contain_one = true;
                }
            }
        }

        if ( que.empty() ) {
            if (contain_one) {return -1;}

            return 0;
            
        }

        int count = 0;

        while(!que.empty()) {
            
            int size = que.size();
            for (int s = 0; s < size; s++) {

                auto [i, j] = que.front();
                que.pop();

                vector<pair<int, int>> d = {{1, 0}, {0,1}, {-1, 0}, {0, -1} };

                for (int n = 0; n < d.size(); n++) {
                    int new_i = i + d[n].first;
                    int new_j = j + d[n].second;

                    if (0 <= new_i && new_i < grid.size() && 0 <= new_j && new_j < grid[0].size()) {
                        if (grid[new_i][new_j] == 1) {
                            grid[new_i][new_j] = 2;
                            que.push({new_i, new_j});
                        }
                    }
                }
            }

            count++;

        }

        // if it has anything unresolved
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] != 2 && grid[i][j] != 0) {
                    return -1;
                }
            }
        }

        return count - 1;

    }

    
};
