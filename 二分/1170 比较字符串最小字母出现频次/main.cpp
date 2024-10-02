#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    int Binary_Search(int num, vector<int>& arr) {
        int left = 0, right = arr.size();
        while (left < right) {
            int mid = (left + right) / 2;
            if (arr[mid] < num) left = mid + 1;
            else right = mid;
        }
        return left;
    }

    vector<int> numSmallerByFrequency(vector<string>& queries, vector<string>& words) {
        vector<int> ans;

        vector<int> words_num;
        for (int i = 0; i < (int)words.size(); i++) {
            char c = words[i][0];
            int ret = 1;
            for (int j = 1; j < (int)words[i].size(); j++) {
                if (words[i][j] < c) {
                    c = words[i][j];
                    ret = 1;
                }
                else if (words[i][j] == c) ++ret;
            }
            words_num.push_back(ret);
        }

        sort(words_num.begin(), words_num.end());
        for (int i = 0; i < (int)queries.size(); i++) {
            char c = queries[i][0];
            int ret = 1;
            for (int j = 1; j < (int)queries[i].size(); j++) {
                if (queries[i][j] < c) {
                    c = queries[i][j];
                    ret = 1;
                }
                else if (queries[i][j] == c) ++ret;
            }
            ans.push_back((int)words.size() - Binary_Search(ret + 1, words_num));
        }
        return ans;
    }
};

int main() {
    vector<string> queries = { "bba","abaaaaaa","aaaaaa","bbabbabaab","aba","aa","baab","bbbbbb","aab","bbabbaabb" };
    vector<string> words = { "aaabbb","aab","babbab","babbbb","b","bbbbbbbbab","a","bbbbbbbbbb","baaabbaab","aa" };
    vector<int> ans = Solution().numSmallerByFrequency(queries, words);
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << " ";
    }
    cout << endl;
	return 0;
}