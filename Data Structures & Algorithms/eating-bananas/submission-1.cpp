
class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int left = 1;
        int right = *max_element(piles.begin(), piles.end());

        while (left < right) {
            int mid = left + (right - left) / 2;

            long long hours = 0;

            // Calculate hours needed at this speed
            for (int pile : piles) {
                hours += pile / mid + (pile % mid != 0);
            }

            if (hours <= h) {
                // Speed works; try something smaller
                right = mid;
            } else {
                // Speed too slow; need a faster one
                left = mid + 1;
            }
        }

        return left;
    }
};
