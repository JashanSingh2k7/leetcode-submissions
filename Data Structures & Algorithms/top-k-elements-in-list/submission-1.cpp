class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

        unordered_map<int, int> count; 

        for (int i = 0; i < nums.size(); i++) {
            count[nums[i]]++;
        }

        for ( auto [key, value] : count) {
            pq.push({value, key });
            if (pq.size() > k) {
                pq.pop();
            }
        }  

        vector<int> solution;

        while(!pq.empty()){
            auto [value, key ] = pq.top();
            solution.push_back(key);
            pq.pop();
        }

        return solution;

    }
};
