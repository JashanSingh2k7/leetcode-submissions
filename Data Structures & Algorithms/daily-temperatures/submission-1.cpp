class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temp) {
        // learn monotonic stack -> very important
        // [30, 38, 30, 36, 35, 40, 25]

        // pick 30
        // pick 

        // it is the case that they don't keep the value, they only keep the index
        // and just reference it from temperatures
        
        //if it keeps going into the stack it is getting smaller, I understand. 
        //38 30 36 35 40

        stack<int> st;
        vector<int> result(temp.size(), 0);

        for (int i = 0; i < temp.size(); i++) {

            // added into the stack
            if (st.empty()) {st.push(i);continue;}

            // only runs if it is bigger
            while(!st.empty() && temp[i] > temp[st.top()]) {

                // temp[i] is greater than the top of the stack
                result[st.top()] = i - st.top();
                st.pop();
            }

            st.push(i);

        }

        return result;

    }
};
