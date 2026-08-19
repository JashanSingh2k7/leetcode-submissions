class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int left = 0;
        int min = 0;

        

        unordered_set<char> curr;

        for(int right = 0; right < s.size(); right++) {

            while(curr.contains(s[right])) {    
                curr.erase(s[left]);
                left++;
            }

           
            curr.insert(s[right]);

            int new_min = right - left + 1;

            if (new_min > min) {
                min = new_min;
            }
            

        }

        
        return min;
    }
};
