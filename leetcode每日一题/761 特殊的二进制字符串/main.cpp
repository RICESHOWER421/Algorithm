#include <bits/stdc++.h>
using namespace std;

//将题目类比于合法括号匹配，以'1'设为左括号，'0'设为右括号
class Solution {
public:
    string makeLargestSpecial(string s) {
		if (s.size() <= 2) return s;

		vector<string> ret;
		int c1 = 0, c2 = 0;	//c1存储左括号数量，c2为下一个嵌套字串的位置
		for (int i = 0; i < (int)s.size(); i++) {
			if (s[i] == '1') ++c1;		//左括号+1
			else if (--c1 == 0) {		//此时处于嵌套状态，里面的字串进行排序  嵌套状态举例：(()())
				ret.push_back("1" + makeLargestSpecial(s.substr(c2 + 1, i - c2 - 1)) + "0");	//去掉最外侧括号进行嵌套循环，嵌套里重新排序
				c2 = i + 1;
			}
		}

		sort(ret.begin(), ret.end(), greater<string>());
		string ans;		
		for (auto& x : ret) ans += x;	//拼接最后答案
		return ans;
    }
};

int main() {

	return 0;
}