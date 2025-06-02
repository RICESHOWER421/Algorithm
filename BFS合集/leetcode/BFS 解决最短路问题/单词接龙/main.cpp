#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <unordered_set>
using namespace std;

int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
	unordered_set<string> vis; //�Ѿ����������ַ���
	unordered_set<string> hash(wordList.begin(), wordList.end()); //���ֵ�����ĵ��ʷ����ϣ��
	int len = beginWord.size();

	//�жϱ�Ե����
	if (!hash.count(endWord)) return 0;

	queue<string> q;
	q.push(beginWord);
	vis.insert(beginWord);
	
	int ret = 1;
	while (q.size()) {
		++ret;
		int size = q.size();
		while (size--) {
			string s = q.front();
			q.pop();
			for (int i = 0; i < len; i++) {
				string temp = s;
				for (int j = 0; j < 26; j++) {
					temp[i] = j + 97;
					if (hash.count(temp) && !vis.count(temp)) {
						if (temp == endWord) return ret;
						q.push(temp);
						vis.insert(temp);
					}
				}
			}
		}
	}
	return 0;
}

int main() {
	string beginWord = "hit", endWord = "cog";
	vector<string> wordList = { "hot","dot","dog","lot","log","cog" };
	cout << ladderLength(beginWord, endWord, wordList) << endl;
	return 0;
}