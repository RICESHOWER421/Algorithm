#include <iostream>
#include <string>
using namespace std;

//1 1 1 0
//0 0 0 0
//1 0 1 1
//0 1 1 1
//���1Ҫ���0������Ҫ������Ҫ�ı������1����ƥ��
//���0Ҫ���1������Ҫ������Ҫ�ı������1����ƥ��
//001
//110
class Solution {
public:
    bool makeStringsEqual(string s, string target) {
        bool ok1 = false, ok2 = false;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '1' && target[i] == '1') return true;
            if (s[i] == '0' && target[i] == '1') ok1 = true;
            if (s[i] == '1') ok2 = true;
            if (ok1 && ok2) return true;
        }
        return false;
    }
};

int main() {

	return 0;
}