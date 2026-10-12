class Solution {
public:
    int longestConsecutive(vector<int>& nums) {

        if (nums.size() == 0) {return 0;}
        // last question of arrays and hashing. 
        sort(nums.begin(), nums.end());

        unordered_set<int> or_set;

        vector<int> new_nums;

        // no duplicates
        for (int i = 0; i < nums.size(); i++) {
            if (!or_set.contains(nums[i])) {
                new_nums.push_back(nums[i]);
                or_set.insert(nums[i]);
            }
        }

        for (int i = 0; i < new_nums.size(); i++) {
            cout << new_nums[i] <<  " ";
        }

        cout << endl;

        int count = 0;
        int return_max = INT_MIN;

        for (int i = 1; i < new_nums.size(); i++) {
            if ( new_nums[i - 1] + 1 == new_nums[i]) {
                count++;
            } else {
                return_max = max(return_max, count);
                count = 0;
            }
        }

        return_max = max(return_max, count);

        return return_max + 1;



    }
};
