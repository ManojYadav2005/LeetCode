class Solution {
public:
    int trap(vector<int>& height) {

        int n = height.size();
        stack<int> st;   // stores indices
        int total = 0;

        for (int i = 0; i < n; i++) {

            // Current building is greater than stack top
            // So a valley is getting closed
            while (!st.empty() && height[i] > height[st.top()]) {

                int bottom = st.top();
                st.pop();

                // No left boundary
                if (st.empty())
                    break;

                int left = st.top();
                int right = i;

                // Width between left and right boundary
                int width = right - left - 1;

                // Height of water
                int waterHeight =
                    min(height[left], height[right])
                    - height[bottom];

                total += width * waterHeight;
            }

            st.push(i);
        }

        return total;
    }
};