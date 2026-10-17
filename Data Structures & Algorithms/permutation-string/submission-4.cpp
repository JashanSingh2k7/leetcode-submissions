class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int s1_size = s1.size();
        sort(s1.begin(), s1.end());
        
        if (s1.size() > s2.size()) {
            return false;
        }

        for (int i = 0; i < s2.size() - s1.size() + 1; i++) {
            string s2_substr = s2.substr(i, s1.size());
            sort(s2_substr.begin(), s2_substr.end());
            // cout << s2_substr << " " << s1 << endl;

            if (s2_substr == s1) {
                // cout << s2_substr << " " << s1 << endl;
                return true;
            }
        }

        return false;
    }
};
