#include <iostream>
#include <string>
using namespace std;

//时间复杂度和空间复杂度都为O(N)
//bool backspaceCompare(string s, string t) {
//    string s1, t1;
//    for (int i = 0; i < s.size(); i++) {
//        if (s[i] != '#') s1 += s[i];
//        else {
//            if (s1.size()) s1.pop_back();
//        }
//    }
//    for (int i = 0; i < t.size(); i++) {
//        if (t[i] != '#') t1 += t[i];
//        else {
//            if (t1.size()) t1.pop_back();
//        }
//    }
//
//    return s1 == t1;
//}

//时间复杂度为O(N)，空间复杂度为O(1)写法
bool backspaceCompare(string s, string t) {
	int index_1 = 0;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] == '#') {
			if(index_1 > 0)--index_1;
		} 
		else {
			s[index_1] = s[i];
			++index_1;
		}
	}
	
	int index_2 = 0;
	for (int i = 0; i < t.size(); i++) {
		if (t[i] == '#') {
			if(index_2 > 0)--index_2;
		} 
		else {
			t[index_2] = t[i];
			++index_2;
		}
	}
	return s.substr(0, index_1) == t.substr(0, index_2);
}
int main() {
	string s = "y#fo##f";
	string t = "y#f#o##f";
	cout << backspaceCompare(s, t) << endl;
	return 0;
}