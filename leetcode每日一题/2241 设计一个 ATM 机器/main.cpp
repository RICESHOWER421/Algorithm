#include <bits/stdc++.h>
using namespace std;

class ATM {
public:
    ATM() {
        count = vector<int>(5);
        money = { 20,50,100,200,500 };
    }

    void deposit(vector<int> banknotesCount) {
        for (int i = 0; i < banknotesCount.size(); i++) {
            count[i] += banknotesCount[i];
        }
    }

    vector<int> withdraw(int amount) {
        vector<int> tmp(5);
        int cur = 4;
        while (cur >= 0 && amount) {
            int ret = amount / money[cur];
            if (ret >= count[cur]) {
                amount -= count[cur] * money[cur];
                tmp[cur] = count[cur];
            }
            else {
                amount -= ret * money[cur];
                tmp[cur] = ret;
            }
            --cur;
        }

        if (amount){
            return { -1 };
        }
        else {
            for (int i = 0; i < 5; i++) {
                count[i] -= tmp[i];
            }
            return tmp;
        }
    }

    vector<int> count;
    vector<int> money;
};

int main() {
    ATM at;
    at.deposit({0,0,1,2,1});
    vector<int> ret1 = at.withdraw(600);
    for (auto& x : ret1) {
        cout << x << " ";
    }
    cout << "\n";
	return 0; 
}