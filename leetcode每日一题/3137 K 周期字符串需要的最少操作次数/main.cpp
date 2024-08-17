#include <iostream>
#include <map>
using namespace std;

int minimumOperationsToMakeKPeriodic(string word, int k) {
	map<string, int> hash_map;
	int max_num = -1;
	for (int i = 0; i < word.size(); i += k) {
		hash_map[word.substr(i, k)]++;
		if (hash_map[word.substr(i, k)] > max_num) max_num = hash_map[word.substr(i, k)];
	}
	return word.size() / k - max_num;
}
int main() {

	return 0;
}