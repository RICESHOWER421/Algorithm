#include <bits/stdc++.h>
using namespace std;

//并查集
class UnionFindSet
{
public:
    int cnt;
    UnionFindSet(size_t n)
        :_ufs(n, -1), cnt(n)
    {}

    bool Union(int x1, int x2)
    { // 合并集合
        int r1 = FindRoot(x1), r2 = FindRoot(x2);
        if (r1 == r2) {
            return false;
        }

        if (_ufs[r1] > _ufs[r2]) { // 优化，将节点个数少的直接接入节点个数大的
            swap(r1, r2);
        }

        _ufs[r1] += _ufs[r2];
        _ufs[r2] = r1;
        --cnt;  //成功合并的话连通块数量-1
        return true;
    }

    int FindRoot(int x) {
        int root = x;
        while (_ufs[root] >= 0)
        {
            root = _ufs[root];
        }

        // 路径压缩：在执行查找操作时，将查找路径上的每个节点直接连接到根节点，从而减少树的高度
        while (_ufs[x] >= 0)
        {
            int parent = _ufs[x];
            _ufs[x] = root;
            x = parent;
        }
        return root;
    }
private:
    vector<int> _ufs;
};

//二分答案 最小值最大
class Solution {
public:
    int maxStability(int n, vector<vector<int>>& edges, int k) {
        UnionFindSet must_ufs(n), all_ufs(n);   //必选边的并查集以及整个图的并查集
        int mx = -1, mn = INT_MAX;
        for (auto& x : edges) {
            int u = x[0], v = x[1], s = x[2], must = x[3];
            if (must && !must_ufs.Union(u, v)) {     //必选边存在环
                return -1;
            }
            all_ufs.Union(u, v);
            mx = max(mx, s);
            mn = min(mn, s);
        }

        if (all_ufs.cnt > 1) {    //图不连通,故一定不存在最小生成树
            return -1;
        }

        auto check = [&](int mid) -> bool {
            UnionFindSet ufs(n);
            //首先处理必选边以及没有升级就满足要求的边
            for (auto& x : edges) {
                int u = x[0], v = x[1], s = x[2], must = x[3];
                if (must && s < mid) {    //必选边比二分答案还要小，不满足要求
                    return false;
                }
                if (must || s >= mid) {   //该边是必选边或者该边权值比二分答案要大，满足要求
                    ufs.Union(u, v);
                }
            }

            //第二遍，处理可以通过升级就达到要求的边
            int left_k = k; //剩余可升级次数
            for (auto& x : edges) {
                if (!left_k || ufs.cnt == 1) {    //连通图成立或者升级次数用完，直接退出循环
                    break;
                }
                int u = x[0], v = x[1], s = x[2], must = x[3];
                if (!must && s < mid && s * 2 >= mid && ufs.Union(u, v)) { //该边不是必选边且选择不构成环路且升级后满足要求
                    --left_k;
                }
            }
            return ufs.cnt == 1;    //构成最小生成树
        };
        int l = mn, r = mx * 2;
        while (l < r) {
            int mid = l + (r - l + 1) / 2;
            if (check(mid)) {
                l = mid;
            }
            else {
                r = mid - 1;
            }
        }
        return l;
    }
};


int main() {

	return 0;
}