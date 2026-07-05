
class Solution {
   public:
    bool isPalindrome(string s) {
        std::vector<char> text;

        for (char c : s) {
            if (std::isalnum(c)) {
                text.push_back(std::tolower(c));
            }
        }

        int n = text.size();

        // if (n % 2 != 0) {
        //     return false;
        // }

        int it = 0;
        while (it < n / 2) {
            if (text[it] != text[n - it - 1]) {
                return false;
            }
            ++it;
        }

        return true;
    }
};
