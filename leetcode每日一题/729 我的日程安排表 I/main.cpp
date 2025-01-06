#include <bits/stdc++.h>
using namespace std;

class MyCalendar {
public:
    MyCalendar() {

    }

    bool book(int startTime, int endTime) {
        bool ok = true;
        for (auto& x : nums) {
            if (startTime >= x.first && startTime <= x.second || endTime - 1 >= x.first && endTime - 1 <= x.second || startTime <= x.first && endTime - 1 >= x.second) {
                ok = false;
                break;
            }
        }

        if (ok) {
            nums.push_back({startTime, endTime - 1});
            return true;
        }
        else {
            return false;
        }
    }

    vector<pair<int, int>> nums;
};


int main() {

	return 0;
}