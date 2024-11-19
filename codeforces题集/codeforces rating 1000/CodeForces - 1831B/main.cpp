#include <iostream>
#include <vector>
#include <map>
using namespace std;

void Test() {
	int n = 0;
	cin >> n;

	vector<int> nums1(n), nums2(n);
	for (int i = 0; i < n; i++) cin >> nums1[i];
	for (int i = 0; i < n; i++) cin >> nums2[i];
	
	vector<int> h1(2 * n + 1), h2(2 * n + 1);
	int left = 0, right = 0;
	while (right < n) {
		if (nums1[left] == nums1[right]) ++right;
		else {
			h1[nums1[left]] = max(right - left, h1[nums1[left]]);
			left = right;
		}
	}
	h1[nums1[left]] = max(right - left, h1[nums1[left]]);

	left = 0, right = 0;
	while (right < n) {
		if (nums2[left] == nums2[right]) ++right;
		else {
			h2[nums2[left]] = max(right - left, h2[nums2[left]]);
			left = right;
		}
	}
	h2[nums2[left]] = max(right - left, h2[nums2[left]]);

	int mx = 1;
	for(int i = 1; i <= 2 * n; i++) {
		mx = max(h1[i] + h2[i], mx);
	}
	cout << mx << "\n";
}

int main() {
	int test = 0;
	cin >> test;
	while (test--) {
		Test();
	}
	return 0;
}