#include <iostream>
#include <vector>
#include <map>
using namespace std;

class Employee {
public:
    int id;
    int importance;
    vector<int> subordinates;
};

map<int, pair<int, int>> hash_map;
int dfs(int id, vector<Employee*>& employees) {
    int ans = hash_map[id].second;
    for (int i = 0; i < (employees[hash_map[id].first]->subordinates).size(); i++) {
        ans = ans + dfs(employees[hash_map[id].first]->subordinates[i], employees);
    }
    return ans;
}

int getImportance(vector<Employee*> employees, int id) {
    for (int i = 0; i < employees.size(); i++) {
        hash_map[employees[i]->id] = { i, employees[i]->importance };
    }

    int ans = dfs(id, employees);
    return ans;
}

int main() {

	return 0;
}