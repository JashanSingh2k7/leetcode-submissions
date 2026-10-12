class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;

        sort(nums.begin(), nums.end());

        for (int i = 0; i < nums.size(); i++) {

            // Skip duplicate anchors
            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }

            int target = -nums[i];

            unordered_set<int> seen;

            for (int j = i + 1; j < nums.size(); j++) {

                int complement = target - nums[j];

                if (seen.contains(complement)) {
                    result.push_back({
                        nums[i],
                        complement,
                        nums[j]
                    });
                    
                    while (j + 1 < nums.size() &&
                           nums[j] == nums[j + 1]) {
                        j++;
                    }
                }

                seen.insert(nums[j]);
            }
        }

        return result;
    }
};