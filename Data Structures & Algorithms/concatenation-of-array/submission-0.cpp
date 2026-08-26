class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
        vector<int> new_vector(nums.size()*2);

        for (int i = 0; i < nums.size() * 2; i++) {
            new_vector[i] = nums[i%nums.size()];
        }

        return new_vector;
    }
};