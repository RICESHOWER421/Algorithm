#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string answerString(string word, int numFriends) {
        if (numFriends == 1) return word;
        int n = word.size();
        int mx = n - numFriends + 1;
        string ans = word.substr(0, mx);
        for (int i = 1; i < n; i++) {
            ans = max(ans, word.substr(i, mx));
        }
        return ans;
    }
};

int main() {
    string word = "dqwjdoinjdiosanoifdjqwiodjiosajdioashjfiohdsoifoiefhiohiohdiohqwoihdioasndionwqidsaoibnhfoiaheo";
    cout << Solution().answerString(word, 18) << "\n";
    return 0;
}