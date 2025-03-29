#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestCycle(vector<int>& edges) {
        int n = edges.size(), ans = -1, ret = 0;
        vector<pair<bool, int>> vis(n);
        for (int i = 0; i < n; i++) {
            if (!vis[i].first) {
                ++ret;  //��ʾ�ڼ���
                int cur = i, l = 0, r = 0;
                bool ok = false;
                while (edges[cur] != -1) {
                    if (vis[cur].first && vis[cur].second == ret) {   //������ĵ��Ѿ������ʹ��������ڱ��ֱ����ʹ���˵��������·
                        ok = true;
                        break;
                    }
                    else if (vis[cur].first && vis[cur].second != ret) {  //������������֮ǰ���ʹ��ģ���ȫû�б�Ҫ�������ʣ�ֱ�ӽ���ѭ��
                        break;
                    }

                    vis[cur].first = true;
                    vis[cur].second = ret;
                    cur = edges[cur];
                    ++l;
                }

                if (ok) {
                    int tmp = cur;
                    cur = i;
                    while (cur != tmp) {
                        cur = edges[cur];
                        ++r;
                    }
                    ans = max(ans, l - r);
                }
            }
        }
        return ans;
    }
};

int main() {
    vector<int> nums = { -1,4,-1,2,0,4 };
    cout << Solution().longestCycle(nums) << "\n";
    /*for (int i = 1; i < 1e5; i++) {
        cout << i << ",";
    }
    cout << 0 << "\n";*/
	return 0;
}