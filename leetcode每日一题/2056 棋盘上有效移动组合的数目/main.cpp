#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <unordered_map>
using namespace std;

//自己写的，还有待修改，过了200+
//class Solution {
//public:
//    int dx[14] = { 1,2,3,4,5,6,7,-1,-2,-3,-4,-5,-6,-7};
//    int dy[14] = { 1,2,3,4,5,6,7,-1,-2,-3,-4,-5,-6,-7};
//    vector<vector<int>> arr;
//    int ans = 0;
//
//    bool check(vector<int> ret, int dx, int dy) {
//        int count = max(abs(dx), abs(dy));
//        for (int i = 0; i < count; i++) {
//            if (dx > 0) ret[0]++;
//            else if (dx < 0) ret[0]--;
//
//            if (dy > 0) ret[1]++;
//            else if(dy < 0) ret[1]--;
//
//            if (ret[0] >= 1 && ret[0] <= 8 && ret[1] >= 1 && ret[1] <= 8) {
//                for (int i = 0; i < arr.size(); i++) {
//                    if (ret[0] == arr[i][0] && ret[1] == arr[i][1]) {
//                        return false;
//                    }
//                }
//            }
//            else {
//                return false;
//            }
//        }
//        return true;
//    }
//
//    void dfs(int pos, vector<string>& str, vector<vector<int>>& positions) {
//        if (pos == str.size()) {
//            ++ans;
//            return;
//        }
//
//        vector<int> ret(2), tmp;
//        ret[0] = positions[pos][0], ret[1] = positions[pos][1];
//        arr.push_back(ret);
//        dfs(pos + 1, str, positions);
//
//        //回溯
//        arr.pop_back();
//        for (int i = 0; i < 14; i++) {
//            if (str[pos] == "rook" || str[pos] == "queen"){
//                if (check(ret, dx[i], 0)) {
//                    tmp = ret;
//                    tmp[0] += dx[i];
//                    arr.push_back(tmp);
//                    dfs(pos + 1, str, positions);
//
//                    //回溯
//                    arr.pop_back();
//                }
//
//                if (check(ret, 0, dy[i])) {
//                    tmp = ret;
//                    tmp[1] += dy[i];
//                    arr.push_back(tmp);
//                    dfs(pos + 1, str, positions);
//
//                    //回溯
//                    arr.pop_back();
//                }
//            }
//
//            if (str[pos] == "bishop" || str[pos] == "queen") {
//                if (check(ret, dx[i], dy[i])) {
//                    tmp = ret;
//                    tmp[0] += dx[i];
//                    tmp[1] += dy[i];
//                    arr.push_back(tmp);
//                    dfs(pos + 1, str, positions);
//
//                    //回溯
//                    arr.pop_back();
//                }
//
//                if (i <= 6) {
//                    if (check(ret, dx[i], dy[i + 7])) {
//                        tmp = ret;
//                        tmp[0] += dx[i];
//                        tmp[1] += dy[i + 7];
//
//                        arr.push_back(tmp);
//                        dfs(pos + 1, str, positions);
//
//                        //回溯
//                        arr.pop_back();
//                    }
//                }
//                else {
//                    if (check(ret, dx[i], dy[i - 7])) {
//                        tmp = ret;
//                        tmp[0] += dx[i];
//                        tmp[1] += dy[i - 7];
//
//                        arr.push_back(tmp);
//                        dfs(pos + 1, str, positions);
//
//                        //回溯
//                        arr.pop_back();
//                    }
//                }
//            }
//        }
//    }
//
//    int countCombinations(vector<string>& pieces, vector<vector<int>>& positions) {
//        dfs(0, pieces, positions);
//        return ans;
//    }
//};

//灵神题解
struct Move {
    int x0, y0; // 起点
    int dx, dy; // 移动方向
    int step;   // 移动次数
};

class Solution {
    vector<pair<int, int>> DIRS = { {-1, 0}, {1, 0}, {0, -1}, {0, 1}, {1, 1}, {-1, 1}, {-1, -1}, {1, -1} }; // 上下左右 + 斜向
    unordered_map<char, vector<pair<int, int>>> PIECE_DIRS = {
        {'r', {DIRS.begin(), DIRS.begin() + 4}},
        {'b', {DIRS.begin() + 4, DIRS.end()}},
        {'q', DIRS},
    };

    // 计算位于 (x0,y0) 的棋子在 dirs 这些方向上的所有合法移动
    vector<Move> generate_moves(int x0, int y0, vector<pair<int, int>>& dirs) {
        const int SIZE = 8;
        vector<Move> moves = { {x0, y0, 0, 0, 0} }; // 原地不动
        for (auto [dx, dy] : dirs) {
            // 往 d 方向走 1,2,3,... 步
            int x = x0 + dx, y = y0 + dy;
            for (int step = 1; 0 < x && x <= SIZE && 0 < y && y <= SIZE; step++) {
                moves.emplace_back(x0, y0, dx, dy, step);
                x += dx;
                y += dy;
            }
        }
        return moves;
    }

    // 判断两个移动是否合法，即不存在同一时刻两个棋子重叠的情况
    bool is_valid(Move& m1, Move& m2) {
        int x1 = m1.x0, y1 = m1.y0;
        int x2 = m2.x0, y2 = m2.y0;
        for (int i = 0; i < max(m1.step, m2.step); i++) {
            // 每一秒走一步
            if (i < m1.step) {
                x1 += m1.dx;
                y1 += m1.dy;
            }
            if (i < m2.step) {
                x2 += m2.dx;
                y2 += m2.dy;
            }
            if (x1 == x2 && y1 == y2) { // 重叠
                return false;
            }
        }
        return true;
    }

public:
    int countCombinations(vector<string>& pieces, vector<vector<int>>& positions) {
        int n = pieces.size();
        // 预处理所有合法移动
        vector<vector<Move>> all_moves(n);
        for (int i = 0; i < n; i++) {
            all_moves[i] = generate_moves(positions[i][0], positions[i][1], PIECE_DIRS[pieces[i][0]]);
        }

        vector<Move> path(n); // 注意 path 的长度是固定的
        int ans = 0;
        auto dfs = [&](auto& dfs, int i) -> void {
            if (i == n) {
                ans++;
                return;
            }
            // 枚举当前棋子的所有合法移动
            for (Move& move1 : all_moves[i]) {
                // 判断合法移动 move1 是否有效
                bool ok = true;
                for (int j = 0; j < i; j++) {
                    if (!is_valid(move1, path[j])) {
                        ok = false;
                        break;
                    }
                }
                if (ok) {
                    path[i] = move1; // 直接覆盖，无需恢复现场
                    dfs(dfs, i + 1); // 枚举后续棋子的所有合法移动组合
                }
            }
        };
        dfs(dfs, 0);
        return ans;
    }
};

int main() {
    vector<string> pieces = { "bishop","rook" };
    vector<vector<int>> positions = { {8,5},{7,7} };
    cout << Solution().countCombinations(pieces, positions) << "\n";
	return 0;
}