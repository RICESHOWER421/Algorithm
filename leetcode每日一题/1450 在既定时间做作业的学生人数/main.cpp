#include <iostream>
#include <vector>
using namespace std;

int busyStudent(vector<int>& startTime, vector<int>& endTime, int queryTime) {
    int ret = 0;
    for (int i = 0; i < startTime.size(); i++) {
        if (queryTime >= startTime[i] && queryTime <= endTime[i]) ++ret;
    }
    return ret;
}

int main() {

    return 0;
}