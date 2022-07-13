class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> s{};
        vector<int> res{};

        for (int i = 0; i < asteroids.size(); ++ i) {
            int temp = asteroids[i];
            if (!s.empty()) {
                while (!s.empty() && temp < 0 && s.top() > 0) {
                    if (abs(temp) == abs(s.top())) {
                        s.pop();
                        temp = 0;
                    } else if (abs(temp) > abs(s.top())) {
                        s.pop();
                    } else {
                        temp = 0;
                    }
                }
            }
            if (temp != 0) s.push(temp);
        }

        while (!s.empty()) {
            res.push_back(s.top());
            s.pop();
        }

        reverse(res.begin(), res.end());
        return res;
    }
};

class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> res;

        for (auto& asteroid: asteroids) {
            bool flag = true;
            while (flag && asteroid < 0 && !res.empty() && res.back() > 0) {
                if (-asteroid > res.back()) {
                    res.pop_back();
                } else if (- asteroid == res.back()) {
                    res.pop_back();
                    flag = false;
                } else {
                    flag = false;
                }
            }
            if (flag == true) {
                res.push_back(asteroid);
            }
        }

        return res;
    }
};