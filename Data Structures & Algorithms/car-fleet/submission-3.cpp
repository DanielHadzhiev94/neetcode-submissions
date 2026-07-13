class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {

        vector<pair<int, int>> cars;

        for (int i = 0; i < position.size(); i++) {
            cars.emplace_back(position[i], speed[i]);
        }

        sort(cars.begin(), cars.end(),
             [](const auto& a, const auto& b) {
                 return a.first > b.first;
             });

        stack<double> fleets;

        for (auto& car : cars) {

            double time = static_cast<double>(target - car.first) / car.second;

            if (fleets.empty() || time > fleets.top()) {
                fleets.push(time);
            }
        }

        return fleets.size();
    }
};