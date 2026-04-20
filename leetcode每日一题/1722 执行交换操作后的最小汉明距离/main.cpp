#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

//并查集写法，稍微有些复杂
class UnionFindSet {
public:
    vector<set<int>> _f;
    UnionFindSet(size_t n)
        :_ufs(n, -1), _f(n)
    {
        for (int i = 0; i < n; i++) {
            _f[i].insert(i);
        }
    }

    void Union(int x1, int x2) {     //合并集合
        int r1 = FindRoot(x1), r2 = FindRoot(x2);
        if (r1 == r2) {
            return ;
        }

        if (_ufs[r1] > _ufs[r2]) {    //优化，将节点个数少的直接接入节点个数大的
            swap(r1, r2);
        }

        _ufs[r1] += _ufs[r2];
        _ufs[r2] = r1;
        _f[r1].insert(_f[r2].begin(), _f[r2].end());
        _f[r2].clear();
    }

    int FindRoot(int x) {
        int root = x;
        while (_ufs[root] >= 0) {
            root = _ufs[root];
        }

        //路径压缩
        while (_ufs[x] >= 0) {
            int parent = _ufs[x];
            _ufs[x] = root;
            x = parent;
        }
        return root;
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
    int minimumHammingDistance(vector<int>& source, vector<int>& target, vector<vector<int>>& allowedSwaps) {
        int n = source.size(), ans = 0;
        UnionFindSet ufs(n);
        unordered_map<int, int> cnt; //统计需要数的差值即可
        for (auto& x : allowedSwaps) {
            int n1 = x[0], n2 = x[1];
            ufs.Union(n1, n2);
        }

        //优先处理能进行交换的
        for (auto& x : ufs._f) {
            if (!x.empty()) {
                for (auto& idx : x) {
                    cnt[source[idx]]--;
                    cnt[target[idx]]++;
                }

                for (auto& x : cnt) {
                    ans += max(0, x.second);
                }
                cnt.clear();
            }
        }
        return ans;
    }
};

//写法二：建图 + dfs
class Solution {
public:
    int minimumHammingDistance(vector<int>& source, vector<int>& target, vector<vector<int>>& allowedSwaps) {
        int n = source.size(), ans = 0;
        vector<vector<int>> grid(n);
        vector<bool> vis(n);
        unordered_map<int, int> cnt; //统计需要数的差值即可
        for (auto& x : allowedSwaps) {
            int n1 = x[0], n2 = x[1];
            grid[n1].push_back(n2);
            grid[n2].push_back(n1);
        }

        auto dfs = [&](auto&& dfs, int i)->void{
            vis[i] = true;
            cnt[source[i]]--;
            cnt[target[i]]++;
            for (auto& x : grid[i]) {
                if (!vis[x]) {
                    vis[x] = true;
                    dfs(dfs, x);
                }
            }
        };

        for (int i = 0; i < n; i++) {
            if (!vis[i]) {
                dfs(dfs, i);
                for (auto& x : cnt) {
                    ans += max(0, x.second);
                }
                cnt.clear();
            }
        }
        return ans;
    }
};

int main() {
    vector<int> source = { 5,1,2,4,3 }, target = { 1,5,4,2,3 };
    vector<vector<int>> allow = { {0,4},{4,2},{1,3},{1,4} };
    cout << Solution().minimumHammingDistance(source, target, allow) << "\n";
	return 0;
}