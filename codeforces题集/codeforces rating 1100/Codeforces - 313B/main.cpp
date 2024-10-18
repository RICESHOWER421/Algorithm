#include <iostream>
#include <string>
#include <vector>
using namespace std;

void Test(){
    string s;
    cin >> s;

    int n = s.size();
    vector<int> dp(n + 1);
    for(int i = 1; i <= n; i++){
        dp[i] = dp[i - 1] + (s[i] == s[i - 1]);
    }

    int k = 0;
    cin >> k;
    while(k--){
        int l = 0, r = 0;
        cin >> l >> r;
        cout << dp[r - 1] - dp[l - 1] << "\n";
    }
}

int main(){
    Test();
    return 0;
}