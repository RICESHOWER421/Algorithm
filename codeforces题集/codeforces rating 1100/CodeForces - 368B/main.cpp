#include <iostream>
#include <vector>
#include <map>
using namespace std;

void Test(){
    int n = 0, m = 0;
    cin >> n >> m;
    vector<int> nums(n);
    for (int i = 0; i < n; i++){
        cin >> nums[i];
    }

    vector<int> vis(n);
    map<int, int> hash_map;
    for (int i = n - 1; i >= 0; i--){
        if(!hash_map.count(nums[i])){
            hash_map[nums[i]] = 1;
        }
        vis[i] = hash_map.size();
    }

    while(m--){
        int num = 0;
        cin >> num;
        cout << vis[num - 1] << "\n";
    }
}

int main(){
    Test();
    return 0;
}