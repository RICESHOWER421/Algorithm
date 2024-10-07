#include <iostream>
#include <map>
#include <vector>
using namespace std;

class SnapshotArray {
public:
    SnapshotArray(int length) {

    }

    void set(int index, int val) {
        hash_map[index].push_back({ ret, val });
    }

    int snap() {
        return ret++;
    }

    int get(int index, int snap_id) {
        if (hash_map[index].empty()) return 0;
        int left = 0, right = hash_map[index].size();
        while (left < right) {
            int mid = (left + right) / 2;
            if (hash_map[index][mid].first < snap_id + 1) left = mid + 1;
            else right = mid;
        }
        return left == 0 ? 0 : hash_map[index][left - 1].second;
    }

    int ret = 0;
    map<int, vector<pair<int, int>>> hash_map;
};

/**
 * Your SnapshotArray object will be instantiated and called as such:
 * SnapshotArray* obj = new SnapshotArray(length);
 * obj->set(index,val);
 * int param_2 = obj->snap();
 * int param_3 = obj->get(index,snap_id);
 */

int main() {
    SnapshotArray sa(1);
    sa.set(0, 15);
    sa.snap();
    sa.snap();
    sa.snap();
    cout << sa.get(0, 2) << endl;
	return 0;
}