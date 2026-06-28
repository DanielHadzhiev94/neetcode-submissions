class Solution {
   public:
    string encode(vector<string>& strs) {
        std::string encoded_str;

        for (auto& str : strs) {
            encoded_str += str + "_r_";
        }

        return encoded_str;
    }

    vector<string> decode(string s) {
        std::string helper_str;
        vector<string> decoded_lst;

        for (size_t i = 0; i < s.length(); ++i) {
            if (s[i] == '_' && s[i + 1] == 'r' && s[i + 2] == '_') {
                decoded_lst.push_back(helper_str);
                helper_str = "";
                i+=2;
            } else {
                helper_str += s[i];
            }
        }

        return decoded_lst;
    }
};
