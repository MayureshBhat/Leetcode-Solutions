class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        int n = nums.size();
        if (n < 3) return false;

        stack<int> st;
        int two = INT_MIN;  // candidate for "2"

        // Traverse from right to left
        for (int i = n - 1; i >= 0; i--) {

            // nums[i] can be "1"
            if (nums[i] < two) {
                return true;
            }

            // Find a value that can be "2"
            while (!st.empty() && nums[i] > st.top()) {
                two = st.top();
                st.pop();
            }

            st.push(nums[i]);
        }

        return false;
    }
};
