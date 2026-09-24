class Solution {
public:
    bool isValid(string s) {
        stack<int> st;
        
        unordered_map<char, char> mp = { {'(', ')'}, {'[', ']'}, {'{', '}'} };

        for (int i = 0; i < s.size(); i++) {
            // check if the starting bracket exists
            if  ( mp.contains(s[i]) ) {
                st.push(s[i]);

            } else {

                if (st.empty()) {
                    return false;
                }
    
                if (s[i] == mp[st.top()]) {
                    st.pop();
                } else {
                    return false;
                }

            }

        }

        if (st.size() == 0) {
            return true;
        }

        return false;
    }
};
