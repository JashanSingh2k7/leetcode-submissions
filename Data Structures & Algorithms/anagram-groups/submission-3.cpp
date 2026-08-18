class Solution {

// group anagrams
// find anagrams and then group them together
// first setup is to find the anagrams (I now how to do)
// I must figure out how to store all of it, extra method
// visited array could be worth it.  

public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> anagramGroups;
        
        for (const string& s : strs) {
            string key = s; 
            sort(key.begin(), key.end()); 
            
            anagramGroups[key].push_back(s);
        }
        
        vector<vector<string>> solution;
        
        for (auto& pair : anagramGroups) {
            solution.push_back(pair.second);
        }
        
        return solution;
    }
};
