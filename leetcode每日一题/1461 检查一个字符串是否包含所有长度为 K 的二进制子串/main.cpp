#include <bits/stdc++.h>
#include <unordered_set>
using namespace std;

//class Solution {
//public:
//    bool hasAllCodes(string s, int k) {
//        int n = s.size();
//        if (n < k) return false;
//
//        unordered_set<int> st;
//        for (int i = 0; i <= n - k; i++) {
//            string tmp = s.substr(i, k);
//            int num = 0, cur = k - 1, cnt = 0;
//            while (cur >= 0) {
//                num += (tmp[cur--] - '0') * pow(2, cnt++);
//            }
//            st.insert(num);
//        }
//        
//        if (st.size() < pow(2, k)) return false;
//        bool ok = true;
//        for (int i = 0; i < pow(2, k); i++) {
//            if (st.find(i) == st.end()) {
//                ok = false;
//                break;
//            }
//        }
//        return ok;
//    }
//};

//速度稍微快一点
//bool nums[3000000];
//class Solution {
//public:
//    bool hasAllCodes(string s, int k) {
//        int n = s.size();
//        if (n < k) return false;
//        memset(nums, 0, sizeof(nums));
//        for (int i = 0; i <= n - k; i++) {
//            string tmp = s.substr(i, k);
//            int num = 0, cur = k - 1, cnt = 0;
//            while (cur >= 0) {
//                num += (tmp[cur--] - '0') * pow(2, cnt++);
//            }
//            nums[num] = true;
//        }
//
//        bool ok = true;
//        for (int i = 0; i < pow(2, k); i++) {
//            if (!nums[i]) {
//                ok = false;
//                break;
//            }
//        }
//        return ok;
//    }
//};

//直接看大小就可以
class Solution {
public:
    bool hasAllCodes(string s, int k) {
        unordered_set<string> st;
        int n = s.size();
        for (int i = 0; i <= n - k; i++) {
            st.insert(s.substr(i, k));
        }
        return st.size() == (1 << k);
    }
};

int main() {
    string s = "0110";
    int k = 2;
    cout << Solution().hasAllCodes(s, k) << "\n";
	return 0;
}