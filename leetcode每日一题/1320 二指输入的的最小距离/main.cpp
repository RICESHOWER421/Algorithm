#include <bits/stdc++.h>
using namespace std;

//class Solution {
//    unordered_map<char, pair<int, int>> hash_map;
//    void Init() {
//        char alpha = 'A';
//        bool ok = false;
//        for (int i = 0; i < 5; i++) {
//            for (int j = 0; j < 6; j++) {
//                hash_map[alpha++] = { i,j };
//                if (alpha > 'Z') {
//                    ok = true;
//                    break;
//                }
//            }
//            if (ok) break;
//        }
//    }
//
//    int len(char a, char b) {
//        return abs(hash_map[a].first - hash_map[b].first) + abs(hash_map[a].second - hash_map[b].second);
//    }
//public:
//    int minimumDistance(string word) {
//        Init();
//        int n = word.size();
//        //memo[i][j][k]表示手指1在j的位置，手指2在k的位置，输入word的前缀[0,i]的最小移动距离
//        vector<vector<vector<int>>> memo(n, vector<vector<int>>(26, vector<int>(26, -1)));
//
//        auto dfs = [&](auto&& dfs, int i, char finger1, char finger2)->int {
//            if (i < 0) return 0;
//
//            auto& x = memo[i][finger1 - 'A'][finger2 - 'A'];
//            if (x != -1) return x;
//
//            //选择finger1到word[i];
//            int ans1 = dfs(dfs, i - 1, word[i], finger2) + len(finger1, word[i]);
//            //选择finger2到word[i]
//            int ans2 = dfs(dfs, i - 1, finger1, word[i]) + len(finger2, word[i]);
//            x = min(ans1, ans2);
//            return x;
//        };
//
//        int ans = INT_MAX;
//        //一定有一个手指指向最后一个元素，枚举另一根手指的位置
//        for (char i = 'A'; i <= 'Z'; i++) {
//            ans = min(ans, dfs(dfs, n - 2, i, word.back()));
//        }
//        return ans;
//    }
//};

//省去一个维度写法（少一根手指）
class Solution {
    unordered_map<char, pair<int, int>> hash_map;
    void Init() {
        char alpha = 'A';
        bool ok = false;
        for (int i = 0; i < 5; i++) {
            for (int j = 0; j < 6; j++) {
                hash_map[alpha++] = { i,j };
                if (alpha > 'Z') {
                    ok = true;
                    break;
                }
            }
            if (ok) break;
        }
    }

    int len(char a, char b) {
        return abs(hash_map[a].first - hash_map[b].first) + abs(hash_map[a].second - hash_map[b].second);
    }
public:
    int minimumDistance(string word) {
        Init();
        int n = word.size();
        //memo[i][j]表示手指1在word[i + 1]的位置，手指2在j的位置，输入word的前缀[0,i]的最小移动距离
        vector<vector<int>> memo(n, vector<int>(26, -1));

        //这里表示一根手指指向word[i + 1],另一根手指指向finger的位置
        auto dfs = [&](auto&& dfs, int i, char finger)->int {
            if (i < 0) return 0;

            auto& x = memo[i][finger - 'A'];
            if (x != -1) return x;

            //选择手指1(word[i + 1])到word[i];
            int ans1 = dfs(dfs, i - 1, finger) + len(word[i + 1], word[i]);
            //选择手指2(finger)到word[i]
            int ans2 = dfs(dfs, i - 1, word[i + 1]) + len(finger, word[i]);
            x = min(ans1, ans2);
            return x;
        };

        int ans = INT_MAX;
        //一定有一个手指指向最后一个元素，枚举另一根手指的位置
        for (char i = 'A'; i <= 'Z'; i++) {
            ans = min(ans, dfs(dfs, n - 2, i));
        }
        return ans;
    }
};

int main() {

	return 0;
}