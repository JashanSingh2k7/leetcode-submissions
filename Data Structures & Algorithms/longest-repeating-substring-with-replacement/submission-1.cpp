class Solution {
public:
    int characterReplacement(string s, int k) {
        vector<int> freq(26, 0);

        int left = 0;

        int result = 0;

        for (int right = 0; right < s.size(); right++) {
            freq[s[right] - 'A']++;

            int max_val = *max_element(freq.begin(), freq.end());

            while ( (right - left + 1) - max_val > k) {
                freq[s[left] - 'A']--;
                left++;
                max_val = *max_element(freq.begin(), freq.end());
            }

            result = max(result, right - left + 1);


        }

        return result;
    }
};
