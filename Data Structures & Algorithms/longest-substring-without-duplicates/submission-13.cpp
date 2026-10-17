class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        // longest subtring without repeating characters problem
        // for loop with a while loop inside it

        if (s.size() == 0) {
            return 0;
        }

        if (s == " ") {
            return 1;
        }

        int l = 0;

        unordered_set<char> st;

        int result = INT_MIN;

        for (int r = 0; r < s.size(); r++) {
            
            while(st.contains(s[r])) {
                st.erase(s[l]);
                l++;
            }

            st.insert(s[r]);
            result = max(result, r - l + 1);

        }

        return result;
    }
};
