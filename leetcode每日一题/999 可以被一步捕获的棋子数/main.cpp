#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int numRookCaptures(vector<vector<char>>& board) {
        int ans = 0;
        for (int i = 0; i < 8; i++) {
            for (int j = 0; j < 8; j++) {
                if (board[i][j] == 'R') {
                    for (int k = i - 1; k >= 0; k--) {
                        if (board[k][j] != '.') {
                            if (board[k][j] == 'p') {
                                ++ans;
                            }
                            break;
                        }
                    }

                    for (int k = i + 1; k < 8; k++) {
                        if (board[k][j] != '.') {
                            if (board[k][j] == 'p') {
                                ++ans;
                            }
                            break;
                        }
                    }

                    for (int k = j - 1; k >= 0; k--) {
                        if (board[i][k] != '.') {
                            if (board[i][k] == 'p') {
                                ++ans;
                            }
                            break;
                        }
                    }

                    for (int k = j + 1; k < 8; k++) {
                        if (board[i][k] != '.') {
                            if (board[i][k] == 'p') {
                                ++ans;
                            }
                            break;
                        }
                    }
                    return ans;
                }
            }
        }
        return ans;
    }
};

int main() {

	return 0;
}