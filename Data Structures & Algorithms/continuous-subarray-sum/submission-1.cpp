class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int sum = 0;
        unordered_map<int, int> count;
        count[0] = -1;

        for(int i = 0; i < nums.size(); i++) {

            sum += nums[i];
            int rem = (sum % k + k) % k;

            // only add it if it doesn't exist
            if (!count.contains(rem)) {
                count[rem] = i;
            }
            
            cout << rem << endl;

            if (count.contains(rem)) {
                int size = i - count[rem];
                cout << size << endl;
                if (size >= 2) {
                    return true;
                }
            }

        }

        return false;

    }


};