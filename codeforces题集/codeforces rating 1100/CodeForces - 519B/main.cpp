#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

void Test(){
    int n = 0;
    cin >> n;

    map<int, int> hash_map;
    vector<int> nums;
    for (int i = 0; i < n; i++){
        int num = 0;
        cin >> num;
        if(!hash_map.count(num)){
            nums.push_back(num);
        }
        hash_map[num]++;
    }

    map<int, int> ret;
    for (int i = 0; i < n - 1; i++){
        int num = 0;
        cin >> num;
        ret[num]++;
    }

    for (int i = 0; i < (int)nums.size(); i++){
        if(hash_map[nums[i]] != ret[nums[i]]){
            cout << nums[i] << "\n";
        }
    }

    hash_map = ret;
    ret.clear();
    for (int i = 0; i < n - 2; i++){
        int num = 0;
        cin >> num;
        ret[num]++;
    }

    for (int i = 0; i < (int)nums.size(); i++){
        if(hash_map[nums[i]] != ret[nums[i]]){
            cout << nums[i] << "\n";
        }
    }
}
int main(){
    Test();
    return 0;
}