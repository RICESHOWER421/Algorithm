#include <vector>
#include <iostream>
using namespace std;

bool canMakeSquare(vector<vector<char>>& grid) {
    for (int i = 0; i < grid.size() - 1; i++) {
        for (int j = 0; j < grid[0].size() - 1; j++) {
            int num1 = 0, num2 = 0;
            if (grid[i][j] == 'W') ++num1;
            else ++num2;
            if (grid[i][j + 1] == 'W') ++num1;
            else ++num2;
            if (grid[i + 1][j] == 'W') ++num1;
            else ++num2;
            if (grid[i + 1][j + 1] == 'W') ++num1;
            else ++num2;

            if (num1 >= 3 || num2 >= 3) return true;
        }
    }
    return false;
}

int main() {

    return 0;
}