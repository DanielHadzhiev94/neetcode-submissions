class Solution {
   public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        std::vector<int> result;
        int n = temperatures.size() - 1;

        for (int i = 0; i < n; ++i) {
            bool warmer = false;
            int counter = 0;
            int it = i + 1;

            while (it <= n) {
                ++counter;

                if (temperatures[it] > temperatures[i]) {
                    warmer = true;
                    break;
                }

                ++it;
            }

            if (warmer) {
                result.push_back(counter);
            } else {
                result.push_back(0);
            }
        }
        result.push_back(0);

        return result;
    }
};
