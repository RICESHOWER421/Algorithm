#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumDeletions(string s) {
        int n = s.size();
        int t1 = 0, t2 = 0, r1 = 0, r2 = 0;     //1表示a结尾，2表示b结尾（平衡所需要的最少删除次数）
        for (int i = 0; i < n; i++) {
            if (s[i] == 'a') {
                r1 = t1;
                r2 = t2 + 1;
            }
            else {
                r2 = min(t1, t2);
                r1 = t1 + 1;
            }
            t1 = r1;
            t2 = r2;
        }
        return min(t1, t2);
    }
};

//abbaaabaabababaa
int main() {

	return 0;
}