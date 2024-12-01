#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int _n;
    vector<bool> checkCol = vector<bool>(10, false);			//�жϸ����Ƿ��лʺ�
    vector<bool> checkDig1 = vector<bool>(20, false);			//�жϸ��Խ����Ƿ��лʺ�
    vector<bool> checkDig2 = vector<bool>(20, false);			//�ж����Խ����Ƿ��лʺ�
    vector<vector<string>> ret;
    vector<string> path;

    void dfs(int row) {
        if (row == _n) {
            ret.push_back(path);
            return;
        }

        //�ؼ���
        for (int col = 0; col < _n; col++) {
            if (!checkCol[col] && !checkDig1[row + col] && !checkDig2[row - col + _n]) {
                path[row][col] = 'Q';
                checkCol[col] = checkDig1[row + col] = checkDig2[row - col + _n] = true;
                dfs(row + 1);

                //����
                path[row][col] = '.';
                checkCol[col] = checkDig1[row + col] = checkDig2[row - col + _n] = false;
            }
        }
    }

    int totalNQueens(int n) {
        _n = n;
        path.resize(n);
        for (int i = 0; i < n; i++) {
            path[i].append(n, '.');
        }
        dfs(0);
        return ret.size();
    }
};

int main() {

    return 0;
}