#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

//思路和找到字符串中所有字母异位词类似
vector<int> findSubstring(string s, vector<string>& words) {
	int s_num = s.size(), words_num = words.size(), words_len = words[0].size();
	vector<int> return_nums;
	unordered_map<string, int> hash_1;
	for (auto& s : words) 
		++hash_1[s]; 

	for (int i = 0; i < words_len; i++) {
		int left = i, right = i, temp = 0;
		unordered_map<string, int> hash_2;
		while (right + words_len <= s_num) {
			string in_str = s.substr(right, words_len);
			if (hash_1.count(in_str) && hash_1[in_str] > hash_2[in_str]) {
				++hash_2[in_str];
				right += words_len;
				++temp;

				if (temp == words_num) 
					return_nums.push_back(left);
			}
			else {
				string out_str = s.substr(left, words_len);
				if (hash_1.count(out_str)) {
					--temp;
					--hash_2[out_str];
				}
				else {
					right += words_len;
				}
				left += words_len;
			}
		}
	}
	return return_nums;
}

int main() {
	string str = "barfoofoobarthefoobarman";
	vector<string> words = {"bar","foo","the"};
	vector<int> nums = findSubstring(str, words);
	for (int i = 0; i < nums.size(); i++) {
		cout << nums[i] << " ";
	}
	cout << endl;
	return 0;
}