class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        int n = arr.size();
        int current_max = -1; 
        
        for (int i = n - 1; i >= 0; i--) {
            int original_val = arr[i];
            
            arr[i] = current_max;      
            
            current_max = max(current_max, original_val); 
        }
        
        return arr;
    }
};