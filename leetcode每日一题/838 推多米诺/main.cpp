#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string pushDominoes(string dominoes) {
        int n = dominoes.size(), l = n - 1, r = n - 1;
        while (l >= 0) {
            if (dominoes[l] == 'R') {
                while (l != r) {
                    dominoes[r--] = 'R';
                }
            }
            else if (dominoes[l] == 'L') {
                r = l;
                while (l >= 0 && dominoes[l] != 'R') {
                    if (dominoes[l] == 'L') {
                        r = l;
                    }
                    else if (dominoes[l] == '.') {
                        dominoes[l] = 'L';
                    }
                    --l;
                }
                if (l == -1) {
                    for (int i = 0; i < r; i++) {
                        dominoes[i] = 'L';
                    }
                }
                else {
                    int tmp = l;
                    while (tmp < r) {
                        dominoes[tmp++] = 'R';
                        dominoes[r--] = 'L';
                    }
                    if (tmp == r) {
                        dominoes[r] = '.';
                    }
                }
                r = l;
            }
            --l;
        }
        return dominoes;
    }
};

int main() {

	return 0;
}