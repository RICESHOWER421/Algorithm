#include <iostream>
#include <vector>
#include <string>
using namespace std;

int _n;
vector<bool> checkCol(10);			//�жϸ����Ƿ��лʺ�
vector<bool> checkDig1(20);			//�жϸ��Խ����Ƿ��лʺ�
vector<bool> checkDig2(20);			//�ж����Խ����Ƿ��лʺ�
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

vector<vector<string>> solveNQueens(int n) {
	_n = n;
	path.resize(n);
	for (int i = 0; i < n; i++) {
		path[i].append(n, '.');
	}
	dfs(0);
	return ret;
}

int main() {
	int n = 5;
	vector<vector<string>> ret = solveNQueens(n);
	for (int i = 0; i < ret.size(); i++) {
		for (int j = 0; j < ret[i].size(); j++) {
			cout << ret[i][j] << endl;
		}
		cout << endl;
	}
	return 0;
}