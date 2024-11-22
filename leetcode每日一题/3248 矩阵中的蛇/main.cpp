#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int finalPositionOfSnake(int n, vector<string>& commands) {
        int begin = 0;
        for (int i = 0; i < commands.size(); i++) {
            if (commands[i] == "UP") begin -= n;
            else if (commands[i] == "DOWN") begin += n;
            else if (commands[i] == "LEFT") begin -= 1;
            else begin += 1;
        }
        return begin;
    }
};

int main() {

	return 0;
}