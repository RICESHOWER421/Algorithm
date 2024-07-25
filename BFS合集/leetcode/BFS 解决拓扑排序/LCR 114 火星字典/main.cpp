#include <iostream>
#include <queue>
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

string alienOrder(vector<string>& words) {
	unordered_map<char, string> edges;    //�洢����ͼ�ıߵ����
	unordered_map<char, int> nums;        //�洢�����ȸ���
	string return_str;

	//��������ͼ
	for (auto& str : words) {
		for (auto ch : str) {
			nums[ch] = 0;
		}
	}

	for (int i = 0; i < words.size() - 1; i++) {
		for (int j = i + 1; j < words.size(); j++) {
			int ret = 0, temp = 0;  //temp�����ڼ�¼�����ַ����Ƿ���Ȼ��߳��������ַ�������min(s.length, t.length) ��ĸ����ͬ���
			while (ret != words[i].size() && ret != words[j].size()) {
				if (words[i][ret] != words[j][ret]) {
					temp = 1;
					if (edges[words[i][ret]].find(words[j][ret]) == string::npos) //ɸ��
						edges[words[i][ret]].push_back(words[j][ret]);
					else break; //�����������ֱ���˳�ѭ��

					//�����ϣ����û����������Ϣ�����������Ҫ���һ��
					if (!nums.count(words[i][ret])) nums[words[i][ret]] = 0;
					if (!nums.count(words[j][ret])) nums[words[j][ret]] = 1;
					else ++nums[words[j][ret]];
					break;     //�ҵ�һ������ȵľ�����ѭ��
				}
				++ret;
			}
				
			//�������
			if (!temp) {
				if (j - i != 1 && words[i] == words[j] && words[j] != words[j - 1]) return "";   //��������ַ�����ȵ��ǲ��������
				if (words[i].size() > words[j].size() && ret == words[j].size()) return "";    //������������ַ�������min(s.length, t.length) ��ĸ����ͬ���
			}
		}
	}

	//�����Ϊ0�ĵ�������
	queue <char>q;
	for (char ch = 'a'; ch <= 'z'; ch++)
		if (nums.count(ch) && nums[ch] == 0) q.push(ch);

	//������������
	while (q.size()) {
		char temp = q.front(); q.pop();
		return_str += temp;
		for (auto ch : edges[temp]) {
			--nums[ch];
			if (!nums[ch]) q.push(ch);
		}
	}

	//����Ƿ��������޻�ͼ
	for (char ch = 'a'; ch < 'z'; ch++)
		if (nums.count(ch) && nums[ch]) return "";
	return return_str;
}

int main() {
	vector<string> words = { "wrt","wrtkj" };
	cout << alienOrder(words) << endl;
	return 0;
}
