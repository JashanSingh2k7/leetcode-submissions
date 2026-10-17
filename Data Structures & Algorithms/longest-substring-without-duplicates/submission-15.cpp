class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        // longest subtring without repeating characters problem
        // for loop with a while loop inside it

        int l = 0;

        unordered_set<char> st;

        int result = 0;

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
