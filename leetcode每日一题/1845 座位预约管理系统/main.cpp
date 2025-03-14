#include <iostream>
#include <queue>
using namespace std;

class SeatManager {
public:
    SeatManager(int n) {
        for (int i = 1; i <= n; i++) {
            pq.push(i);
        }
    }

    int reserve() {
        int num = pq.top();
        pq.pop();
        return num;
    }

    void unreserve(int seatNumber) {
        pq.push(seatNumber);
    }

    priority_queue<int, vector<int>, greater<int>> pq;
    int* nums;
};

/**
 * Your SeatManager object will be instantiated and called as such:
 * SeatManager* obj = new SeatManager(n);
 * int param_1 = obj->reserve();
 * obj->unreserve(seatNumber);
 */

int main() {

	return 0;
}
