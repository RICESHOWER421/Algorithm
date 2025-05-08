#include <bits/stdc++.h>
using namespace std;

class UnionFindSet {
public:
    UnionFindSet(size_t n)
        :_ufs(n, -1)
    {}

    void Union(int x1, int x2) {     //合并集合
        int r1 = FindRoot(x1), r2 = FindRoot(x2);
        if (r1 == r2) {
            return;
        }

        _ufs[r1] += _ufs[r2];
        _ufs[r2] = r1;
    }

    int FindRoot(int x) {
        while (_ufs[x] >= 0) {
            x = _ufs[x];
        }
        return x;
    }

    bool IsInset(int x1, int x2) {
        return FindRoot(x1) == FindRoot(x2);
    }

    size_t SetSize() {   //统计小集体个数
        size_t ans = 0;
        for (auto& x : _ufs) {
            if (x < 0) {
                ++ans;
            }
        }
        return ans;
    }
private:
    vector<int> _ufs;
};

class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        UnionFindSet ufs(isConnected.size());
        for (int i = 0; i < isConnected.size(); i++) {
            for (int j = 0; j < isConnected[i].size(); j++) {
                if (isConnected[i][j]) {
                    ufs.Union(i, j);
                }
            }
        }
        return ufs.SetSize();
    }
};

int main() {

	return 0;
}