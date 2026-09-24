class Solution {
public:
    bool isValid(string s) {
        stack<char> st; 
        
        unordered_map<char, char> mp = { {')', '('}, {']', '['}, {'}', '{'} };

        for (int i = 0; i < s.size(); i++) {
            
            if (mp.contains(s[i])) {
                if (st.empty() || st.top() != mp[s[i]]) {
                    return false; 
                }
                st.pop();
            } else {
                st.push(s[i]);
            }
        }

        return st.empty(); 
    }
};