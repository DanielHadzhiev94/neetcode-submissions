class Solution {
   public:
    int evalRPN(vector<string>& tokens) {
        std::stack<int> numbers;
        std::unordered_map<string, int> operators{{"+", 1}, {"-", 2}, {"*", 3}, {"/", 4}};

        for (auto token : tokens) {
            auto it = operators.find(token);
            if (it == operators.end()) {
                numbers.push(stoi(token));
            } else {
                if (numbers.size() <= 1) {
                    continue;
                }

                int sum = 0;

                // if(it->second == 3){
                //     sum = 1;
                // }

                int num = numbers.top();
                numbers.pop();

                int num2 = numbers.top();
                numbers.pop();

                  std::cout << num << "\n";
                    std::cout << num2 << "\n";

                switch (it->second) {
                    case 1:
                        sum = num + num2;
                        break;
                    case 2:
                        sum = num2 - num;
                        break;
                    case 3:
                        sum = num * num2;
                        break;
                    case 4:
                        sum = num2 / num;
                        break;
                }

                //std::cout << sum << "\n";

                numbers.push(sum);
            }
        }

        return numbers.top();
    }
};
