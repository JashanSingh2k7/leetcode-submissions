class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(), people.end());

        int right = people.size() - 1;
        int left = 0;
        int count = 0;
        

        while(right > left) {
            if (people[right] + people[left] > limit) {
                right--;
                count++;
            }
            else if (people[right] + people[left] <= limit) {
                right--;
                left++;
                count++;
            }
        }

        if (right == left){
            count++;
        }

        return count;
    }
};