#include <bits/stdc++.h>
using namespace std;

class OrderedStream {
public:
    OrderedStream(int n) {
        ptr = 1;
        mx = n;
        hash_map = vector<string>(n + 1);
    }

    vector<string> insert(int idKey, string value) {
        vector<string> ans;
        hash_map[idKey] = value;
        if (ptr == idKey) {
            while (ptr <= mx && !hash_map[ptr].empty()) {
                ans.push_back(hash_map[ptr++]);
            }
        }
        return ans;
    }

    int ptr, mx;
    vector<string> hash_map;
};

/**
 * Your OrderedStream object will be instantiated and called as such:
 * OrderedStream* obj = new OrderedStream(n);
 * vector<string> param_1 = obj->insert(idKey,value);
 */

int main() {

	return 0;
}