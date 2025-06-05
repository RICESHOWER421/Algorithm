#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

class Solution {
public:
	string smallestEquivalentString(string s1, string s2, string baseStr) {
		int n = s1.size();
		vector<int> rets(26, -1);
		for (int i = 0; i < n; i++) {
			int p1 = s1[i] - 'a', p2 = s2[i] - 'a';
			while (rets[p1] >= 0) p1 = rets[p1];
			while (rets[p2] >= 0) p2 = rets[p2];
			if (p1 != p2) {
				rets[p1] += rets[p2];
				rets[p2] = p1;
			}
		}

		/*for (auto& x : rets) {
			cout << x << " ";
		}
		cout << "\n";*/

		vector<char> cnts(26);
		for (int i = 0; i < 26; i++) cnts[i] = (i + 'a');
		for (int i = 0; i < 26; i++) {
			if (rets[i] >= 0) {
				int pos = i;
				char tmp = (char)(i + 'a');
				while (rets[pos] >= 0) {
					tmp = min(tmp, (char)(pos + 'a'));
					pos = rets[pos];
				}
				cnts[pos] = min(cnts[pos], tmp);
			}
		}
		/*for (auto& x : cnts) {
			cout << x << " ";
		}
		cout << "\n";*/

		string tmp;
		for (auto& x : baseStr) {
			int pos = x - 'a';
			while (rets[pos] >= 0) pos = rets[pos];
			tmp += cnts[pos];
		}
		return tmp;
	}
};

int main()
{
	string s1 = "hello", s2 = "world", base = "hold";
	cout << Solution().smallestEquivalentString(s1, s2, base) << "\n";
	return 0;
}