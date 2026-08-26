class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        int n = arr.size();
        
        // The last element is always replaced by -1, 
        // so our initial "max to the right" is -1.
        int current_max = -1; 
        
        // Traverse the array from right to left
        for (int i = n - 1; i >= 0; i--) {
            int original_val = arr[i]; // Remember the current number
            
            arr[i] = current_max;      // Replace it with the biggest number seen to the right
            
            // Update the maximum for the next iteration
            current_max = max(current_max, original_val); 
        }
        
        return arr;
    }
};