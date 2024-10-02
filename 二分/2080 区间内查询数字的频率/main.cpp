#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

class RangeFreqQuery {
public:
    int Binary_Search(vector<int>& arr, int num) {
        int left = 0, right = arr.size();
        while (left < right) {
            int mid = (left + right) / 2;
            if (arr[mid] < num) left = mid + 1;
            else right = mid;
        }
        return left;
    }

    RangeFreqQuery(vector<int>& arr) {
        for (int i = 0; i < (int)arr.size(); i++) {
            hash_map[arr[i]].push_back(i);
        }
    }

    int query(int left, int right, int value) {
        int left_index = Binary_Search(hash_map[value], left);
        int right_index = Binary_Search(hash_map[value], right + 1);
        return right_index - left_index;
    }

    map<int, vector<int>> hash_map;
};

int main() {
    vector<int> arr = { 12, 33, 4, 56, 22, 2, 34, 33, 22, 12, 34, 56 };
    RangeFreqQuery s(arr);
    cout << s.query(1, 2, 4) << endl;
    cout << s.query(0, 11, 33) << endl;
	return 0;
}