#include <iostream>
#include <vector>
#include <queue>
#include <map>
using namespace std;

//方法一：大根堆
//vector<int> rearrangeBarcodes(vector<int>& barcodes) {
//	struct cmp { bool operator()(pair<int, int> a, pair<int, int> b) { return a.second < b.second; } };
//	priority_queue <pair<int, int>, vector<pair<int, int>>, cmp> q;
//	vector<int> ret;
//	vector<int> arr;
//	map<int, int> hash_map;
//	for (int i = 0; i < barcodes.size(); i++) {
//		if (!hash_map.count(barcodes[i])) arr.push_back(barcodes[i]);
//		hash_map[barcodes[i]]++;
//	}
//
//	for (int i = 0; i < arr.size(); i++) 
//		q.push({ arr[i], hash_map[arr[i]] });
//	
//	while (q.size() > 1) {
//		pair<int, int> first = q.top();
//		q.pop();
//		pair<int, int> second = q.top();
//		q.pop();
//		if (!ret.empty() && first.first == ret.back()) {
//			ret.push_back(second.first);
//			ret.push_back(first.first);
//		}
//		else {
//			ret.push_back(first.first);
//			ret.push_back(second.first);
//		}
//		if (first.second - 1 > 0) q.push({first.first, first.second - 1});
//		if (second.second - 1 > 0) q.push({second.first, second.second - 1});
//	}
//	if(!q.empty())ret.push_back(q.top().first);
//	return ret;
//}

//方法二：贪心
//贪心策略如下：
//首先我们找到出现次数最多的数字，先将他们以两者间隔一个空位的形式先放入数组中，然后将剩下的每种数字依次按照这种方式放入即可。
vector<int> rearrangeBarcodes(vector<int>& barcodes) {
	vector<int> ret(barcodes.size());
	vector<int> arr;
	map<int, int> hash_map;
	pair<int, int> max_time = {-1,-1};
	for (int i = 0; i < barcodes.size(); i++) {
		if (!hash_map.count(barcodes[i])) arr.push_back(barcodes[i]);
		hash_map[barcodes[i]]++;
		if (hash_map[barcodes[i]] > max_time.second) {
			max_time.first = barcodes[i];
			max_time.second = hash_map[barcodes[i]];
		}
	}

	int index = 0;
	while (max_time.second) {
		ret[index] = max_time.first;
		index += 2;
		max_time.second -= 1;
		if (index >= barcodes.size()) index = 1;
	}

	for (int i = 0; i < arr.size(); i++) {
		if (arr[i] != max_time.first) {
			while (hash_map[arr[i]]) {
				ret[index] = arr[i];
				index += 2;
				if (index >= barcodes.size()) index = 1;
				--hash_map[arr[i]];
			}
		}
	}
	return ret;
}

int main() {
	vector<int> barcodes = { 1,1,1,1,2,2,3,3 };
	vector<int> ans = rearrangeBarcodes(barcodes);
	for (int i = 0; i < ans.size(); i++) {
		cout << ans[i] << " ";
	}
	cout << endl;
	return 0;
}