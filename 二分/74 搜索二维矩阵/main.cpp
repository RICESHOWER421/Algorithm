#include <iostream>
#include <vector>
using namespace std;

//���ݰ���̫�٣�ֱ�ӱ���ö��
//bool searchMatrix(vector<vector<int>>& matrix, int target) {
//    for (int i = 0; i < matrix.size(); i++)
//        for (int j = 0; j < matrix[i].size(); j++)
//            if (matrix[i][j] == target) return true;
//    return false;
//}


//ʹ�ö��ֲ��ҵķ�ʽ�������
bool searchMatrix(vector<vector<int>>& matrix, int target) {
    vector<pair<int, int>> p;
    for (int i = 0; i < matrix.size(); i++)
        p.push_back({ matrix[i][0],matrix[i][matrix[i].size() - 1] });

    int left = 0, right = p.size() - 1;
    while (left < right) {
        int mid = left + (right - left) / 2;
        if (target > p[mid].second) left = mid + 1;
        else if (target < p[mid].first) right = mid;
        else {
            int temp = mid;
            left = 0, right = matrix[temp].size() - 1;
            while (left < right) {
                mid = left + (right - left) / 2;
                if (target > matrix[temp][mid]) left = mid + 1;
                else if (target < matrix[temp][mid]) right = mid;
                else return true;
            }
            if (target == matrix[temp][right]) return true;
            else return false;
        }
    }
    if (target >= p[right].first && target <= p[right].second) {  //�������Ҫ�ҵ���������p[right(left)]������
        int temp = right;
        int left = 0, right = matrix[temp].size() - 1;
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (target > matrix[temp][mid]) left = mid + 1;
            else if (target < matrix[temp][mid]) right = mid;
            else return true;
        }
        if (matrix[temp][right] == target) return true;     //�������Ҫ�ҵ���������matrix[temp][right(left)]��
        else return false;
    }
    return false;
}

int main() {
    vector<vector<int>> matrix = { {1,3} };
    int target = 3;
    cout << searchMatrix(matrix, target) << endl;
    return 0;
}