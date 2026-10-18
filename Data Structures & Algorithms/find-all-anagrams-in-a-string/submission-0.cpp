class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> freq1(26, 0);
        vector<int> freq2(26, 0);

        if (p.size() > s.size()) {
            return {};
        }

        for (int i = 0; i < p.size(); i++) {
            freq1[p[i] - 'a']++;
            freq2[s[i] - 'a']++;
        }

        
        int left = 0;
        vector<int> result;

        if (freq1 == freq2) {
            result.push_back(0);
        }

        for (int i = p.size(); i < s.size(); i++) {
            freq2[s[i] - 'a']++;
            freq2[s[left] - 'a']--;
            left++;

            // check again
            if (freq1 == freq2) {
                result.push_back(left);
            }

        }

        return result;


    }
};
