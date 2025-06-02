#include <iostream>
#include <queue>
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

string alienOrder(vector<string>& words) {
	unordered_map<char, string> edges;    //存储有向图的边的情况
	unordered_map<char, int> nums;        //存储点的入度个数
	string return_str;

	//建立有向图
	for (auto& str : words) {
		for (auto ch : str) {
			nums[ch] = 0;
		}
	}

	for (int i = 0; i < words.size() - 1; i++) {
		for (int j = i + 1; j < words.size(); j++) {
			int ret = 0, temp = 0;  //temp是用于记录两者字符串是否相等或者出现两者字符串出现min(s.length, t.length) 字母都相同情况
			while (ret != words[i].size() && ret != words[j].size()) {
				if (words[i][ret] != words[j][ret]) {
					temp = 1;
					if (edges[words[i][ret]].find(words[j][ret]) == string::npos) //筛重
						edges[words[i][ret]].push_back(words[j][ret]);
					else break; //如果不成立者直接退出循环

					//如果哈希表中没有这个点的信息，则这个点需要标记一下
					if (!nums.count(words[i][ret])) nums[words[i][ret]] = 0;
					if (!nums.count(words[j][ret])) nums[words[j][ret]] = 1;
					else ++nums[words[j][ret]];
					break;     //找到一个不相等的就跳出循环
				}
				++ret;
			}
				
			//特殊情况
			if (!temp) {
				if (j - i != 1 && words[i] == words[j] && words[j] != words[j - 1]) return "";   //解决两个字符串相等但是不连续情况
				if (words[i].size() > words[j].size() && ret == words[j].size()) return "";    //解决出现两者字符串出现min(s.length, t.length) 字母都相同情况
			}
		}
	}

	//将入度为0的点放入队列
	queue <char>q;
	for (char ch = 'a'; ch <= 'z'; ch++)
		if (nums.count(ch) && nums[ch] == 0) q.push(ch);

	//进行拓扑排序
	while (q.size()) {
		char temp = q.front(); q.pop();
		return_str += temp;
		for (auto ch : edges[temp]) {
			--nums[ch];
			if (!nums[ch]) q.push(ch);
		}
	}

	//检查是否是有向无环图
	for (char ch = 'a'; ch < 'z'; ch++)
		if (nums.count(ch) && nums[ch]) return "";
	return return_str;
}

int main() {
	vector<string> words = { "wrt","wrtkj" };
	cout << alienOrder(words) << endl;
	return 0;
}
