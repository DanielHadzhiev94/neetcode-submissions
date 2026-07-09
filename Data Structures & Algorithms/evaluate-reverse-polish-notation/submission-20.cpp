class Solution {
   public:
    int evalRPN(vector<string>& tokens) {
        std::stack<int> numbers;
        for (const auto& token : tokens) {
            if (token == "+" || token == "-" || token == "*" || token == "/") {
                int right = numbers.top();
                numbers.pop();

                int left = numbers.top();
                numbers.pop();

                switch (token[0]) {
                    case '+':
                        numbers.push(left + right);
                        break;
                    case '-':
                        numbers.push(left - right);
                        break;
                    case '*':
                        numbers.push(left * right);
                        break;
                    case '/':
                        numbers.push(left / right);
                        break;
                }
            } else {
                numbers.push(stoi(token));
            }
        }
        return numbers.top();
    }
};
