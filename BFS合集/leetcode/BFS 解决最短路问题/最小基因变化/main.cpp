#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <unordered_set>
using namespace std;

int minMutation(string startGene, string endGene, vector<string>& bank) {
	unordered_set<string> vis; //判断字符串是否已经被访问过
	unordered_set<string> hash(bank.begin(), bank.end()); //将基因库里的所有字符串存储在哈希表中
	string str = "ACGT";

	//考虑边界情况,一种是起始基因就是最后要变成的基因，一种是bank中根本没有最后要变成的基因
	if (startGene == endGene) return 0;
	if (!hash.count(endGene)) return -1;

	queue <string> q;
	q.push(startGene);
	vis.insert(startGene);

	int ret = 0;
	while (q.size()) {
		++ret;
		int size = q.size();
		while (size--) {
			string s = q.front();
			q.pop();
			for (int i = 0; i < 8; i++) {
				string temp = s;
				for (int j = 0; j < 4; j++) {
					temp[i] = str[j];
					if (hash.count(temp) && !vis.count(temp)) {
						if (temp == endGene) return ret;
						q.push(temp);
						vis.insert(temp);
					}

				}
			}
		}
	}
	return -1;
}

int main() {
	string start = "AAAAACCC", end = "AACCCCCC";
	vector<string> bank = { "AAAACCCC","AAACCCCC","AACCCCCC" };
	cout << minMutation(start, end, bank) << endl;
	return 0;
}