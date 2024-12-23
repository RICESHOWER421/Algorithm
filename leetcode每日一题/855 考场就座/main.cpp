#include <bits/stdc++.h>
using namespace std;

class ExamRoom {
public:
    ExamRoom(int n) {
        this->n = n;
    }

    int seat() {
        if (nums.empty()) {
            nums.insert(0);
            return 0;
        }
        
        int left = -1, right = 0, mx = 0, ans = 0;
        if (*nums.begin()) mx = *nums.begin();
        for (auto i = nums.begin(); i != nums.end(); i++) {
            right = *i;
            if ((right - left) / 2 > mx) {
                mx = (right - left) / 2;
                ans = (right + left) / 2;
            }
            left = right;
        }

        if (right != n - 1) {
            if (mx < n - 1 - right) ans = n - 1;
        }
        nums.insert(ans);
        return ans;
    }

    void leave(int p) {
        nums.erase(p);
    }
    
    int n;
    set<int> nums;
};

int main() {

	return 0;
}