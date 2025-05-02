#include <bits/stdc++.h>
using namespace std;

//4 6 6
//5 5 8
class Solution {
public:
    int maxTaskAssign(vector<int>& tasks, vector<int>& workers, int pills, int strength) {
        sort(tasks.begin(), tasks.end());
        sort(workers.begin(), workers.end());
        int n = tasks.size(), m = workers.size();
        int l = 0, r = min(n, m);

        auto check = [&](int mid)->bool {
            int cur = 0,cnt = 0;   
            deque<int> a;  //存储待完成任务
            for (int i = m - mid; i < m; i++) {
                while (cur < mid && workers[i] + strength >= tasks[cur]) {
                    a.push_back(tasks[cur++]);
                }

                //假设这个工人理想情况一个任务都完不成
                if (a.empty()) {
                    return false;
                }
                //工人在不嗑药的情况下完成任务
                if (workers[i] >= a[0]) {
                    a.pop_front();
                    continue;
                }
                
                if (cnt == pills) {
                    return false;
                }
                ++cnt;
                a.pop_back();   //干不掉最小的，就嗑药干掉最大的
            }
            return true;
        };

        while (l < r) {
            int mid = l + (r - l + 1) / 2;
            if (check(mid)) {
                l = mid;
            }
            else {
                r = mid - 1;
            }
        }
        return l;
    }
};

int main() {
    vector<int> tasks = { 5,9,8,5,9 }, workers = { 1,6,4,2,6 };
    cout << Solution().maxTaskAssign(tasks, workers, 1, 5) << "\n";
	return 0;
}