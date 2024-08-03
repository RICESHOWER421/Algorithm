#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <cmath>
using namespace std;

int maxPointsInsideSquare(vector<vector<int>>& points, string s) {
	vector<pair<char, int>> arr;
	for (int i = 0; i < points.size(); i++) 
		arr.push_back({ s[i], {max(abs(points[i][0]),abs(points[i][1]))}});
	
	sort(arr.begin(), arr.end(), [](const pair<char, int>& s1, const pair<char, int>& s2) {
		return s1.second < s2.second;
	});

	int ret = 0;
	int sum = 0;
	int index = 0;
	map<char, int> hash_map;
	int a = arr[0].second;
	for (int i = 0; i < points.size(); i++) {
		if (arr[i].second != a) {
			ret += sum;
			sum = 0;
			a = arr[i].second;
		}

		if (arr[i].second == a && !hash_map.count(arr[i].first)) {
			++sum;
			hash_map[arr[i].first] = 1;
		}
		else {
			index = 1;
			break;
		}
	}
	return ret + (index == 0 ? sum : 0);
}

int main() {

	return 0;
}