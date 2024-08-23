#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> flipAndInvertImage(vector<vector<int>>& image) {
	for (int i = 0; i < image.size(); i++)	//·­×ªÍ¼Ïñ
		reverse(image[i].begin(), image[i].end());

	for (int i = 0; i < image.size(); i++)	//·´×ªÍ¼Ïñ
		for (int j = 0; j < image[0].size(); j++)
			image[i][j] = 1 - image[i][j];

	return image;
}

int main() {
	vector<vector<int>> image = { {1,1,0},{1,0,1},{0,0,0} };
	vector<vector<int>> ans = flipAndInvertImage(image);
	for (int i = 0; i < ans.size(); i++) {
		for (int j = 0; j < ans[0].size(); j++) {
			cout << ans[i][j] << " ";
		}
		cout << endl;
	}
	return 0;
}
