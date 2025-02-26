#include <bits/stdc++.h>
using namespace std;
class Allocator {
public:
    Allocator(int n) {
        nums = vector<int>(n);
    }

    int allocate(int size, int mID) {
        int cnt = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 0) {
                ++cnt;
            }
            else {
                cnt = 0;
            }

            if (cnt == size) {
                for (int j = i - size + 1; j <= i; j++) {
                    nums[j] = mID;
                }
                return i - size + 1;
            }
        }
        return -1;
    }

    int freeMemory(int mID) {
        int cnt = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == mID) {
                nums[i] = 0;
                ++cnt;
            }
        }
        return cnt;
    }
private:
    vector<int> nums;
};

/**
 * Your Allocator object will be instantiated and called as such:
 * Allocator* obj = new Allocator(n);
 * int param_1 = obj->allocate(size,mID);
 * int param_2 = obj->freeMemory(mID);
 */

int main() {
    Allocator a(5);
    cout << a.allocate(1,1) << "\n";
	return 0;
}