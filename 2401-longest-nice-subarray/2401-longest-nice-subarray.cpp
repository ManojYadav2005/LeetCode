class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {

        int n = nums.size();
        int ans = 1;

        for(int i = 0; i < n; i++)
        {
            for(int j = i; j < n; j++)
            {
                bool nice = true;

                // Check nums[j] with all previous elements
                for(int k = i; k < j; k++)
                {
                    if((nums[k] & nums[j]) != 0)
                    {
                        nice = false;
                        break;
                    }
                }

                if(nice)
                    ans = max(ans, j - i + 1);
                else
                    break;      // Aage bhi nice nahi banega
            }
        }

        return ans;
    }
};