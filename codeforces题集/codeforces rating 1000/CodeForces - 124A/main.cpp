#include <iostream>
#include <cmath>
using namespace std;

//6 2 3
int main() {
    int n = 0, a = 0, b = 0;
    cin >> n >> a >> b;
    cout << min(n - a, b + 1) << endl;;
    return 0;
}