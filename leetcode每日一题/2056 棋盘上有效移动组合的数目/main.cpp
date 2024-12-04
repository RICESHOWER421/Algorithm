#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <unordered_map>
using namespace std;

//�Լ�д�ģ����д��޸ģ�����200+
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
//        //����
//        arr.pop_back();
//        for (int i = 0; i < 14; i++) {
//            if (str[pos] == "rook" || str[pos] == "queen"){
//                if (check(ret, dx[i], 0)) {
//                    tmp = ret;
//                    tmp[0] += dx[i];
//                    arr.push_back(tmp);
//                    dfs(pos + 1, str, positions);
//
//                    //����
//                    arr.pop_back();
//                }
//
//                if (check(ret, 0, dy[i])) {
//                    tmp = ret;
//                    tmp[1] += dy[i];
//                    arr.push_back(tmp);
//                    dfs(pos + 1, str, positions);
//
//                    //����
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
//                    //����
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
//                        //����
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
//                        //����
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

//�������
struct Move {
    int x0, y0; // ���
    int dx, dy; // �ƶ�����
    int step;   // �ƶ�����
};

class Solution {
    vector<pair<int, int>> DIRS = { {-1, 0}, {1, 0}, {0, -1}, {0, 1}, {1, 1}, {-1, 1}, {-1, -1}, {1, -1} }; // �������� + б��
    unordered_map<char, vector<pair<int, int>>> PIECE_DIRS = {
        {'r', {DIRS.begin(), DIRS.begin() + 4}},
        {'b', {DIRS.begin() + 4, DIRS.end()}},
        {'q', DIRS},
    };

    // ����λ�� (x0,y0) �������� dirs ��Щ�����ϵ����кϷ��ƶ�
    vector<Move> generate_moves(int x0, int y0, vector<pair<int, int>>& dirs) {
        const int SIZE = 8;
        vector<Move> moves = { {x0, y0, 0, 0, 0} }; // ԭ�ز���
        for (auto [dx, dy] : dirs) {
            // �� d ������ 1,2,3,... ��
            int x = x0 + dx, y = y0 + dy;
            for (int step = 1; 0 < x && x <= SIZE && 0 < y && y <= SIZE; step++) {
                moves.emplace_back(x0, y0, dx, dy, step);
                x += dx;
                y += dy;
            }
        }
        return moves;
    }

    // �ж������ƶ��Ƿ�Ϸ�����������ͬһʱ�����������ص������
    bool is_valid(Move& m1, Move& m2) {
        int x1 = m1.x0, y1 = m1.y0;
        int x2 = m2.x0, y2 = m2.y0;
        for (int i = 0; i < max(m1.step, m2.step); i++) {
            // ÿһ����һ��
            if (i < m1.step) {
                x1 += m1.dx;
                y1 += m1.dy;
            }
            if (i < m2.step) {
                x2 += m2.dx;
                y2 += m2.dy;
            }
            if (x1 == x2 && y1 == y2) { // �ص�
                return false;
            }
        }
        return true;
    }

public:
    int countCombinations(vector<string>& pieces, vector<vector<int>>& positions) {
        int n = pieces.size();
        // Ԥ�������кϷ��ƶ�
        vector<vector<Move>> all_moves(n);
        for (int i = 0; i < n; i++) {
            all_moves[i] = generate_moves(positions[i][0], positions[i][1], PIECE_DIRS[pieces[i][0]]);
        }

        vector<Move> path(n); // ע�� path �ĳ����ǹ̶���
        int ans = 0;
        auto dfs = [&](auto& dfs, int i) -> void {
            if (i == n) {
                ans++;
                return;
            }
            // ö�ٵ�ǰ���ӵ����кϷ��ƶ�
            for (Move& move1 : all_moves[i]) {
                // �жϺϷ��ƶ� move1 �Ƿ���Ч
                bool ok = true;
                for (int j = 0; j < i; j++) {
                    if (!is_valid(move1, path[j])) {
                        ok = false;
                        break;
                    }
                }
                if (ok) {
                    path[i] = move1; // ֱ�Ӹ��ǣ�����ָ��ֳ�
                    dfs(dfs, i + 1); // ö�ٺ������ӵ����кϷ��ƶ����
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