#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> imageSmoother(vector<vector<int>>& img) {
    vector<vector<int>> ans(img.size(), vector<int>(img[0].size()));
    for (int i = 0; i < img.size(); i++) {
        for (int j = 0; j < img[i].size(); j++) {
            int sum = 0;
            int ret = 0;
            if (i - 1 >= 0 && j - 1 >= 0) {
                sum += img[i - 1][j - 1];
                ++ret;
            }
            if (i - 1 >= 0) {
                sum += img[i - 1][j];
                ++ret;
            }
            if (i - 1 >= 0 && j + 1 < img[i].size()) {
                sum += img[i - 1][j + 1];
                ++ret;
            }
            if (j - 1 >= 0) {
                sum += img[i][j - 1];
                ++ret;
            }
            sum += img[i][j];
            ++ret;
            if (j + 1 < img[i].size()) {
                sum += img[i][j + 1];
                ++ret;
            }
            if (i + 1 < img.size() && j - 1 >= 0) {
                sum += img[i + 1][j - 1];
                ++ret;
            }
            if (i + 1 < img.size()) {
                sum += img[i + 1][j];
                ++ret;
            }
            if (i + 1 < img.size() && j + 1 < img[i].size()) {
                sum += img[i + 1][j + 1];
                ++ret;
            }
            ans[i][j] = sum / ret;
        }
    }
    return ans;
}
int main() {

	return 0;
}