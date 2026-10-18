class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> result;

        // added all the string into the result
        for (string s : strs) {
            string temp = s;
            sort(s.begin(), s.end());
            result[s].push_back(temp);
        }

        vector<vector<string>> solution;

        for (auto& [key, value] : result) {
            solution.push_back(value);
        }

        return solution;
    }
};
