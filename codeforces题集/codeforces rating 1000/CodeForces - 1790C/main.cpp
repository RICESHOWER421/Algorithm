#include <iostream>
#include <vector>
#include <map>
using namespace std;

void Test() {
	int n = 0;
	cin >> n;

	vector<vector<int>> arr(n, vector<int>(n - 1));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n - 1; j++) {
			cin >> arr[i][j];
		}
	}
	
	map<int, int> hash_map;
	vector<int> nums;
	for (int i = 0; i < n; i++) {
		if (!hash_map.count(arr[i][0])) nums.push_back(arr[i][0]);
		hash_map[arr[i][0]]++;
	}
	if (hash_map[nums[0]] < hash_map[nums[1]]) cout << nums[1] << " " << nums[0] << " ";
	else cout << nums[0] << " " << nums[1] << " ";

	for (int i = 1; i < n - 1; i++) {
		for (int j = 0; j < n; j++) {
			if (!hash_map.count(arr[j][i])) {
				cout << arr[j][i] << " ";
				hash_map[arr[j][i]] = 1;
				break;
			}
		}
	}
	cout << "\n";
}
int main() {
	int test = 0;
	cin >> test;
	while (test--) {
		Test();
	}
	return 0;
}