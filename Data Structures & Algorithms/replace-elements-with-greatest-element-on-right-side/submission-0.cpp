class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        for(int i = 0; i < arr.size();i++) {
            if (i == arr.size() - 1) {
                arr[i] = -1;
                continue;
            }

            int max1 = INT_MIN;
            for (int n = i + 1; n < arr.size(); n++) {
                max1 = max(arr[n], max1);
            }

            arr[i] = max1;
        }

        

        return arr;
    }

    
};