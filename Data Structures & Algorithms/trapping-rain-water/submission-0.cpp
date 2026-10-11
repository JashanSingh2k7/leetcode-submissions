class Solution {
public:
    int trap(vector<int>& height) {
        // two pointer problem
        int right = height.size() - 1;
        int left = 0;

        int rightMax = 0;
        int leftMax = 0;
        int water = 0;
        
        while (right > left) {
            
            // update the max
            rightMax = max(height[right], rightMax);
            leftMax = max(height[left], leftMax);

            int small = min(rightMax, leftMax);

            // movement of the pointers
            if ( height[left] > height[right] ) {
                right--;

                if (height[right] < small) {
                    water += small - height[right];
                }

            } else {
                left++;

                if (height[left] < small) {
                    water += small - height[left];
                }

            }

        }

        return water;

    }
};
