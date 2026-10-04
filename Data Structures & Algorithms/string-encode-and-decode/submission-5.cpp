class Solution {
public:

    string encode(vector<string>& strs) {
        string encoded_string = "";

        for (int i = 0; i < strs.size(); i++) {
            encoded_string += to_string(strs[i].size());
            encoded_string += "#";
            encoded_string += strs[i];
        }

        return encoded_string;
    }

    vector<string> decode(string s) {
        vector<string> decoded_strs;

        int i = 0;

        while (i < s.size()) {

            // Find where the length ends
            int j = i;

            while (s[j] != '#') {
                j++;
            }

            // Extract the length
            int length = stoi(s.substr(i, j - i));

            // The actual string starts after '#'
            string word = s.substr(j + 1, length);

            decoded_strs.push_back(word);

            // Move i to the start of the next encoded string
            i = j + 1 + length;
        }

        return decoded_strs;
    }
};