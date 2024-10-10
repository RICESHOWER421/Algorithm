#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& asteroids) {
        sort(asteroids.begin(), asteroids.end());
        long long sum = mass;
        for (auto& x : asteroids) {
            if (sum >= x) sum += x;
            else return false;
        }
        return true;
    }
};

int main() {

	return 0;
}