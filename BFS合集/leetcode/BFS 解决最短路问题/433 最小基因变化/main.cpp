#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <unordered_set>
using namespace std;

int minMutation(string startGene, string endGene, vector<string>& bank) {
	unordered_set<string> vis; //�ж��ַ����Ƿ��Ѿ������ʹ�
	unordered_set<string> hash(bank.begin(), bank.end()); //���������������ַ����洢�ڹ�ϣ����
	string str = "ACGT";

	//���Ǳ߽����,һ������ʼ����������Ҫ��ɵĻ���һ����bank�и���û�����Ҫ��ɵĻ���
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