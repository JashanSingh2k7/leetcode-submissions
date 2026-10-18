class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<pair<int, int>> st;

        st.push({temperatures[0], 0});

        vector<int> result(temperatures.size(), 0);

        for (int i = 1; i < temperatures.size(); i++) {

            while (!st.empty() && st.top().first < temperatures[i]) {
                result[st.top().second] = i - st.top().second;
                st.pop();
            }

            st.push({temperatures[i], i});
        }

        return result;

    }
};
