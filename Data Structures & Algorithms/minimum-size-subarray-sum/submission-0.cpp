class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int sum = 0;
        int left = 0;
        int min = INT_MAX;

        for (int right = 0; right < nums.size(); right++) {
            sum += nums[right];

            while(sum >= target) {
                int min_now = right - left + 1;
                if (min_now < min) {min = min_now;}

                sum -= nums[left];
                left++;
            }
        } 

        if (min == INT_MAX) {return 0;}

        return min;
    }
};