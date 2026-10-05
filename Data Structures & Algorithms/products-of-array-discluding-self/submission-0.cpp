class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        // you can multiply all but you get run with the 0 case. 
        int count = 0;
        vector<int> v1 = {0};

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 0) {
                count++;
            }
        }


        if (count > 1) {
            return vector<int>(nums.size(), 0);
        } 
        
        else if (count == 1) {
            int result = 1;
            vector<int> vec1;

            // get result other than 0
            for (int i = 0; i < nums.size(); i++) {

                if ( nums[i] == 0) {
                    continue;
                } 

                result *= nums[i];
            }

            

            // add the values
            for (int i = 0; i < nums.size(); i++) {
                if (nums[i] == 0) {
                    vec1.push_back(result);
                    continue;
                }

                vec1.push_back(0);
            }

            return vec1;

        } 
        
        else {
            int product = 1; 
            vector<int> vec2;

            for (int i = 0; i < nums.size(); i++) {
                product *= nums[i];
            }

            for (int i = 0;i < nums.size(); i++) {
                vec2.push_back(product / nums[i]);
            }

            return vec2;

        }

        return v1;

    }
};
