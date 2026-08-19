class Solution {
public:
    int maxArea(vector<int>& heights) {
        int left = 0;
        int right = heights.size() - 1;

        int max = 0;

        while(left < right) {
            int curr = (right - left) * min(heights[left], heights[right]);
            
            if (curr > max) {
                max = curr;
            }

            if (heights[left] > heights[right]) {
                right--;
            } else {
                left++;
            }
        }

        return max;
    }
};
