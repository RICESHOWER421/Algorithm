#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    string smallestNumber(string pattern) {
        string ans;
        char begin = '1';
        int cur = 0;
        while (cur < pattern.size()) {
            if (pattern[cur] == 'I') {
                ans += begin;
                ++cur;
                ++begin;
            }
            else {
                int temp = cur;
                while (pattern[cur] == 'D' && cur < pattern.size()) {
                    ++begin;
                    ++cur;
                }

                for (int i = 0; i <= cur - temp; i++) {
                    ans += (begin - i);
                }
                ++cur;
                ++begin;
            }
        }
        return ans.size() == pattern.size() + 1? ans : ans + begin;
    }
};

int main() {
    string pattern = "DDDIII";
    cout << Solution().smallestNumber(pattern) << "\n";
    return 0;
}