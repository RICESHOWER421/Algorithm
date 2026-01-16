#include <iostream>
#include <vector>
using namespace std;

class StockSpanner {
public:
    vector<int> st, nums;
    StockSpanner() {

    }

    int next(int price) {
        int ans = 1, n = nums.size();
        nums.push_back(price);
        while (!st.empty() && price >= nums[st.back()]) st.pop_back();
        if (!st.empty()) ans += n - st.back() - 1;
        else ans = n + 1;
        st.push_back(n);
        return ans;
    }
};

int main() {
    StockSpanner s;
    cout << s.next(100) << "\n";
    cout << s.next(80) << "\n";
    cout << s.next(60) << "\n";
    cout << s.next(70) << "\n";
    cout << s.next(60) << "\n";
    cout << s.next(75) << "\n";
    cout << s.next(85) << "\n";
	return 0;
}