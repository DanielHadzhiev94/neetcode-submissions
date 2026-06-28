class Solution {
   public:
    vector<int> productExceptSelf(vector<int>& nums) {
        std::vector<int> result;
        int i = 0;


        while (i < nums.size()) {
            int j = 0;
            int sum = 1;

            while (j < nums.size()) {
                if (j == i) {
                    ++j;
                }

                if (j != nums.size()) {
                    sum *= nums[j];
                }

                ++j;
            }
            result.push_back(sum);
            j = i;
            ++i;
        }

        return result;
    }
};
