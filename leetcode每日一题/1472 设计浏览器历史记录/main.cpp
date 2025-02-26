#include <bits/stdc++.h>
using namespace std;

class BrowserHistory {
public:
    BrowserHistory(string homepage) {
        str.push_back(homepage);
        cur = 0;
    }

    void visit(string url) {
        int tmp = str.size() - 1;
        while (tmp != cur) {
            str.pop_back();
            --tmp;
        }
        str.push_back(url);
        ++cur;
    }

    string back(int steps) {
        if (cur - steps >= 0) {
            cur -= steps;
        }
        else {
            cur = 0;
        }
        return str[cur];
    }

    string forward(int steps) {
        if (cur + steps < str.size()) {
            cur += steps;
        }
        else {
            cur = str.size() - 1;
        }
        return str[cur];
    }
private:
    map<string, int> hash_map;
    vector<string> str;
    int cur;
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */

int main() {

	return 0;
}