class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int count = 0;
        unordered_map<int, int> c;
        int sum = 0;

        c[0] = 1;

        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];

            int need = sum - k;

            if (c.contains(need)) {
                count += c[need];
            }

            c[sum]++;
        }


        return count;

    }
};