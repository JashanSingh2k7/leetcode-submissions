class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int score = 0;
        int maxx = 0;
        int left = 0;
        int k_have = k;

        for (int right = 0; right < nums.size(); right++) {
            
            if (nums[right] == 1) {
                score++;
            } 
            else if (nums[right] == 0 && k_have > 0) {
                score++;
                k_have--;
            } 
            else if (nums[right] == 0 && k_have == 0) {
                
                while (k_have == 0 ) {
                    if (nums[left] == 0) {
                        k_have++; 
                    }
                    score--;      
                    left++;       
                }
                
                if (k_have > 0) {
                    score++;
                    k_have--;
                }
            }

            maxx = max(maxx, score);
        }

        return maxx;
    }
};