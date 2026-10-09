class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;

        for (int i = 0; i < tokens.size(); i++) {

            if (isdigit(tokens[i][0]) || tokens[i].size() > 1)  {

                st.push(stoi(tokens[i]));

            } else {
                int first = st.top();
                st.pop();

                int second = st.top();
                st.pop();

                int result;

                if (tokens[i] == "+") {
                    result = second + first;
                    st.push(result);
                } else if (tokens[i] == "-") {
                    result = second - first;
                    st.push(result);
                } else if (tokens[i] == "*") {
                    result = second * first;
                    st.push(result);
                } else {
                    result = second / first;
                    st.push(result);
                }
            }

        }

        return st.top();

    }
};
