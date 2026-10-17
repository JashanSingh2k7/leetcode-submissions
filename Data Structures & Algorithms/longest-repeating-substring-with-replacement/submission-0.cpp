
class Solution {
public:
    int characterReplacement(string s, int k) {
        vector<int> freq(26, 0);
        int l = 0;
        int result = 0;

        for (int r = 0; r < s.size(); r++) {
            freq[s[r] - 'A']++;

            int max_freq = *max_element(freq.begin(), freq.end());

            while ((r - l + 1) - max_freq > k) {
                freq[s[l] - 'A']--;
                l++;

                max_freq = *max_element(freq.begin(), freq.end());
            }

            result = max(result, r - l + 1);
        }

        return result;
    }
};
