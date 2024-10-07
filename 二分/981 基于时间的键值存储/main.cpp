#include <iostream>
#include <map>
#include <vector>
using namespace std;

class TimeMap {
public:
    TimeMap() {

    }

    void set(string key, string value, int timestamp) {
        hash_map[key].push_back({timestamp, value});
    }

    string get(string key, int timestamp) {
        int left = 0, right = hash_map[key].size();
        while (left < right) {
            int mid = (left + right) / 2;
            if (hash_map[key][mid].first < timestamp) left = mid + 1;
            else right = mid;
        }
        
        string ans;
        if (left == (int)hash_map[key].size() || hash_map[key][left].first != timestamp) {
            if (left - 1 >= 0) ans = hash_map[key][left - 1].second;
            else ans = "";
        }
        else ans = hash_map[key][left].second;
        return ans;
    }

    map<string, vector<pair<int, string>>> hash_map;
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */

int main() {
    TimeMap tm;
    tm.set("foo", "bar", 1);
    cout << tm.get("foo", 1) << endl;
    cout << tm.get("foo", 3) << endl;
    tm.set("foo", "bar2", 4);
    cout << tm.get("foo", 4) << endl;
    cout << tm.get("foo", 5) << endl;
	return 0;
}