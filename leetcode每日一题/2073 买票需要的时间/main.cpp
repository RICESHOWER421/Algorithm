#include <iostream>
#include <queue>
#include <vector>
using namespace std;

class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        int ret = 0;
        queue<pair<int, int>> arr;
        for (int i = 0; i < (int)tickets.size(); i++) {
            pair<int, int> temp;
            temp.first = tickets[i];
            if (i == k) temp.second = 1;
            else temp.second = 0;

            arr.push(temp);
        }

        while (!arr.empty()) {
            pair<int, int> ans = arr.front();
            arr.pop();

            if (ans.first - 1) arr.push({ ans.first - 1, ans.second });
            else {
                if (ans.second == 1) return ret + 1;    //记住自己也要删除一次
            }
            ++ret;
        }
        return ret;
    }
};

int main() {
    vector<int> tickets = { 2,3,2 };
    int k = 2;
    Solution s;
    cout << s.timeRequiredToBuy(tickets, k) << endl;
	return 0;
}